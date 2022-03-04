#include <stdlib.h>
#include <stdio.h>
#include "observer.h"

//Desroy Observer
void _destroyOb(Observer* this){
    printf("DEBUG: Observer: destroy()\n");
    free(this);
    this = NULL;
}
//Update Observer
static void _update(Observer *this, int state, void *subject){
    printf("DEBUG: Observer: update()\n");
    this->impl_update(this->impl, state, subject);
}
//Observer constructor
Observer *observer_new(void *impl, void (*impl_update)(void *, int, void *)){
    printf("DEBUG: Observer: observer_new()\n");
    Observer *this = (Observer*)malloc(sizeof(*this));
    this->destroyOb = _destroyOb;
    this->update = _update;
    this->impl = impl;
    this->impl_update = (void (*)(void *, int, void *)) impl_update;
    return this;
}