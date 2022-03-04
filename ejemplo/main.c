#include <stdio.h>
#include "player.h"
#include "coach.h"

int main(){
    Player *bicho = player_new("Serresiete", 0);
    Coach *carlos = coach_new("Carletto");
    bicho->getLocation(bicho);

    bicho->enterField(bicho, carlos);
    carlos->giveOrder(carlos, 4);

    printf("\n\tNew strat %d\n\n", carlos->new_strat);
    
    bicho->getLocation(bicho);
    return 0;
}