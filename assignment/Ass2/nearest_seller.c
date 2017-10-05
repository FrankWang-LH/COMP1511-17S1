// Frank Wang <zhenqi.wang@student.unsw.edu.au>
// MAY 2017
// find the distance to the nearest seller
// input the bot, output an integer distance

#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"
#include <string.h>
#include "bot.h"

#define LOW_PRICE 75
#define LOW_NEED 10
#define SOLD_OUT 0

int nearest_seller(struct bot *b){
    struct location *lA = b -> location;
    int disD = 0;
    int disU = 0;
    int priceD = 0;
    int priceU = 0;
    // first find the upwards SELLER
    while(lA -> next != b -> location){
        if (lA -> type == LOCATION_SELLER){
            if(lA -> quantity != SOLD_OUT && needSp(lA) > LOW_NEED && lA -> price > LOW_PRICE){
                // need of commodity can't be 0
                // price higher than certain number to guarantee profit
                priceD = lA -> price;
                break; // break when matching reuqirements
            }
        }
        disD = disD + 1;
        lA = lA -> next;
    }

    // then the lower one, same as above
    struct location *lB = b -> location;
    while(lB -> previous != b -> location){
        if (lB -> type == LOCATION_SELLER){
            if(lB -> quantity != SOLD_OUT && needSp(lB) > LOW_NEED &&  lB -> price > LOW_PRICE){
                priceU = lB -> price;
                break;
            }
        }
        disU = disU + 1;
        lB = lB -> previous;
    }

    // compare and return
    if(disD > disU){
        disU = - disU;
        return disU;
    } else if(disD < disU){       
        return disD;
    } else {
        // for the same distance, buy the expensive commodity
        if(priceD > priceU){
            return disD;
        } else {
            disU = - disU;
            return disU;
        }
    }
}



