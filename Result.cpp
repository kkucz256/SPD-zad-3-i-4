#include "Result.h"
#include <iostream>
Result::Result(vector<Task> instance, int cmax) {
    this->tasks = instance;
    this->cmax = cmax;
}

void Result::print_results() {
    string ids = "";
    for(Task task: tasks){
        ids += to_string(task.get_index()) + " ";
        task.print_task();
    }
    std::cout <<"Cmax for this instance: " + to_string(cmax)+ "\nOrder of tasks: " + ids << endl << endl;
}
