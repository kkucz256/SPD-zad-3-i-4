#include <iostream>
#include "Task.h"

int Task::taskcount = 0;

Task::Task(vector<int> times) {
    this->operation_times = times;
    taskcount++;
    index = taskcount;
}

int Task::get_time_at_index(int machineIndex) {
    return operation_times[machineIndex];
}

void Task::print_task() {
    string text = "Task no." + to_string(index)+ " Times: [ ";
    for(int operation_time : operation_times){
        text += to_string(operation_time) + " ";
    }
    text+= "]";
    cout << text << endl;
}

int Task::get_size() {
    return operation_times.size();
}

int Task::get_index(){
    return index;
}

int Task::sum_times() {
    int sum = 0;
    for(int time: operation_times){
        sum+=time;
    }
    return sum;
}
