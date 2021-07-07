#include "myclass.h"
#include "mycalc.h"

Mynumber* mysum(Mynumber* a, Mynumber* b){
    Mynumber* res = new Mynumber();
    res->setter(a->getter()+b->getter());
    return res;
}