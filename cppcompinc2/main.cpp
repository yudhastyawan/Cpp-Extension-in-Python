#include "myclass.h"
#include <stdio.h>

int main() {
    // Mynum c(10);
    // printf("%d\n", c.getter());
    Mynum* c = new Mynum(10);
    printf("%d\n", c->getter());
    delete(c);
    return 0;
}