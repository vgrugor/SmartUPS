#ifndef TASK_H
    #define TASK_H

    class Task {
        public:
            virtual void execute() = 0;
            virtual bool isDue() = 0;
            virtual ~Task() {}
    };

#endif // TASK_H
