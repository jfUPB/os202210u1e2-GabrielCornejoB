#include <stdio.h>
#include <stdlib.h>
#include "dt.h"

static void _cambiarEstrategia(Dt* this, Estrategia est){
    printf("El tecnico %s ordeno la estrategia #%d",this->nombre, est);
    this->estrategia = est;
    this->subject->notifyObservers(this->subject);
}
static Estrategia _getStrategy(Dt *this){
    return this->estrategia;
}
static void _addObserver(Dt *this, Observer *observer){
    return this->subject->addObserver(this->subject, observer);
}
static void _removeObserver(Dt *this, Observer *observer){
    return this->subject->removeObserver(this->subject, observer);
}
Dt *dt_new(char *name){
    Dt *this = (Dt *)malloc(sizeof(*this));
    this->nombre = name;
    this->cambiarEstrategia = _cambiarEstrategia;
    this->getStrategy = _getStrategy;
    this->addObserver = _addObserver;
    this->removeObserver = _removeObserver;
}