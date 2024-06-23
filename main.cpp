#include <iostream>
#include <chrono>

#include "Task.h"
#include "Problem.h"

using namespace chrono;

int main() {
/*
    Task task1({4, 2, 7});
    Task task2({1, 5, 3});
    Task task3({2, 1, 4});
    Task task4({5, 6, 3});
    Task task5({7, 2, 8});
    Task task6({9, 4, 4});
    Task task7({3, 2, 7});
    Task task8({7, 5, 3});
    Task task9({1, 6, 7});
    Task task10({5, 4, 9});
    Task task11({6, 9, 2});
    Task task12({8, 4, 5});
*/
    /*
    Task task1({4, 2, 7, 1, 3, 5, 6, 8, 9, 10});
    Task task2({1, 5, 3, 7, 4, 6, 2, 8, 9, 10});
    Task task3({2, 1, 4, 5, 3, 7, 6, 8, 9, 10});
    Task task4({5, 6, 3, 2, 1, 4, 7, 8, 9, 10});
    Task task5({7, 2, 8, 4, 3, 6, 1, 5, 9, 10});
    Task task6({9, 4, 4, 2, 1, 7, 3, 5, 6, 8});
    Task task7({3, 2, 7, 6, 5, 1, 4, 8, 9, 10});
    Task task8({7, 5, 3, 4, 6, 2, 1, 8, 9, 10});
    Task task9({1, 6, 7, 2, 3, 4, 5, 8, 9, 10});
    Task task10({5, 4, 9, 7, 3, 6, 1, 8, 2, 10});
    Task task11({6, 9, 2, 1, 3, 7, 4, 8, 5, 10});
    Task task12({1, 3, 5, 7, 2, 3, 9, 7, 4, 6});
     */
    /*
    Task task0({2,10,3,9,4,5,7,6,9,8,5,3,5,3,6,7,9,4,8,1,5,3,4,9,3,8,8,3,5,8});
    Task task1({1,3,9,10,6,7,10,8,4,5,4,9,10,4,6,8,1,4,3,2,4,4,7,2,1,10,2,5,5,1});
    Task task2({9,10,4,10,1,9,3,2,5,4,7,9,3,7,3,9,9,5,2,5,9,4,8,4,6,3,5,1,9,8});
    Task task3({10,8,5,6,6,9,7,8,2,10,4,9,8,10,3,1,6,1,3,8,7,4,7,5,10,8,6,9,9,6});
    Task task4({10,9,9,3,8,6,8,4,3,4,2,3,8,9,4,7,10,10,2,6,3,3,10,8,7,7,10,5,2,10});
    Task task5({6,10,10,9,2,9,10,6,9,8,8,4,6,7,2,9,7,3,9,9,9,10,10,1,8,6,6,7,2,5});
    Task task6({8,5,8,8,4,9,7,4,3,5,3,3,1,6,5,8,8,9,5,8,4,4,2,3,2,3,6,7,9,10});
    Task task7({9,6,7,1,1,9,5,6,10,5,10,7,10,8,3,8,5,1,10,1,5,8,7,8,8,3,1,5,1,8});
    Task task8({6,2,7,1,7,3,2,2,2,10,3,2,3,8,9,4,9,7,2,6,2,7,4,4,10,2,10,3,8,5});
    Task task9({4,5,2,6,8,1,1,5,8,4,4,6,6,10,8,8,10,3,5,4,2,1,2,4,4,9,2,6,4,4});
    Task task10({4,4,2,3,9,9,5,9,10,5,2,5,7,5,4,2,2,6,8,10,2,7,6,10,8,10,9,8,9,10});
    Task task11({6,9,8,3,5,2,2,4,10,3,4,5,2,8,7,10,1,10,4,1,8,8,2,5,6,4,9,10,2,1});
     */

    double initial_temp = 10000;
    double cooling_rate = 0.997;
    int stop = 500;
    int seed = 10;



    Task task0({1,6,10,5,9,1,4,6,7,7});
    Task task1({9,5,9,3,3,5,5,4,9,4});
    Task task2({4,9,4,1,5,5,7,7,2,2});
    Task task3({8,2,3,1,5,4,10,1,9,6});
    Task task4({3,10,1,6,1,5,7,9,9,8});
    Task task5({1,9,4,7,3,3,9,6,3,10});
    Task task6({6,9,5,6,3,2,8,1,5,10});
    Task task7({2,5,4,10,10,8,1,4,10,4});
    Task task8({1,9,1,6,5,10,2,9,10,10});
    Task task9({6,4,4,10,8,8,7,3,8,5});
    Task task10({6,2,10,5,6,6,7,5,7,8});
    Task task11({9,10,7,5,4,3,3,1,6,3});
    Task task12({5,8,3,10,2,5,10,8,4,10});
    Task task13({6,2,5,9,6,7,9,9,6,1});
    Task task14({3,8,6,9,4,4,10,5,6,1});
    Task task15({2,3,7,2,6,3,3,2,6,5});
    Task task16({2,9,5,6,1,7,10,9,8,10});
    Task task17({9,8,2,2,10,8,8,3,7,2});
    Task task18({2,1,8,8,5,6,4,8,1,4});
    Task task19({4,9,8,4,5,8,9,10,5,9});
    Task task20({8,2,6,4,3,3,1,1,7,1});
    Task task21({7,8,1,4,9,3,2,7,9,9});
    Task task22({1,7,9,2,1,5,7,3,4,10});
    Task task23({9,3,3,6,1,4,4,1,2,3});
    Task task24({4,6,4,2,3,2,7,7,4,3});
    Task task25({5,3,4,1,4,3,10,1,1,1});
    Task task26({4,4,10,1,8,4,7,5,8,7});
    Task task27({10,5,5,8,4,8,9,1,2,1});
    Task task28({7,1,4,4,5,4,6,1,6,4});
    Task task29({10,3,9,10,9,9,2,9,5,4});
    Task task30({6,8,5,9,1,8,5,9,1,5});
    Task task31({3,9,7,6,3,7,8,2,3,2});
    Task task32({6,7,6,7,8,4,1,5,7,8});
    Task task33({6,5,8,6,2,4,6,2,9,3});
    Task task34({10,3,9,4,7,6,10,7,1,10});
    Task task35({5,6,2,3,6,3,5,1,8,3});
    Task task36({5,4,9,2,5,10,10,6,4,6});
    Task task37({3,10,9,3,6,5,10,9,10,3});
    Task task38({2,1,3,5,6,8,4,3,9,4});
    Task task39({2,9,2,9,4,4,4,2,1,10});
    Task task40({5,5,1,4,2,8,4,4,10,6});
    Task task41({5,2,10,2,5,10,3,8,3,2});
    Task task42({2,10,10,9,5,2,6,10,5,4});
    Task task43({3,2,4,8,3,10,4,8,3,2});
    Task task44({5,8,6,3,4,2,7,1,6,2});
    Task task45({10,6,10,7,8,3,6,7,10,10});
    Task task46({9,8,10,6,8,5,9,7,9,9});
    Task task47({5,4,7,5,10,9,10,4,3,1});
    Task task48({4,10,4,1,10,8,10,5,9,9});
    Task task49({6,3,6,1,9,3,3,1,8,3});
    Problem problem({task0, task1, task2, task3, task4, task5, task6, task7, task8, task9, task10, task11, task12, task13, task14, task15, task16, task17, task18, task19, task20, task21, task22, task23, task24, task25, task26, task27, task28, task29, task30, task31, task32, task33, task34, task35, task36, task37, task38, task39, task40, task41, task42, task43, task44, task45, task46, task47, task48, task49});

    Problem problem1 = problem;
    Problem problem2 = problem;
    Problem problem3 = problem;
    Problem problem4 = problem;

    /*
    clock_t startBF = clock();
    Result result = problem.bruteforce();
    clock_t endBF = clock();
    double elapsedBF = double(endBF - startBF) / CLOCKS_PER_SEC * 1000;
    cout << "Bruteforce results: " << endl;
    cout << "\nBruteforce time: " << elapsedBF << " ms" << endl;
    result.print_results();
     */

    clock_t startNEH = clock();
    Result result1 = problem1.NEH();
    clock_t endNEH = clock();
    double elapsedNEH = double(endNEH - startNEH) / CLOCKS_PER_SEC * 1000;
    cout << "NEH results: " << endl;
    cout << "\nNEH time: " << elapsedNEH << " ms" << endl;
    result1.print_results();

    clock_t startFNEH = clock();
    Result result3 = problem3.FNEH();
    clock_t endFNEH = clock();
    double elapsedFNEH = double(endFNEH - startFNEH) / CLOCKS_PER_SEC * 1000;
    cout << "FNEH results: " << endl;
    cout << "\nFNEH time: " << elapsedFNEH << " ms" << endl;
    result3.print_results();

    clock_t startJA = clock();
    Result result4 = problem4.Johnson_algorithm();
    clock_t endJA = clock();
    double elapsedJA = double(endJA - startJA) / CLOCKS_PER_SEC * 1000;
    cout << "johnson_algorithm results: " << endl;
    cout << "\nJohnson algorithm time: " << elapsedJA << " ms" << endl;
    result4.print_results();

    clock_t startSA = clock();
    Result result2 = problem2.simulated_annealing(initial_temp, cooling_rate, stop, seed);
    clock_t endSA = clock();
    double elapsedSA = double(endSA - startSA) / CLOCKS_PER_SEC * 1000;
    cout << "Results of simulated annealing: " << endl;
    cout << "\nsimulated annealing time: " << elapsedSA << " ms" << endl;
    result2.print_results();

    return 0;

};

