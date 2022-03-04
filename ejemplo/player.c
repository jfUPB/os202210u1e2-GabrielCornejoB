#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "coach.h"

char *printRole(int num){
    if(num == 0){ return "STRIKER"; }
    else if(num == 1){ return "MIDFIELDER"; }
    else if(num == 2){ return "DEFENDER"; }
    else{ return "a"; }                         //Colocar algo aca que acabe el programa, tambien toca hacer eso en muchos lados   
}
char *printLocation(int num){
    if(num == 0){ return "UP"; }
    else if(num == 1){ return "MID"; }
    else if(num == 2){ return "DOWN"; }
    else{ return "a"; }
}
static void _destroy(Player *this){
    printf("DEBUG: Player: destroy()\n");
    this->observer->destroyOb(this->observer);
    if(this != NULL){
        free(this);
        this = NULL;
    }
}
static Role _getRole(Player *this){
    printf("DEBUG: Player: getRole()\n");
    printf("\n\tPlayer '%s' role is: %s\n\n", this->name, printRole(this->role));
    return this->role;
}
static Location _getLocation(Player *this){
    printf("DEBUG: Player: getLocation()\n");
    printf("\n\tPlayer '%s' location: %s\n\n", this->name, printLocation(this->location));
    return this->location;
}
static void _enterField(Player *this, Coach *coach){
    printf("DEBUG: Player: EnterField()\n");                
    coach->addObserver(coach, this->observer);  
    printf("\n\tPlayer '%s' entered the field\n\n", this->name); 
}
void verifyPosition(Player *this, int new){
    if(this->location != new){
        this->location = new;
        printf("\n\tPlayer '%s' changed location to: %s\n\n",this->name, printLocation(this->location));
    }
}
static void _handleDtEvent(Player *this, Coach *coach){
    printf("DEBUG: Player: handleDtEvent()\n");  
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
static void _update(Player *this, int state, void *subject){
    printf("DEBUG: Player: update()\n");                       
    _handleDtEvent(this, (Coach*) subject);
}
Player *player_new(char *playerName, int role){
    printf("DEBUG: Player: player_new()\n");
    Player *this = (Player*)malloc(sizeof(*this));
    this->name = playerName;
    this->role = role;
    this->location = role;
    this->destroy = _destroy;
    this->getRole = _getRole;
    this->getLocation = _getLocation;
    this->enterField = _enterField;
    this->observer = observer_new(this, (void (*)(void*, int, void*))_update);
    printf("\n\tPlayer '%s' created, default role is: %s\n\n", playerName, printRole(this->role));
    return this;
}

