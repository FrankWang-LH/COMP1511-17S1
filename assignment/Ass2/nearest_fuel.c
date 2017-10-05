// Frank and Anant and Tanya
// 08/05/2017
// find the nearest gas station
// input be the bot, output an integer distance

#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"
#include <string.h>
#include "bot.h"

#define SOLD_OUT 0

int nearest_fuel(struct bot *b){
    struct location *lA = b -> location;
    int disD = 0;
    int disU = 0;
    // first find the upwards gas station
    while(lA -> next != b -> location){
        if (lA -> type == LOCATION_PETROL_STATION){
            if(lA -> quantity != SOLD_OUT){
                break;// break when matching requirements
            }
        }
        disD = disD + 1;
        lA = lA -> next;
    }
       
    // then the lower one
    struct location *lB = b -> location;
    while(lB -> previous != b -> location){
        if (lB -> type == LOCATION_PETROL_STATION){
            if(lB -> quantity != SOLD_OUT){
                break;
            }
        }
        disU = disU + 1;
        lB = lB -> previous;
    }


    // compare and return
    if(disD >= disU){
        disU = - disU;
        return disU;
    } else {
        return disD;
    }
}



