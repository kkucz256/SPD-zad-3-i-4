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

    for (Task task : instance) {
        int best_position = -1;
        int temp_cmax = 10000;

        for (int i = 0; i <= temp_instance.size(); ++i) {
            //Inserting tasks on every possible place in temporal instance
            temp_instance.insert(temp_instance.begin() + i, task);
            int cmax = calculate_cmax(temp_instance);
            if (cmax < temp_cmax) {
                temp_cmax = cmax;
                best_position = i;
            }
            //Task printing below:
            /*
            for (Task task : temp_instance) {
                std::cout << task.get_index() << " ";
            }
            cout << endl;
            */
            temp_instance.erase(temp_instance.begin() + i);
        }
        //Updating temporal instance with the best position for current task
        temp_instance.insert(temp_instance.begin() + best_position, task);
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

