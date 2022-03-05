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
static void _update(Observer *this,void *subject){
    printf("\nDEBUG: Observer: update()\n");
    this->impl_update(this->impl, subject);
}
//Observer constructor
Observer *observer_new(void *impl, void (*impl_update)(void *, void *)){
    char *s1 = "DEBUG: Observer: observer_new()";
    printf("%-40s", s1);
    Observer *this = malloc(sizeof(*this));
    this->destroyOb = _destroyOb;
    this->update = _update;
    this->impl = impl;
    this->impl_update = (void (*)(void *, void *)) impl_update;
    return this;
}