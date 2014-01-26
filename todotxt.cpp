#include "todotxt.h"

TodotxtTask todotxt_parse_task(const char* todo, int id) {
    TodotxtTask task;

    task.id = id;
    task.finished = false;
    task.raw_todo = strdup(todo);

    if (strlen(todo) > 2) {
        if (isupper(todo[1]) && (todo[0] == '(' && todo[2] == ')')) {
            task.priority = todo[1];
        }
    }

    return task;
}
