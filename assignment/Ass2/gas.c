// Frank Wang <zhenqi.wang@student.unsw.edu.au>
// MAY 2017
// calculate need for gas
// input be the bot, output an integer distance

#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"
#include <string.h>
#include "bot.h"

int gas(struct bot *b){
    struct location *l = b -> location;
    struct location *l0 = b -> location;
    struct commodity *c = b -> location -> commodity;
    int gass = 0;
    int i = 0;
    while(l -> next != l0){
        // ADD UP THE QUANTITY OF FUEL AT GAS STATION
        if(l -> type == LOCATION_PETROL_STATION){
            gass = gass + l -> quantity;
        }
        l = l -> next;
    }

    
    return gass;
    
}

