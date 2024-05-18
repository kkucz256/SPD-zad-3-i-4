#include <iostream>
#include "Task.h"
#include "Problem.h"


int main(){
    Task task1({4,2,7});
    Task task2({1,5,3});
    Task task3({2,1,4});
    Task task4({5,6,3});
    Task task5({7,2,8});
    Task task6({3,2,4});
    double initial_temp = 10000;
    double cooling_rate = 0.85;
    int stop = 100;
    int seed = 10;

    Problem problem({task1,task2,task3,task4,task5,task6});
    Problem problem1 = problem;
    Problem problem2 = problem;
    Result result = problem.bruteforce();
    cout<< "Bruteforce results: " << endl;
    result.print_results();

    Result result1 = problem1.NEH();
    cout<< "NEH results: " << endl;
    result1.print_results();

    Result result2 = problem2.simulated_annealing(initial_temp, cooling_rate, stop, seed);
    cout << "Results: " << endl;
    result2.print_results();


    return 0;

};

