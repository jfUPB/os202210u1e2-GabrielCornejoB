#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "coach.h"

static void _destroy(Player *this){
    this->observer->destroyOb(this->observer);
    if(this != NULL){
        free(this);
        this = NULL;
    }
}
static Location _getLocation(Player *this){
    printf("Player: getLocation(): %d\n",this->location);
    return this->location;
}
//Tal vez si realizo herencia y coloco el atributo observer de primero en la clase jugador pueda
//omitir esto
static void _enterField(Player *this, Coach *coach){
    printf("Player: EnterField()\n");
    coach->addObserver(coach, this->observer);  
}
static void _handleDtEvent(Player *this, Coach *dt){
    //printf("Jugador: %s, se reubicará por orden de: %s\n",this->nombre,dt->nombre);
    this->location = 2;
}

static void _update(Player *this, int state, void *subject){
    printf("Player: update()\n");
    _handleDtEvent(this, (Coach*) subject);
}
Player *player_new(char *playerName, int default_location){
    Player *this = (Player*)malloc(sizeof(*this));
    this->name = playerName;
    this->location = default_location;
    this->destroy = _destroy;
    this->getLocation = _getLocation;
    this->enterField = _enterField;
    this->observer = observer_new(this, (void (*)(void*, int, void*))_update);
    return this;
}