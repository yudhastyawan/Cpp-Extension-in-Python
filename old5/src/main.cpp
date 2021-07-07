#include "mycalc.h"
#include <iostream>

int main() {
    Mynumber* a = new Mynumber(10.);
    Mynumber* b = new Mynumber(20.);
    Mynumber* c = new Mynumber();
    c = mysum(a,b);
    std::cout << c->getter() << std::endl;    
    delete a;
    delete b;
    delete c;
    return 0;
}