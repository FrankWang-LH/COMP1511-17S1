// Frank Wang <zhenqi.wang@student.unsw.edu.au>
// MAY 2017
// find the distance to the nearest seller
// input be the bot, output an integer distance

#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"
#include <string.h>
#include "bot.h"

int nearest_seller(struct bot *b){
    struct location *lA = b -> location;
    int disD = 0;
    int disU = 0;
    int priceD = 0;
    int priceU = 0;
    // first find the upwards SELLER
    while(lA -> next != b -> location){
        if (lA -> type == LOCATION_SELLER){
            if(lA -> quantity != 0 && needSp(lA) > 10 && lA -> price > 50){
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
            if(lB -> quantity != 0 && needSp(lB) > 10 &&  lB -> price > 50){
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



