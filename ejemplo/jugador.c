#include <stdio.h>
#include "jugador.h"
#include "dt.h"

//Se hace así ya que podemos tener distintos tipos de eventos, Ej: que un jugador le diga a otros.
static void _DtEvent(Jugador *this, Dt *dt){
    printf("%s, se reubicará por orden de: %s\n",this->nombre,dt->nombre);
    if(dt->estrategia == 0){
        this->ubicacion == 0;
    }
    else if(dt->estrategia == 1){
        this->ubicacion == 1;
    }
    else if(dt->estrategia == 2){
        this->ubicacion == 2;
    }
}
static Ubi _getUbicacion(Jugador *this){
    return this->ubicacion;
}

static void _update(Jugador *this, int state, void *subject){
    _DtEvent(this, (Dt*)subject);
}

Jugador *jugador_new(char *nombre, Ubi ubic){
    Jugador *this = (Jugador*)malloc(sizeof(*this));
    this->nombre = nombre;
    this->ubicacion = ubic;
    this->getUbicacion = _getUbicacion;
    this->observer = observer_new(this, (void (*)(void*, int, void*))_update);
}