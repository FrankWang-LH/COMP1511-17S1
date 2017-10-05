// Frank Wang <zhenqi.wang@student.unsw.edu.au>
// MAY 2017
// calculate need using location
// basically the same as need.c

#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"
#include <string.h>
#include "bot.h"

// same as need.c
int needSp(struct location *l){

    struct location *l0 = l;
    struct commodity *c = l -> commodity;
    int needs = 0;
    int i = 0;
    while(l -> next != l0){
        if(l -> type == LOCATION_BUYER){
            if(strcmp(c -> name, l -> commodity -> name) == 0){
            needs = needs + l -> quantity;
            }
        }
        l = l -> next;
    }
    
    return needs;
    
}

