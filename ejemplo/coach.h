#ifndef COACH_H_
#define COACH_H_
#include "../implementacion/subject.h"
#include "../implementacion/observer.h"

typedef enum _coachEvent{
    GIVE_ORDER
}CoachEvent;

typedef struct _coach{
    char *name;
    void (*destroy)(struct _coach*);

    CoachEvent event;
    CoachEvent (*getEvent)(struct _coach *);

    void (*giveOrder)(struct _coach *, int);    

    int new_strat; 

    Subject * subject;
    void (*addObserver)(struct _coach *, Observer*);
    void (*removeObserver)(struct _coach *, Observer*);
}Coach;

Coach *coach_new(char *);

#endif