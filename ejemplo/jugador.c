#include <stdio.h>
#include <stdlib.h>
#include "jugador.h"
#include "dt.h"

static void _destroy(Jugador *this){
    this->observer->destroyOb(this->observer);
    if(this != NULL){
        free(this);
        this = NULL;
    }
}
static Ubi _getUbicacion(Jugador *this){
    printf("Jugador: getUbicación: %d\n",this->ubicacion);
    return this->ubicacion;
}
//Tal vez si realizo herencia y coloco el atributo observer de primero en la clase jugador pueda
//omitir esto
static void _firmarContrato(Jugador *this, Dt *dt){
    printf("Jugador: firmarContrato\n");
    dt->addObserver(dt, this->observer);  
}
static void _handleDtEvent(Jugador *this, Dt *dt){
    //printf("Jugador: %s, se reubicará por orden de: %s\n",this->nombre,dt->nombre);
    this->ubicacion = 2;
}

static void _update(Jugador *this, int state, void *subject){
    printf("Jugador: update\n");
    _handleDtEvent(this, (Dt*) subject);
}
Jugador *jugador_new(char *nombre, int ubi){
    Jugador *this = (Jugador*)malloc(sizeof(*this));
    this->nombre = nombre;
    this->ubicacion = ubi;
    this->destroy = _destroy;
    this->getUbicacion = _getUbicacion;
    this->firmarContrato = _firmarContrato;
    this->observer = observer_new(this, (void (*)(void*, int, void*))_update);
    return this;
}