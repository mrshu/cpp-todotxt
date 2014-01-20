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
    ASSERT_STR_EQ(task.raw_todo, "this is an important task");
    PASS();
}

SUITE(suite) {
    RUN_TEST(simple_task_parse);
}

GREATEST_MAIN_DEFS();

int main(int argc, char** argv)
{
    GREATEST_MAIN_BEGIN();
    RUN_SUITE(suite);
    GREATEST_MAIN_END();
}
