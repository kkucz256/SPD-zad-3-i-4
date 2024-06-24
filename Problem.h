#ifndef SPD_ZAD_3_I_4_PROBLEM_H
#define SPD_ZAD_3_I_4_PROBLEM_H
#include "Task.h"
#include "Result.h"

using namespace std;

class Problem {
private:
    vector<Task> instance;

public:
    Problem(vector<Task> tasks);
    void print_instance_order();
    int calculate_cmax(vector<Task> tasks);
    int fast_calculate_cmax(vector<Task>& tasks, int newPosition,  Task& newTask);
    vector<Task> get_tasks();
    Result bruteforce();
    Result NEH();
    Result FNEH();
    Result Johnson_algorithm();

    Result simulated_annealing(double initial_temperature, double cooling_rate, int iterations, int seed);
};


#endif //SPD_ZAD_3_I_4_PROBLEM_H
