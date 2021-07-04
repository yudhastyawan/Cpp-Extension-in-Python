#include "MyWrapper.h"
#include <stdio.h>

int main() {
    MyClass* c = newMyClass();
    int b = 12;
    MyClass_int_set(c,b);
    printf("Your data: %d\n",MyClass_int_get(c));
    deleteMyClass(c);
    return 0;
}