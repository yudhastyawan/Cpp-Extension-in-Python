#include "cwrapper.h"
#include <stdio.h>

int main(){
    Mynumber *a = new_Mynumber(), *b = new_Mynumber(), *c = new_Mynumber();
    double i = 10., j = 20.;
    Mynumber_setter(a,i);
    Mynumber_setter(b,j);
    c = c_mysum(a,b);
    printf("%f",Mynumber_getter(c));
    return 0;
}