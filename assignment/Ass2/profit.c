// Frank Wang <zhenqi.wang@student.unsw.edu.au>
// MAY 2017
// calculate profit
// input location

#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"
#include <string.h>
#include "bot.h"

int profit(struct location *l){
    struct location *l0 = l;
    struct commodity *c = l -> commodity;
    int profits = 0;
    int i = 0;
    while(l -> next != l0){
        if(strcmp(c -> name, l -> commodity -> name) == 0 && l -> type == LOCATION_BUYER){
            profits = profits + l -> quantity * l -> price;
        } else if(strcmp(c -> name, l -> commodity -> name) == 0 && l -> type == LOCATION_SELLER){
            profits = profits - l -> quantity * l -> price;
        }
        l = l -> next;
    }
    
    return profits;
    
}

