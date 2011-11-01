#ifndef _SIMPLETEST_H
#define _SIMPLETEST_H

#include <assert.h>

typedef struct {
    char *name;
    int (*main)();
} test_entry_t;

#define TEST(name)                      \
    int run_test_##name(void)

#define TEST_LIST_START                 \
    char *FILENAME = __FILE__;          \
    test_entry_t TESTS[] = {

#define TEST_ENTRY(name)                \
    {#name, &run_test_##name},

#define TEST_LIST_END                   \
    {NULL, NULL},                       \
    };

int run_all_tests(void);
int run_test(test_entry_t *test);

#endif