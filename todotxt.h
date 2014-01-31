#ifndef TODOTXT_H
#define TODOTXT_H

#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>

typedef struct TodotxtTask {
    int id;
    char priority;
    bool finished;
    char* raw_todo;
    char* todo;
    time_t create_date;
    time_t finish_date;
} TodotxtTask;

typedef TodotxtTask* TodotxtTasks;

TodotxtTask todotxt_parse_task(const char* todo, int id);
void todotxt_free_task(TodotxtTask *task);
#endif
