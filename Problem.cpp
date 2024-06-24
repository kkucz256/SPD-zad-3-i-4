#include <algorithm>
#include <iostream>
#include <cmath>
#include "Problem.h"
#include "Result.h"

using namespace std;

Problem::Problem(vector<Task> tasks) {
    this->instance = tasks;

}

void Problem::print_instance_order() {
    for(Task task: instance){
        cout << task.get_index() << " ";
    }
    cout << endl;
}

int Problem::calculate_cmax(vector<Task> tasks) {
    int m = tasks[0].get_size();

    vector<int> end_time(m, 0);

    for (Task task : tasks) {
        end_time[0] += task.get_time_at_index(0);
        
        for (int j = 1; j < m; j++) {
            end_time[j] = max(end_time[j], end_time[j - 1]) + task.get_time_at_index(j);
        }
    }
    
    return end_time[m - 1];
}

int Problem::fast_calculate_cmax(vector<Task>& tasks, int newPosition, Task& newTask) {
    int numJobs = tasks.size() + 1;
    int numMachines = newTask.get_size();
    vector<int> completionTimes(numMachines, 0);
    vector<int> previousCompletionTimes(numMachines, 0);

    for (int i = 0; i <= tasks.size(); ++i) {
        if (i == newPosition) {
            for (int j = 0; j < numMachines; ++j) {
                if (j == 0) {
                    completionTimes[j] = previousCompletionTimes[j] + newTask.get_time_at_index(j);
                } else {
                    completionTimes[j] = max(completionTimes[j-1], previousCompletionTimes[j]) + newTask.get_time_at_index(j);
                }
            }
        } else {
            for (int j = 0; j < numMachines; ++j) {
                if (j == 0) {
                    completionTimes[j] = previousCompletionTimes[j] + tasks[i < newPosition ? i : i-1].get_time_at_index(j);
                } else {
                    completionTimes[j] = max(completionTimes[j-1], previousCompletionTimes[j]) + tasks[i < newPosition ? i : i-1].get_time_at_index(j);
                }
            }
            previousCompletionTimes = completionTimes;
        }
    }
    return completionTimes[numMachines-1];
}

bool compare_M1( Task& t1, Task& t2) {
    return t1.get_time_at_index(0) < t2.get_time_at_index(0);
}

bool compare_M2( Task& t1, Task& t2) {
    return t1.get_time_at_index(1) < t2.get_time_at_index(1);
}


Result Problem::bruteforce() {
    int min_cmax = 100000;
    std::vector<Task> best;
    do {
        //print_instance_order();
        int cmax = calculate_cmax(instance);
        if (cmax < min_cmax) {
            min_cmax = cmax;
            best = instance;
        }
    } while (next_permutation(instance.begin(), instance.end(), [](Task& task1, Task& task2) {
        return task1.get_index() < task2.get_index();
    }));
    return {best, min_cmax};
}

Result Problem::NEH() {
    sort(instance.begin(), instance.end(), [](Task& task1, Task& task2){
        return task1.sum_times() > task2.sum_times();
    });

    std::vector<Task> temp_instance;

    for (Task& task : instance) {
        int best_position = -1;
        int temp_cmax = 10000;

        // Temporary vector to hold best permutation found
        std::vector<Task> best_permutation;

        for (int i = 0; i <= temp_instance.size(); ++i) {
            // Insert task at position i in temporary instance
            temp_instance.insert(temp_instance.begin() + i, task);

            // Calculate cmax for current permutation
            int cmax = calculate_cmax(temp_instance);

            // Check if current permutation is the best found so far
            if (cmax < temp_cmax) {
                temp_cmax = cmax;
                best_position = i;
                best_permutation = temp_instance; // Update best permutation
            }

            // Remove task from temporary instance for next iteration
            temp_instance.erase(temp_instance.begin() + i);
        }

        // Update temporary instance with the best position for current task
        temp_instance = best_permutation;
    }

    int min_cmax = calculate_cmax(temp_instance);

    return {temp_instance, min_cmax};
}

vector<Task> Problem::get_tasks() {
    return instance;
}

Result Problem::simulated_annealing(double initial_temperature, double cooling_rate, int iterations, int seed) {
    vector<Task> best_instance = instance;
    int best_cmax = calculate_cmax(instance);
    double temperature = initial_temperature;
    srand(seed);
    for (int iter = 0; iter < iterations; ++iter) {
        // Generate neighbor using SWAP
        vector<Task> neighbor_instance = instance;
        int i = rand() % neighbor_instance.size();
        int j = rand() % neighbor_instance.size();
        swap(neighbor_instance[i], neighbor_instance[j]);

        int neighbor_cmax = calculate_cmax(neighbor_instance);

        // Acceptance probability
        double delta = neighbor_cmax - best_cmax;
        double acceptance_probability = exp(-delta / temperature);

        // Decide whether to accept the neighbor solution
        if (delta < 0 || (rand() / (double)RAND_MAX) < acceptance_probability) {
            instance = neighbor_instance;
            best_cmax = neighbor_cmax;
            best_instance = neighbor_instance;
        }

        // Cool down the temperature
        temperature *= cooling_rate;
    }

    return {best_instance, best_cmax};
}



Result Problem::FNEH(){
    std::sort(instance.begin(), instance.end(), [](Task& task1, Task& task2){
        return task1.sum_times() > task2.sum_times();
    });

    std::vector<Task> temp_instance;

    for (Task task : instance) {
        int best_position = -1;
        int temp_cmax = INT_MAX;

        for (int i = 0; i <= temp_instance.size(); ++i) {
            int cmax = fast_calculate_cmax(temp_instance, i, task);
            if (cmax < temp_cmax) {
                temp_cmax = cmax;
                best_position = i;
            }
        }
        temp_instance.insert(temp_instance.begin() + best_position, task);
    }

    int min_cmax = calculate_cmax(temp_instance);

    return {temp_instance, min_cmax};
}

// TABU sort

 Result Problem::Johnson_algorithm(){
    vector<Task> M1,M2;

    for (int i =0; i < instance.size(); ++i){
        Task task = instance[i];

        if (task.get_time_at_index(0) <= task.get_time_at_index(1)){
            M1.push_back(task);
        }
        else {
            M2.push_back(task);
        }
    }

    sort(M1.begin(), M1.end(), compare_M1);

    sort(M2.begin(), M2.end(), compare_M2);

    vector<Task> result;

     result.insert(result.end(), M1.begin(), M1.end());
     result.insert(result.end(), M2.begin(), M2.end());

    int min_cmax = calculate_cmax(result);
    return{result, min_cmax};
 }


