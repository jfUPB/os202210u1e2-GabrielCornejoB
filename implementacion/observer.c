#include <stdlib.h>
#include <stdio.h>
#include "observer.h"

void _destroyOb(Observer* this){
    free(this);
    this = NULL;
}

static void _update(Observer *this, int state, void *subject){
    printf("Observer: update\n");
    this->impl_update(this->impl, state, subject);
}

Observer *observer_new(void *impl, void (*impl_update)(void *, int, void *)){
    Observer *this = (Observer*)malloc(sizeof(*this));
    this->destroyOb = _destroyOb;
    this->update = _update;
    this->impl = impl;
    this->impl_update = (void (*)(void *, int, void *)) impl_update;
    return this;
}