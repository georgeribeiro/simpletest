#include "simpletest.h"
#include <stdio.h>
#include <time.h>

int run_all_tests() {
    test_entry_t *test;
    int count = 0;

    printf("\n%s\n", FILENAME);
    time_t start, end;

    start = time(NULL);
    for(test = (test_entry_t*)&TESTS; test->name; test++)  {
        run_test(test);
        count++;
    }
    end = time(NULL);

    printf("\nOK: %d assertion%s (%.0fs)\n", count, count > 1 ? "s" : "", difftime(end, start));
    
    return 0;
}

int run_test(test_entry_t *test) {
    if (test->main() == 0) {
        printf("✔ %s\n", test->name);
    }
}