// Frank Wang <zhenqi.wang@student.unsw.edu.au>
// MAY 2017
// calculate need
// input bot, output integer

#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"
#include <string.h>
#include "bot.h"

int need(struct bot *b){
    struct location *l = b -> location;
    struct location *l0 = b -> location;
    struct commodity *c = b -> location -> commodity;
    int needs = 0;
    int i = 0;
    while(l -> next != l0){
        if(l -> type == LOCATION_BUYER){
            if(strcmp(c -> name, l -> commodity -> name) == 0){ 
                // add up need for a certain commodity
                needs = needs + l -> quantity;
            }
        }
        l = l -> next;
    }
    
    // return value
    return needs;
    
}

