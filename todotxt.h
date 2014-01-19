#ifndef TODOTXT_H
#define TODOTXT_H

#include <cstdlib>
#include <cstring>

typedef struct TodotxtTask {
    int id;
    char priority;
    bool finished;
    char* raw_todo;
} TodotxtTask;

typedef TodotxtTask* TodotxtTasks;

#endif
