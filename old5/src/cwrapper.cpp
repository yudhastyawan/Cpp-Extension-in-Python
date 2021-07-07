#include "myclass.h"
#include "mycalc.h"
#include "cwrapper.h"

Mynumber* new_Mynumber(){
    return new Mynumber();
}

void delete_Mynumber(Mynumber* v){
    delete v;
}

void Mynumber_setter(Mynumber* v, double i){
    v->setter(i);
}

double Mynumber_getter(Mynumber* v){
    return v->getter();
}

Mynumber* c_mysum(Mynumber* a, Mynumber* b){
    return mysum(a,b); 
}