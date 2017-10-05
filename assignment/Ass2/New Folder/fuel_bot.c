// Frank and Anant and Tanya
// 08/05/2017
// fuel the bot

#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"

void get_action(struct bot *bot, int *action, int *n){
    int dis = nearest_fuel(&bot[0]);
    
    if(dis == 0){
        if(bot -> fuel_tank_capacity > bot -> fuel){
            *action = ACTION_BUY;
            *n = bot -> fuel_tank_capacity - bot -> fuel;
        } else {
            *action = ACTION_MOVE;
            *n = bot -> maximum_move;
        }
    } else {
        *action = ACTION_MOVE;
        if(bot -> fuel >= dis){
            if(dis > bot -> maximum_move){
                *n = bot -> maximum_move;
            } else {
                *n = dis;
            }
        } else {
            if(bot -> fuel > bot -> maximum_move){
                *n = bot -> maximum_move;
            } else {
                *n = bot -> fuel;
            }
        }
    }
}





