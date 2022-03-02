//Notificador o publicador
#ifndef SUBJECT_H
#define SUBJECT_H
#define LEN_OBSERVERS 10
#include "observer.h"

typedef struct _subject{
    void *impl;
    int state;
    Observer * observers[LEN_OBSERVERS];
    void (*addObserver)(struct _subject *, Observer *);
    void (*removeObserver)(struct _subject *, Observer *);
    void (*notifyObservers)(struct _subject *);
    
}Subject;

Subject *subject_new(void *, int);              //impl, state
void subject_destroy(Subject *);

#endif