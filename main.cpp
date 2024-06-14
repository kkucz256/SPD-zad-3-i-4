#include <iostream>
#include <chrono>

#include "Task.h"
#include "Problem.h"

using namespace chrono;

int main(){
    Task task1({4,2,7});
    Task task2({1,5,3});
    Task task3({2,1,4});
    Task task4({5,6,3});
    Task task5({7,2,8});
    Task task6({9,4,4});
    Task task7({3,2,7});
    Task task8({7,5,3});
   /*ask task9({1,6,7});
    Task task10({5,4,9});
    Task task11({6,9,2});
    Task task12({8,4,5});
*/

    double initial_temp = 10000;
    double cooling_rate = 0.85;
    int stop = 100;
    int seed = 10;

    Problem problem({task1,task2,task3,task4,task5,task6, task7, task8/*,task9, task10, task11, task12*/});
    Problem problem1 = problem;
    Problem problem2 = problem;

    steady_clock::time_point startBF = steady_clock::now();
    Result result = problem.bruteforce();
    steady_clock::time_point endBF = steady_clock::now();
    duration<double, milli> elapsedBF = endBF - startBF;
    cout<< "Bruteforce results: " << endl;
    cout << "\nBruteforce time: " << elapsedBF.count() << " ms" << endl;
    result.print_results();

    steady_clock::time_point startNEH = steady_clock::now();
    Result result1 = problem1.NEH();
    steady_clock::time_point endNEH = steady_clock::now();
    duration<double, milli> elapsedNEH = endBF - startNEH;
    cout<< "NEH results: " << endl;
    cout << "\nNEH time: " << elapsedBF.count() << " ms" << endl;
    result1.print_results();

    steady_clock::time_point startSA = steady_clock::now();
    Result result2 = problem2.simulated_annealing(initial_temp, cooling_rate, stop, seed);
    steady_clock::time_point endSA = steady_clock::now();
    duration<double, milli> elapsedSA = endSA - startSA;
    cout << "Results of simulated annealing: " << endl;
    cout << "\nsimulated annealing time: " << elapsedSA.count() << " ms" << endl;
    result2.print_results();

    steady_clock::time_point startFNEH = steady_clock::now();
    Result result3 = problem1.FNEH();
    steady_clock::time_point endFNEH = steady_clock::now();
    duration<double, milli> elapsedFNEH = endFNEH - startFNEH;
    cout<< "FNEH results: " << endl;
    cout << "\nFNEH time: " << elapsedFNEH.count() << " ms" << endl;
    result1.print_results();

    steady_clock::time_point startJA = steady_clock::now();
    Result result4 = problem1.Johnson_algorithm();
    steady_clock::time_point endJA = steady_clock::now();
    duration<double, milli> elapsedJA = endJA - startJA;
    cout<< "johnson_algorithm results: " << endl;
    cout << "\nJohnson algoritm time: " << elapsedJA.count() << " ms" << endl;
    result1.print_results();


    return 0;

};

