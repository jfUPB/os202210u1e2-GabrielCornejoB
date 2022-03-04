#include <stdio.h>
#include "player.h"
#include "coach.h"

int main(){
    Player *bicho = player_new("Serresiete", 0);
    Player *lukita = player_new("Modric", 1);
    Player *sergio = player_new("Ramos", 2);
    Coach *carletto = coach_new("Carletto Ancelotti");

    bicho->enterField(bicho, carletto);
    lukita->enterField(lukita, carletto);
    sergio->enterField(sergio, carletto);

    bicho->getLocation(bicho);
    lukita->getLocation(lukita);
    sergio->getLocation(sergio);

    carletto->giveOrder(carletto, 4);
    
    bicho->getLocation(bicho);
    lukita->getLocation(lukita);
    sergio->getLocation(sergio);
    return 0;
}
/*
STRATEGIES
UO          0       Suben TODOS
O           1       Suben MEDIOCAMPISTAS, van al medio los DEFENSAS
B           2       TODOS en su posicion normal
D           3       Bajan MEDIOCAMPISTAS, van al medio los DELANTEROS
UD          4       Bajan TODOS 

LOCATIONS
UP          0
MID         1
BACK        2

ROLES
STRIKER     0
MIDFIELDER  1
DEFENDER    2
*/