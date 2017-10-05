#include <stdio.h>
#include <string.h>
#include "trader_bot.h"
#include "bot.h"

void read(struct bot *b){
    struct location *lA = b -> location;
    char *n = b -> location -> name; 
    int i = 0;
    while(1){
        if(lA -> type == LOCATION_BUYER){
            struct need_supply[] {
                {lA -> commodity -> name , NULL, lA -> quantity};
            }
            lA = lA -> next;
            break;
        } else {
            lA = lA -> next;
        }
    }
    while(strcmp(n, lA -> next -> name) != 0){
        if(lA -> type == LOCATION_BUYER){
            i = 0;
            while(need_supply[i] != NULL){
                if(strcmp(need_supply[i] -> name, lA -> commodity -> name) != 0){
                    struct need_supply[] {
                        {lA -> commodity -> name , NULL, lA -> quantity};
                    }
                } else if(strcmp(need_supply[i] -> name, lA -> commodity -> name) == 0){
                    need_supply[i] -> need = need_supply[i] -> need + lA-> quantity;    
                } 
                i++;
            }
           
        } else if(lA -> type == LOCATION_SELLER){
            i = 0;
            while(need_supply[i] != NULL){
                if(strcmp(need_supply[i] -> name, lA -> commodity -> name) != 0){
                    struct need_supply[] {
                        {lA -> commodity -> name , lA -> quantity, NULL};
                    }
                } else if(strcmp(need_supply[i] -> name, lA -> commodity -> name) == 0){
                    need_supply[i] -> need = need_supply[i] -> supply + lA-> quantity;    
                } 
                i++;
            }
        }
        lA = lA -> next;
           
    }
    
}
