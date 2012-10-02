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

#define assertEquals(a, b)			\
  assert(a == b)

#define assertStrEquals(a, b)			\
  assert(strcmp(a, b) == 0)

#define assertNULL(a)				\
  assert(a == NULL)

extern test_entry_t TESTS[];
extern char *FILENAME;

int run_all_tests(int argc, const char *argv[]);

#endif
