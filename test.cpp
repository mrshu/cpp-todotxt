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
    PASS();
}

TEST simple_task_parse_with_priority(void) {
    TodotxtTask task = todotxt_parse_task("(A) this is a very important task", 1);
    ASSERT_EQ(task.id, 1);
    ASSERT_EQ(task.finished, false);
    ASSERT_STR_EQ(task.raw_todo, "(A) this is a very important task");
    ASSERT_EQ(task.priority, 'A');
    PASS();
}

TEST simple_task_parse_with_wrong_priority(void) {
    TodotxtTask task = todotxt_parse_task("(a) this is a very important task", 1);
    ASSERT_EQ(task.id, 1);
    ASSERT_EQ(task.finished, false);
    ASSERT_STR_EQ(task.raw_todo, "(a) this is a very important task");
    ASSERT_FALSE(task.priority == 'a');
    PASS();
}

SUITE(suite) {
    RUN_TEST(simple_task_parse);
    RUN_TEST(simple_task_parse_with_priority);
    RUN_TEST(simple_task_parse_with_wrong_priority);
}

GREATEST_MAIN_DEFS();

int main(int argc, char** argv)
{
    GREATEST_MAIN_BEGIN();
    RUN_SUITE(suite);
    GREATEST_MAIN_END();
}
