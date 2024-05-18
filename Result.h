#ifndef SPD_ZAD_3_I_4_RESULT_H
#define SPD_ZAD_3_I_4_RESULT_H


#include "Task.h"

class Result {
private:
    vector<Task> tasks;
    int cmax;
public:
    Result(vector<Task> instance, int cmax);
    void print_results();
};


#endif //SPD_ZAD_3_I_4_RESULT_H
