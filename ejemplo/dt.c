#include <stdio.h>
#include <stdlib.h>
#include "dt.h"

static void _darOrden(Dt *this){
    printf("Dt: El tecnico %s va a cambiar la estrategia\n",this->nombre);
    this->event = DAR_ORDEN;
    this->subject->notifyObservers(this->subject);
}
static void _destroy(Dt *this){
    this->subject->destroySu(this->subject);
    if(NULL != this){
        free(this);
        this = NULL;
    }
}
static DtEvent _getEvent(Dt *this){
    return this->event;
}
static void _addObserver(Dt *this, Observer *observer){
    printf("Dt: AddObserver\n");
    this->subject->addObserver(this->subject, observer);
}
static void _removeObserver(Dt *this, Observer *observer){
    this->subject->removeObserver(this->subject, observer);
}
Dt *dt_new(char *name){
    Dt *this = (Dt *)malloc(sizeof(*this));
    this->nombre = name;
    this->destroy = _destroy;
    this->getEvent = _getEvent;
    this->darOrden = _darOrden;
    this->subject = subject_new(this, 1);
    this->addObserver = _addObserver;
    this->removeObserver = _removeObserver;
    return this;
}