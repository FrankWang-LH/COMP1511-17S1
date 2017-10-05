// Frank and Anant and Tanya
// 08/05/2017
// find the nearest gas station

#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"

int nearest_fuel(struct bot *b){
    struct location *lA = b -> location;
    int disD = 0;
    int disU = 0;
    int i = 0;
    while(i == 0){
        if (lA -> type == LOCATION_PETROL_STATION){
            i = 1;
        }
        disD = disD + 1;
        lA = lA -> next;
    }
    i = 0;
    struct location *lB = b -> location;
    while(i == 0){
        if (lB -> type == LOCATION_PETROL_STATION){
            i = 1;
        }
        disU = disU + 1;
        lB = lB -> previous;
    }

    disU = disU - 1;
    disD = disD - 1;

    if(disD >= disU){
        disU = - disU;
        return disU;
    } else {
        return disD;
    }
}



