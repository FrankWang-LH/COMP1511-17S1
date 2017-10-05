// Frank Wang <zhenqi.wang@student.unsw.edu.au>
// MAY 2017
// find nearest buyer
// input be the bot, output an integer distance

#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"
#include <string.h>
#include "bot.h"

int nearest_buyer(struct bot *b){
    struct location *lA = b -> location;
    struct location *lB = b -> location;
    int disD = 0;
    int disU = 0;
    int priceD = 0;
    int priceU = 0;
    // first find the upwards BUYER
    if(b -> cargo != NULL){
        while(lA -> next != b -> location){
            if (lA -> type == LOCATION_BUYER && strcmp(b -> cargo -> commodity -> name,lA -> commodity -> name) == 0 && lA -> quantity != 0){
                // type of commodity should match, and quantity shouldn't be 0
                priceD = lA -> price;
                break;// break when meet a matching location
            }
            disD = disD + 1;
            lA = lA -> next;
        }
        // then the lower one
        while(lB -> previous != b -> location){            
            if (lB -> type == LOCATION_BUYER && strcmp(b -> cargo -> commodity -> name,lB -> commodity -> name) == 0 && lB -> quantity != 0){
                priceU = lB -> price;
                break;
            }
            disU = disU + 1;
            lB = lB -> previous;
        }
    } else {
        // find upper one when cargo's NULL
        struct commodity *c = b -> location -> commodity;
        while(lA -> next != b -> location){
            if (lA -> type == LOCATION_BUYER && strcmp(c -> name,lA -> commodity -> name) == 0 && lA -> quantity != 0){
                priceD = lA -> price;
                break;
            }
            disD = disD + 1;
            lA = lA -> next;
        }
        // then the lower one
        while(lB -> previous != b -> location){
            if (lB -> type == LOCATION_BUYER && strcmp(c -> name,lB -> commodity -> name) == 0 && lB -> quantity != 0){
                priceU = lB -> price;
                break;
            }
            disU = disU + 1;
            lB = lB -> previous;
        }
    }


    // compare and return
   if(disD > disU){
        disU = - disU;
        return disU;
    } else if(disD < disU){       
        return disD;
    } else {
        // for the same distance, choose the buyer offering a higher price
        if(priceD > priceU){
            return disD;
        } else {
            disU = - disU;
            return disU;
        }
    }
}



