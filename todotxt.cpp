#include "todotxt.h"

TodotxtTask todotxt_parse_task(const char* todo, int id) {
    TodotxtTask task;

    task.id = id;
    task.raw_todo = strdup(todo);

    if (strlen(todo) > 3) {
        if (todo[0] == 'x' && todo[1] == ' ' && todo[2] != ' ') {
            task.finished = true;
            todo += 2;
        } else {
            task.finished = false;
        }
    }

    if (strlen(todo) > 4) {
        if (isupper(todo[1]) &&
            (todo[0] == '(' && todo[2] == ')' && todo[3] == ' ')) {
            task.priority = todo[1];
            todo += 4;
        } else {
            task.priority = '^';
        }
    }

    int todo_len = strlen(todo) + 1;
    task.todo = new char[todo_len + 1];
    memcpy(task.todo, todo, todo_len);

    return task;
}

void todotxt_free_task(TodotxtTask *task) {
    delete task->raw_todo;
    delete task->todo;
    delete task;
}
