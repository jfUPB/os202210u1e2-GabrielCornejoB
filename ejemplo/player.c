#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "coach.h"
#include <time.h>

//Functions that takes enum number and turns it to its String representation
char *printRole(int num){
    if(num == 0){ return "STRIKER"; }
    else if(num == 1){ return "MIDFIELDER"; }
    else { return "DEFENDER"; }                           
}
char *printLocation(int num){
    if(num == 0){ return "UP"; }
    else if(num == 1){ return "MID"; }
    else { return "DOWN"; }
}
//Destroy Player
static void _destroy(Player *this){
    printf("DEBUG: Player: destroy()\n");
    this->observer->destroyOb(this->observer);
    if(this != NULL){
        free(this);
        this = NULL;
    }
}
//Returns Player´s Role
static Role _getRole(Player *this){
    char * s1 = "DEBUG: Player: getRole()";
    printf("%-40s\tPlayer '%s' role is: %s\n\n", s1, this->name, printRole(this->role));
    return this->role;
}
//Returns Player´s Location
static Location _getLocation(Player *this){
    char * s1 = "DEBUG: Player: getLocation()";
    printf("%-40s\tPlayer '%s' location: %s\n\n", s1, this->name, printLocation(this->location));
    return this->location;
}
//Player is added to Coach´s list
static void _enterField(Player *this, Coach *coach){
    printf("DEBUG: Player: EnterField()\n");                
    coach->addObserver(coach, this->observer);  
    printf("\tPlayer '%s' entered the field\n\n", this->name); 
}
//Verify if new position is same as actual position
void verifyPosition(Player *this, int new){
    if(this->location != new){
        this->location = new;
        printf("\tPlayer '%s' changed location to: %s\n\n",this->name, printLocation(this->location));
    }
    else{
        printf("\n");
    }
}
//Calls VerifyPosition in each case
static void _handleDtEvent(Player *this, Coach *coach){
    char * s1 = "DEBUG: Player: handleDtEvent()";
    printf("%-40s", s1);  
    if(coach->new_strat == 0){          //ULTRA OFFENSIVE
        verifyPosition(this, 0);        //TODOS
    }
    else if(coach->new_strat == 1){     //OFFENSIVE
        if(this->role == 0){            //STRIKER
            verifyPosition(this, 0);
        }
        else if(this->role == 1){       //MIDFIELDER
            verifyPosition(this, 0);
        }
        else if(this->role == 2){       //DEFENDER
            verifyPosition(this, 1);
        }
    }
    else if(coach->new_strat == 2){     //BALANCED
        if(this->role == 0){            //STRIKER
            verifyPosition(this, 0);
        }
        else if(this->role == 1){       //MIDFIELDER
            verifyPosition(this, 1);
        }
        else if(this->role == 2){       //DEFENDER
            verifyPosition(this, 2);  
        }
    }
    else if(coach->new_strat == 3){     //DEFFENSIVE
        if(this->role == 0){            //STRIKER
            verifyPosition(this, 1);
        }
        else if(this->role == 1){       //MIDFIELDER
            verifyPosition(this, 2);
        }
        else if(this->role == 2){       //DEFFENSIVE
            verifyPosition(this, 2);  
        }
    }
    else if(coach->new_strat == 4){     //ULTRA DEFFENSIVE
        verifyPosition(this, 2);        //TODOS
    }              
}
//Updates Player's location
static void _update(Player *this, void *subject){
    printf("DEBUG: Player: update()\n");                       
    _handleDtEvent(this, (Coach*) subject);
}
//Player constructor
Player *player_new(char *playerName, int role){
    printf("DEBUG: Player: player_new()\n");
    Player *this = malloc(sizeof(*this));
    this->name = playerName;
    if(role < 0 || role > 2){
        printf("DEBUG: Invalid role, choosing random role\n");
        int random;
        srand(time(0));
        random = rand() % 3;
        printf("DEBUG: Random role is: %d (%s)\n", random, printRole(random));
        this->role = random;
        this->location = random;
    }
    else{
        this->role = role;
        this->location = role;
    } 
    this->destroy = _destroy;
    this->getRole = _getRole;
    this->getLocation = _getLocation;
    this->enterField = _enterField;
    this->observer = observer_new(this, (void (*)(void*, void*))_update);
    printf("\tPlayer '%s' created, default role is: %s\n\n", playerName, printRole(this->role));
    return this;
}

