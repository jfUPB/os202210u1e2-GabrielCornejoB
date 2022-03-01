//Notificador o publicador
#ifndef SUBJECT_H
#define SUBJECT_H
#define LEN_OBSERVERS 10
#include "observer.h"

typedef void (*addObserver)(struct subject *, observer *);
typedef void (*removeObserver)(struct subject *, observer *);
typedef void (*notifyObservers)(struct subject *);

typedef struct{
    int state;
    observer *observers[LEN_OBSERVERS];
    addObserver add;
    removeObserver remove;
    notifyObservers notify;
}subject;

subject *subject_new();         
void subject_ctor(subject *);
void subject_destroy(subject *);

#endif