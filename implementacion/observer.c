#include <stdlib.h>
#include <stdio.h>
#include "observer.h"

static void _update(Observer *this, int state, Subject *subject){
    this->impl_update(this->impl, state, subject);
}

Observer *observer_new(void *impl, void (*impl_update)(void *, int, void *)){
    Observer *this = (Observer*)malloc(sizeof(Observer));
    this->update = _update;
    this->impl = impl;
    this->impl_update = (void (*)(void *, int, void *))impl_update;
    return this;
}

void observer_destroy(Observer* this){
    free(this);
    this = NULL;
}