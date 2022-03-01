#include <stdlib.h>
#include <stdio.h>
#include "observer.h"

static void _update(observer *this, subject *subject){
    if(this->var == subject->state){
        printf("Subject notificó a observer\n");
    }
}

observer *observer_new(){
    return (observer*)malloc(sizeof(observer));
}
void observer_ctor(observer* this){
    this->var = 2;
    this->update = _update;
}
void observer_destroy(observer* this){
    free(this);
}