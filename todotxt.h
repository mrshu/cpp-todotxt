#ifndef TODOTXT_H
#define TODOTXT_H

#include <stdlib.h>

struct TodotxtTask {
    int id;
    char priority;
    bool finished;
    char* raw_todo;
};

typedef *TodotxtTask TodotxtTasks;

TodotxtTask parse_task(const char* todo, int id) {
    TodotxtTask task = new TodotxtTask;

    task.id = id;
    task.raw_todo = strdup(todo);

    return task;
}

#endif
