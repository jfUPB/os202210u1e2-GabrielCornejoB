//Notificador o publicador
#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"

typedef void (*addObserver)(void*);
typedef void (*removeObserver)(void*);
typedef void (*notifyObservers)(void*);

typedef struct{
    int state;
    observer observer[10];
    addObserver add;
    removeObserver remove;
    notifyObservers notify;
}subject;

subject *subject_new();         
void subject_ctor(subject *);
void subject_destroy(subject *);

#endif