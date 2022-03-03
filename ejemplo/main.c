#include <stdio.h>
#include "jugador.h"
#include "dt.h"

int main(){
    Jugador *bicho = jugador_new("Serresiete", 0);
    Dt *carlos = dt_new("Carletto");
    bicho->getUbicacion(bicho);

    bicho->firmarContrato(bicho, carlos);
    carlos->darOrden(carlos);
    
    bicho->getUbicacion(bicho);
    return 0;
}