#ifndef _SIMPLETEST_H_
#define _SIMPLETEST_H_

#include <assert.h>

typedef struct {
  char *name;
  void (*main)();
} test_entry_t;

#define TEST(name)				\
  void run_test_##name()

#define TEST_DECLARE(name)			\
  void run_test_##name();

#define TEST_LIST_START                 \
  char *FILENAME = __FILE__;		\
  test_entry_t TESTS[] = {

#define TEST_ENTRY(name)			\
  {#name, &run_test_##name},

#define TEST_LIST_END		  \
  {0, 0},			  \
    };

extern test_entry_t TESTS[];
extern char *FILENAME;

int run_all_tests(int argc, const char *argv[]);

#endif
