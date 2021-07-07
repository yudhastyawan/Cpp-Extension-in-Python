#ifndef __WRAPPER_H
#define __WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Mynumber Mynumber;

Mynumber* new_Mynumber();

void delete_Mynumber(Mynumber* v);

void Mynumber_setter(Mynumber* v, double i);

double Mynumber_getter(Mynumber* v);

Mynumber* c_mysum(Mynumber* a, Mynumber* b);

#ifdef __cplusplus
}
#endif

#endif