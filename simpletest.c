#include <stdio.h>
#include "simpletest.h"

extern test_entry_t TESTS[];
extern char *FILENAME;

int run_all_tests() {
    test_entry_t *test;
    int count = 0;

    printf("\n%s\n", FILENAME);
    for(test = (test_entry_t*)&TESTS; test->name; test++)  {
        run_test(test);
        count++;
    }
    printf("\nOK: %d assertion%s\n", count, count > 1 ? "s" : "");
    
    return 0;
}

int run_test(test_entry_t *test) {
    if (test->main() == 0) {
        printf("✔ %s\n", test->name);
    }
}