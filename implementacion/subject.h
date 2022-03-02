//Notificador o publicador
#ifndef SUBJECT_H
#define SUBJECT_H
#define LEN_OBSERVERS 10
#include "observer.h"

typedef struct{
    void *impl;
    int state;
    Observer *observers[LEN_OBSERVERS];
    void (*addObserver)(struct Subject *, Observer *);
    void (*removeObserver)(struct Subject *, Observer *);
    void (*notifyObservers)(struct Subject *);
    
}Subject;

Subject *subject_new(void *, int);              //impl, state
void subject_destroy(Subject *);

#endif