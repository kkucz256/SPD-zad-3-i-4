#ifndef SPD_ZAD_3_I_4_TASK_H
#define SPD_ZAD_3_I_4_TASK_H
#include <vector>
using namespace std;

class Task {
private:
    std::vector<int> operation_times;
    static int taskcount;
    int index;

public:
    Task(vector<int> times);
    int get_time_at_index(int machineIndex);
    void print_task();
    int get_size();
    int get_index();
    int sum_times();
};


#endif //SPD_ZAD_3_I_4_TASK_H
