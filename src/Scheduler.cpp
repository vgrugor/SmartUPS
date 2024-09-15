#include "Scheduler.h"

Scheduler::Scheduler() {}
    void Scheduler::scheduleTask(Task *task) {
    _tasks.push_back(task);
}

void Scheduler::cancelTask(Task *task) {
    _tasks.erase(std::remove(_tasks.begin(), _tasks.end(), task), _tasks.end());
    delete task; // Освобождаем память
}

void Scheduler::update() {
    for (auto it = _tasks.begin(); it != _tasks.end(); ) {
        if ((*it)->isDue()) {
            (*it)->execute();
            delete *it;
            it = _tasks.erase(it);
        } else {
            ++it;
        }
    }
}
