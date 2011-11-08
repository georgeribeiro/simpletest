#include "simpletest.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static int run_process(void (*main)()) 
{
  int status;
  pid_t pid, w;
  
  pid = fork();
  if (pid == -1) {
    perror("fork()");
    return -1;
  }
  else if (pid == 0) {
    main();
    exit(0);
  }
  w = waitpid(pid, &status, 0);
  if (w == -1) {
    return -1;
  }
  return status;
}

static int run(int verbose, int abort_failed)
{
  test_entry_t *test;
  int count = 0, passed = 0, failed = 0;
  time_t start, end;
  int success;

  if(verbose)
    fprintf(stdout, "\n%s\n", FILENAME);
  
  start = time(NULL);
  for(test = (test_entry_t*)&TESTS; test->name; test++)  {
    if (abort_failed) {
      test->main();
      if (verbose)
        fprintf(stdout, "✔ %s\n", test->name);
    } else {
      success = run_process(test->main);
      if (success == 0) {
        passed++;
      } else {
        failed++;
      }
      if (verbose)
        fprintf(stdout, "%s %s\n", success == 0 ? "✔" : "✖", test->name);
    }
    count++;
  }
  end = time(NULL);
  
  if (failed == 0)
    fprintf(stdout, "\nOK: %d assertion%s (%.0fs)\n", count, count > 1 ? "s" : "", difftime(end, start));
  else
    fprintf(stdout, "\nFAILURE: %d/%d assertion%s failed (%.0fs)\n", failed, count, count > 1 ? "s" : "", difftime(end, start));
  
  return 0;
}

int run_all_tests(int argc, const char *argv[]) {
  int i;
  int verbose = 1, abort_failed = 0;
  
  if (argc == 1) {
    return run(verbose, abort_failed);
  }
  for(i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-n") == 0 ||strcmp(argv[i], "--no-verbose") == 0) {
      verbose = 0;
    }
    else if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--abort-failed") == 0) {
      abort_failed = 1;
    }
    else {
      fprintf(stderr, "Unknown option: %s\n", argv[i]);
      return 1;
    }
  }
  return run(verbose, abort_failed);
}
