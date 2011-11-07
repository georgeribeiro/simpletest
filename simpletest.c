#include "simpletest.h"
#include <time.h>
#include <string.h>
#include <stdio.h>

int run(int verbose) {
  test_entry_t *test;
  int count = 0;
  time_t start, end;
  
  if(verbose)
    fprintf(stdout, "\n%s\n", FILENAME);
  
  start = time(NULL);
  for(test = (test_entry_t*)&TESTS; test->name; test++)  {
    test->main();
    if (verbose)
      fprintf(stdout, "✔ %s\n", test->name);
    count++;
  }
  end = time(NULL);
  
  fprintf(stdout, "\nOK: %d assertion%s (%.0fs)\n", count, count > 1 ? "s" : "", difftime(end, start));
  
  return 0;
}

int run_all_tests(int argc, const char *argv[]) {
  int i;
  
  if (argc == 1) {
    return run(1);
  }
  for(i = 1; i < argc; i++) {
    if (strcmp(argv[i], "--no-verbose") == 0) {
      return run(0);
    }
    else {
      fprintf(stderr, "Unknown option: %s\n", argv[i]);
      return 1;
    }
  }
}
