#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include <algorithm>
#include "Task.h"

class Scheduler {
    public:
        Scheduler();
        void scheduleTask(Task *task);
        void cancelTask(Task *task);
        void update();
    private:
        std::vector<Task*> _tasks;
};

#endif // SCHEDULER_H
