#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int id;
} Object;

Object * new(const char *name, int id) {
    Object *obj;
    obj = malloc(sizeof(Object));
    strcpy(obj->name, name);
    obj->id = id;
    return obj;
}

equals(Object *obj1, Object *obj2) {
    return strcmp(obj1->name, obj2->name) == 0 &&
        obj1->id == obj2->id;
}