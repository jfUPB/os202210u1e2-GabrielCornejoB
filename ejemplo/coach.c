#include <stdio.h>
#include <stdlib.h>
#include "coach.h"

static void _giveOrder(Coach *this){
    //printf("Dt: El tecnico %s va a cambiar la estrategia\n",this->nombre);
    this->event = GIVE_ORDER;
    this->subject->notifyObservers(this->subject);
}
static void _destroy(Coach *this){
    this->subject->destroySu(this->subject);
    if(NULL != this){
        free(this);
        this = NULL;
    }
}
static CoachEvent _getEvent(Coach *this){
    return this->event;
}
static void _addObserver(Coach *this, Observer *observer){
    printf("Coach: AddObserver()\n");
    this->subject->addObserver(this->subject, observer);
}
static void _removeObserver(Coach *this, Observer *observer){
    this->subject->removeObserver(this->subject, observer);
}
Coach *coach_new(char *coachName){
    Coach *this = (Coach *)malloc(sizeof(*this));
    this->name = coachName;
    this->destroy = _destroy;
    this->getEvent = _getEvent;
    this->giveOrder = _giveOrder;
    this->subject = subject_new(this, 1);
    this->addObserver = _addObserver;
    this->removeObserver = _removeObserver;
    return this;
}