#include "todotxt.h"

TodotxtTask todotxt_parse_task(const char* todo, int id) {
    TodotxtTask task;

    task.id = id;
    task.finished = false;
    task.raw_todo = strdup(todo);

    //int clean_todo_start = 0;
    if (strlen(todo) > 2) {
        if (isupper(todo[1]) &&
            (todo[0] == '(' && todo[2] == ')' && todo[3] == ' ')) {
            task.priority = todo[1];
        } else {
            task.priority = '^';
        }
    }

    //task.todo = new char[strlen(todo) - clean_todo_start];


    return task;
}
