#include <stdio.h>
#include <stdlib.h>
#include "coach.h"
#include <time.h>

//Functions that takes enum number and turns it to its String representation
char *printStrat(int num){
    if(num == 0){ return "ULTRA OFFENSIVE"; }
    else if(num == 1){ return "OFFENSIVE"; }
    else if(num == 2){ return "BALANCED"; }
    else if(num == 3){ return "DEFENSIVE"; }
    else if(num == 4){ return "ULTRA DEFFENSIVE"; }
    else{ return "a"; }
}
//Coach changes strat
static void _giveOrder(Coach *this, int newStrat){
    if(newStrat < 0 || newStrat > 4){
        printf("DEBUG: Coach: giveOrder()\n");
        printf("DEBUG: Invalid strat, choosing random strat\n");
        int random;
        srand(time(0));
        random = rand() % 5;
        printf("DEBUG: Random strat is: %d", random);
        this->new_strat = random;
        printf("\t\t\tCoach '%s' is changing strat to: %s\n\n",this->name, printStrat(this->new_strat));
    }
    else{
        this->new_strat = newStrat;
        char *s1 = "DEBUG: Coach: giveOrder()";
        printf("%-40s\tCoach '%s' is changing strat to: %s\n\n", s1,this->name, printStrat(this->new_strat));
    }
    this->event = GIVE_ORDER;
    this->subject->notifyObservers(this->subject);
}
//Destroy Coach
static void _destroy(Coach *this){
    printf("DEBUG: Coach: destroy()\n");
    this->subject->destroySu(this->subject);
    if(NULL != this){
        free(this);
        this = NULL;
    }
}
//Returns coach Event
static CoachEvent _getEvent(Coach *this){
    printf("DEBUG: Coach: CoachEvent()\n");
    return this->event;
}
//Adds Observer to list
static void _addObserver(Coach *this, Observer *observer){
    printf("DEBUG: Coach: AddObserver()\n");
    this->subject->addObserver(this->subject, observer);
}
//Removes Observer from list
static void _removeObserver(Coach *this, Observer *observer){
    printf("DEBUG: Coach: RemoveObserver()\n");
    this->subject->removeObserver(this->subject, observer);
} 
//Coach constructor
Coach *coach_new(char *coachName){
    printf("DEBUG: Coach: coach_new()\n");
    Coach *this = malloc(sizeof(*this));
    this->name = coachName;
    this->destroy = _destroy;
    this->getEvent = _getEvent;
    this->giveOrder = _giveOrder;
    this->subject = subject_new(this);
    this->addObserver = _addObserver;
    this->removeObserver = _removeObserver;
    printf("\tCoach '%s' created\n\n", coachName);
    return this;
}