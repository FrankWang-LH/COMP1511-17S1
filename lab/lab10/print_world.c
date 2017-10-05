// Frank and Anant and Tanya
// 08/05/2017
// print the world

#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"
#include <string.h>

void print_world(struct bot *b){
    struct location *l = b -> location;
    char *n = b -> location -> name;
    int i = 0;
    while(i == 0){
        if(l -> type == LOCATION_OTHER){
            printf("%s: other\n", l -> name);
        } else if (l -> type == LOCATION_START){
            printf("%s: start\n", l -> name);
	    } else if (l -> type == LOCATION_SELLER){
            printf("%s: will sell %d units of %s for $%d\n",l -> name,l -> quantity, l -> commodity -> name, l -> price);
        } else if (l -> type == LOCATION_BUYER){
            printf("%s: will buy %d units of %s for $%d\n",l -> name,l -> quantity, l -> commodity -> name, l -> price);
        } else if (l -> type == LOCATION_DUMP){
            printf("%s: dump\n", l -> name);
        } else if (l -> type == LOCATION_PETROL_STATION){
            printf("%s: Petrol station %d units of available fuel for $%d\n",l -> name,l -> quantity,l -> price);
        }
        if(strcmp(n, l -> next -> name) == 0){
            i = 1;
        }
        l = l -> next;
        
    }
}
