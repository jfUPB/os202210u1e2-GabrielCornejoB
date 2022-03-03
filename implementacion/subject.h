//Notificador o publicador
#ifndef SUBJECT_H
#define SUBJECT_H
#define LEN_OBSERVERS 10
#include "observer.h"

typedef struct _subject{
    int state;
    void (*destroySu)(struct _subject *);
    void *impl;
    Observer *observers[LEN_OBSERVERS];
    void (*addObserver)(struct _subject *,  Observer *);        //(Subject, Observer)
    void (*removeObserver)(struct _subject *, Observer *);      //(Subject, Observer)
    void (*notifyObservers)(struct _subject *);
    
}Subject;

Subject *subject_new(void *, int);              //impl, state

#endif