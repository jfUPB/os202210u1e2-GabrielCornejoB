//SUBJECT EXAMPLE
#ifndef COACH_H_
#define COACH_H_
#include "../implementacion/subject.h"
#include "../implementacion/observer.h"

//Enum that triggers event
typedef enum _coachEvent{
    GIVE_ORDER
}CoachEvent;
//Enum for Coach's strategies
typedef enum _strategy{
    ULTRA_OFFENSIVE = 0,
    OFFENSIVE = 1,
    BALANCED = 2,
    DEFENSIVE = 3,
    ULTRA_DEFENSIVE = 4
}Strategy;

typedef struct _coach{
    char *name;
    void (*destroy)(struct _coach*);                        //(this)

    CoachEvent event;
    CoachEvent (*getEvent)(struct _coach *);                //(this)

    void (*giveOrder)(struct _coach *, int);                //(this, strategy)

    int new_strat; 

    Subject * subject;
    void (*addObserver)(struct _coach *, Observer*);        //(this, Observer)
    void (*removeObserver)(struct _coach *, Observer*);     //(this, Player)
}Coach;

//Coach constructor
Coach *coach_new(char *);                                   //(coachName)

#endif