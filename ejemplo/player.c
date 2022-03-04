#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "coach.h"

static void _destroy(Player *this){
    printf("DEBUG: Player: destroy()\n");
    this->observer->destroyOb(this->observer);
    if(this != NULL){
        free(this);
        this = NULL;
    }
}
static Location _getLocation(Player *this){
    printf("DEBUG: Player: getLocation()\n");
    printf("\n\tPlayer '%s' location: %d\n\n", this->name, this->location);
    return this->location;
}
static void _enterField(Player *this, Coach *coach){
    printf("DEBUG: Player: EnterField()\n");                
    coach->addObserver(coach, this->observer);  
    printf("\n\tPlayer '%s' entered the field\n\n", this->name); 
}
static void _handleDtEvent(Player *this, Coach *dt){
    printf("DEBUG: Player: handleDtEvent()\n");                    
    this->location = 2;
    printf("\n\tPlayer '%s' changed location to: %d\n\n",this->name, 2);
}

static void _update(Player *this, int state, void *subject){
    printf("DEBUG: Player: update()\n");                       
    _handleDtEvent(this, (Coach*) subject);
}
Player *player_new(char *playerName, int default_location){
    printf("DEBUG: Player: player_new()\n");
    Player *this = (Player*)malloc(sizeof(*this));
    this->name = playerName;
    this->location = default_location;
    this->destroy = _destroy;
    this->getLocation = _getLocation;
    this->enterField = _enterField;
    this->observer = observer_new(this, (void (*)(void*, int, void*))_update);
    printf("\n\tPlayer '%s' created\n\n", playerName);
    return this;
}