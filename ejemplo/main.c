#include <stdio.h>
#include "player.h"
#include "coach.h"

int main(){
    //PlAYERS
    Player *bicho = player_new("Serresiete", 0);
    Player *lukita = player_new("Modric", 1);
    Player *sergio = player_new("Ramos", 2);
    //PLAYER WITH INVALID ROLE (SO IT CHOOSES A RANDOM ONE FOR HIM)
    Player *miguel = player_new("Miguel", 8);       

    //COACH
    Coach *carletto = coach_new("Carletto Ancelotti");

    //PLAYERS ENTER FIELD
    bicho->enterField(bicho, carletto);
    lukita->enterField(lukita, carletto);
    sergio->enterField(sergio, carletto);
    miguel->enterField(miguel,carletto);

    //LOCATION OF PLAYERS
    bicho->getLocation(bicho);
    lukita->getLocation(lukita);
    sergio->getLocation(sergio);
    miguel->getLocation(miguel);

    //CHANGE STRAT TO DEFENSIVE
    carletto->giveOrder(carletto, 3);
    
    //LOCATION OF PLAYERS
    bicho->getLocation(bicho);
    lukita->getLocation(lukita);
    sergio->getLocation(sergio);
    miguel->getLocation(miguel);

    //CHANGE STRAT TO ULTRA OFFENSIVE
    carletto->giveOrder(carletto, 0);

    //LOCATION OF PLAYERS
    bicho->getLocation(bicho);
    lukita->getLocation(lukita);
    sergio->getLocation(sergio);
    miguel->getLocation(miguel);

    //CHANGE STRAT TO INVALID OPTION (SO IT CHOOSES A RANDOM ONE)
    carletto->giveOrder(carletto, 9);

    //LOCATION OF PLAYERS
    bicho->getLocation(bicho);
    lukita->getLocation(lukita);
    sergio->getLocation(sergio);
    miguel->getLocation(miguel);
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