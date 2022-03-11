//OBSERVER EXAMPLE
#ifndef PLAYER_H_
#define PLAYER_H_
#include "../implementacion/subject.h"
#include "../implementacion/observer.h"
#include "coach.h"

//ENUM FOR ACTUAL LOCATION FOR PLAYER
typedef enum _location{
    UP = 0,
    MID = 1,
    BACK = 2
}Location;
//ENUM FOR PLAYER'S ROLE
typedef enum _role{
    STRIKER = 0,
    MIDFIELDER = 1,
    DEFENDER = 2
}Role;

typedef struct _player{
    char *name;
    Location location;
    Location (*getLocation)(struct _player *);                  //(this)
    Role role;
    Role (*getRole)(struct _player *);                          //(this)
    void (*enterField)(struct _player *, Coach*);               //(this, Coach)
    void (*destroy)(struct _player *);                          //(this)
    Observer * observer;
}Player;

//Player constructor
Player *player_new(char *, int);                                //(playerName, intialRole)
#endif