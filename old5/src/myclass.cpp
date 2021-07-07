#include "myclass.h"

void Mynumber::setter(double i){
    this->num = i;
}

double Mynumber::getter() {
    return this->num;
}

Mynumber::Mynumber(double i) {
    this->num = i;
}

Mynumber::Mynumber(){
    this->num = 0;
}