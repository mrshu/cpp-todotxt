#include "todotxt.h"

TodotxtTask todotxt_parse_task(const char* todo, int id) {
    TodotxtTask task;

    task.id = id;
    task.raw_todo = strdup(todo);

    int clean_todo_start = 0;

    if (strlen(todo) > 3) {
        if (todo[0] == 'x' && todo[1] == ' ' && todo[2] != ' ') {
            task.finished = true;
            clean_todo_start += 2;
        } else {
            task.finished = false;
        }
    }

    if (strlen(todo) > 4) {
        if (isupper(todo[1]) &&
            (todo[0] == '(' && todo[2] == ')' && todo[3] == ' ')) {
            task.priority = todo[1];
            clean_todo_start += 4;
        } else {
            task.priority = '^';
        }
    }

    int todo_len = strlen(todo) - clean_todo_start;
    task.todo = new char[todo_len + 1];
    memcpy(task.todo, (todo + clean_todo_start), todo_len);

    return task;
}
