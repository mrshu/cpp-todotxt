#include <stdio.h>
#include "todotxt.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "greatest.h"

SUITE(suite);

TEST simple_task_parse(void) {
    TodotxtTask task = todotxt_parse_task("this is an important task", 1);
    ASSERT_EQ(task.id, 1);
    ASSERT_EQ(task.finished, false);
    ASSERT_STR_EQ(task.raw_todo, "this is an important task");
    ASSERT_STR_EQ(task.todo, "this is an important task");
    PASS();
}

TEST simple_finished_task_parse(void) {
    TodotxtTask task = todotxt_parse_task("x this is an important task", 1);
    ASSERT_EQ(task.id, 1);
    ASSERT_EQ(task.finished, true);
    ASSERT_STR_EQ(task.raw_todo, "x this is an important task");
    ASSERT_STR_EQ(task.todo, "this is an important task");
    PASS();
}

TEST simple_task_parse_with_priority(void) {
    TodotxtTask task = todotxt_parse_task("(A) this is a very important task", 1);
    ASSERT_EQ(task.id, 1);
    ASSERT_EQ(task.finished, false);
    ASSERT_STR_EQ(task.raw_todo, "(A) this is a very important task");
    ASSERT_STR_EQ(task.todo, "this is a very important task");
    ASSERT_EQ(task.priority, 'A');
    PASS();
}

TEST simple_task_parse_with_wrong_priority(void) {
    TodotxtTask task = todotxt_parse_task("(a) this is a very important task", 1);
    ASSERT_EQ(task.id, 1);
    ASSERT_EQ(task.finished, false);
    ASSERT_STR_EQ(task.raw_todo, "(a) this is a very important task");
    ASSERT_STR_EQ(task.todo, "(a) this is a very important task");
    ASSERT_FALSE(task.priority == 'a');
    PASS();
}

TEST simple_task_parse_without_priority(void) {
    TodotxtTask task = todotxt_parse_task("(a)task without a priority", 1);
    ASSERT_EQ(task.id, 1);
    ASSERT_EQ(task.finished, false);
    ASSERT_STR_EQ(task.raw_todo, "(a)task without a priority");
    ASSERT_STR_EQ(task.todo, "(a)task without a priority");
    ASSERT_EQ(task.priority, '^');
    PASS();
}

SUITE(suite) {
    RUN_TEST(simple_task_parse);
    RUN_TEST(simple_finished_task_parse);
    RUN_TEST(simple_task_parse_with_priority);
    RUN_TEST(simple_task_parse_with_wrong_priority);
    RUN_TEST(simple_task_parse_without_priority);
}

GREATEST_MAIN_DEFS();

int main(int argc, char** argv)
{
    GREATEST_MAIN_BEGIN();
    RUN_SUITE(suite);
    GREATEST_MAIN_END();
}
