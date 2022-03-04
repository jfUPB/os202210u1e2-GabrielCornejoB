#ifndef PLAYER_H_
#define PLAYER_H_
#include "../implementacion/subject.h"
#include "../implementacion/observer.h"
#include "coach.h"

typedef enum _location{
    UP = 0,
    MID = 1,
    BACK = 2
}Location;

typedef struct _player{
    char *name;
    Location location;
    Location (*getLocation)(struct _player *);
    void (*enterField)(struct _player *, Coach*);
    void (*destroy)(struct _player *);
    Observer * observer;
}Player;

Player *player_new(char *, int);
#endif