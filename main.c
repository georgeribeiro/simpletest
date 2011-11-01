#include <string.h>
#include "simpletest.h"
#include "object.h"

TEST(number_equals) {
    assert(1 == 1);
    return 0;
}

TEST(string_equals) {
    assert(strcmp("1", "1") == 0);
    return 0;
}

TEST(float_equals) {
    assert(1.0 == 1.0);
    return 0;
}

TEST(string_not_equals) {
    assert(strcmp("1", "2") == -1);
    return 0;
}

TEST(object_equals) {
    Object *obj1 = new("obj", 1);
    Object *obj2 = new("obj", 1);
    assert(equals(obj1, obj2));
    return 0;
}

TEST(object_not_equals) {
    Object *obj1 = new("obj1", 1);
    Object *obj2 = new("obj2", 1);
    assert(!equals(obj1, obj2));
    return 0;
}

TEST_LIST_START
    TEST_ENTRY(number_equals)
    TEST_ENTRY(string_equals)
    TEST_ENTRY(float_equals)
    TEST_ENTRY(string_not_equals)
    TEST_ENTRY(object_equals)
    TEST_ENTRY(object_not_equals)
TEST_LIST_END

int main(int argc, char const *argv[])
{
    return run_all_tests();
}