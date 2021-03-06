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

    if (strlen(todo) > 11) {
        if (todo[10] == ' ') {
            char* time = new char[11];
            memcpy(time, todo, 10);
            time[10] = '\0';

            task.create_date = todotxt_build_time(time);
            delete time;

            if (task.create_date !=  -1) {
                todo += 11;
            }

        } else {
            task.create_date = -1;
        }
    }

    int todo_len = strlen(todo) + 1;
    task.todo = new char[todo_len + 1];
    memcpy(task.todo, todo, todo_len);

    return task;
}

time_t todotxt_build_time(char* time) {
    struct tm Tm;
    memset(&Tm, 0, sizeof(Tm));

    if (sscanf(time, "%d-%d-%d", &Tm.tm_year, &Tm.tm_mon, &Tm.tm_mday) == 3) {
        Tm.tm_year -= 1900;
        Tm.tm_mon -= 1;

        return mktime(&Tm);
    } else {
        return -1;
    }
}

void todotxt_free_task(TodotxtTask *task) {
    delete task->raw_todo;
    delete task->todo;
    delete task;
}
