#include <stdio.h>
#include <stdlib.h>
#include "coach.h"

char *printStrat(int num){
    if(num == 0){ return "ULTRA OFFENSIVE"; }
    else if(num == 1){ return "OFFENSIVE"; }
    else if(num == 2){ return "BALANCED"; }
    else if(num == 3){ return "DEFENSIVE"; }
    else if(num == 4){ return "ULTRA DEFFENSIVE"; }
    else{ return "a"; }
}
static void _giveOrder(Coach *this, int newStrat){
    printf("DEBUG: Coach: giveOrder()\n");
    printf("\n\tCoach '%s' is changing strat to: %s\n\n",this->name, printStrat(newStrat));
    this->event = GIVE_ORDER;
    this->new_strat = newStrat;
    this->subject->notifyObservers(this->subject);
}
static void _destroy(Coach *this){
    printf("DEBUG: Coach: destroy()\n");
    this->subject->destroySu(this->subject);
    if(NULL != this){
        free(this);
        this = NULL;
    }
}
static CoachEvent _getEvent(Coach *this){
    printf("DEBUG: Coach: CoachEvent()\n");
    return this->event;
}
static void _addObserver(Coach *this, Observer *observer){
    printf("DEBUG: Coach: AddObserver()\n");
    this->subject->addObserver(this->subject, observer);
}
static void _removeObserver(Coach *this, Observer *observer){
    printf("DEBUG: Coach: RemoveObserver()\n");
    this->subject->removeObserver(this->subject, observer);
} 
Coach *coach_new(char *coachName){
    printf("DEBUG: Coach: coach_new()\n");
    Coach *this = (Coach *)malloc(sizeof(*this));
    this->name = coachName;
    this->destroy = _destroy;
    this->getEvent = _getEvent;
    this->giveOrder = _giveOrder;
    this->subject = subject_new(this, 1);
    this->addObserver = _addObserver;
    this->removeObserver = _removeObserver;
    printf("\n\tCoach '%s' created\n\n", coachName);
    return this;
}