// Frank Wang <zhenqi.wang@student.unsw.edu.au>
// ID : 5141545
// MAY 2017
// CS1511-Assignment 2-Pass actions to trader bot

#include <stdio.h>
#include <stdlib.h>
#include "trader_bot.h"
#include <string.h>
#include "bot.h"

#define CRITICAL_FIGURE 3 // THE AMOUNT OF TOTAL FUEL IS TOO LOW AND GIVE UP MOVING

void get_action(struct bot *bot, int *action, int *n){
    
    struct location *l = bot -> location;// pointer to the bot's location

    int i = 0;
    int m = 0;

    int fuel = nearest_fuel(bot);// distance to nearest fuel
    int seller = 0;// distance to nearest seller
    int buyer = 0;// distance to nearest buyer
    int needs = 0;// need of a certain commodity

    // STOP MOVING WHEN TOO LITTLE FUEL REMAINING IN THE WORLD
    // OR WHEN VERY FEW TURNS LEFT(BUY THINGS THEN WILL BE WASTING MONEY)
    if((gas(bot) == 0 && bot -> fuel == 0) || (gas(bot)  <= CRITICAL_FIGURE && bot -> fuel <= CRITICAL_FIGURE && bot -> cargo == NULL) || (bot -> turns_left <= 2 && bot->cargo == NULL)){
        *action = ACTION_MOVE;
        *n = 0;
    // refuel    
    } else if(bot -> fuel <= bot -> fuel_tank_capacity*9/50 && bot -> location -> type != LOCATION_PETROL_STATION && gas(bot) > 0){
        // when fuel lower than a certain level go refueling
        // not using the nearest fuel value
        // reason is to leave enough fuel after the next movement
        *action = ACTION_MOVE;
        *n = fuel;
    } else if(bot -> location -> type == LOCATION_PETROL_STATION && bot-> fuel != bot -> fuel_tank_capacity && bot -> location -> quantity != 0){
        // buy fuel at fuel station
        *action = ACTION_BUY;
        *n = bot -> fuel_tank_capacity - bot -> fuel + 1;// always try refuel too max fuel capacity

    // find seller when the bot is empty
    } else if(l -> type != LOCATION_BUYER && l -> type != LOCATION_SELLER && bot -> cargo == NULL){
        l = bot -> location;
        seller = nearest_seller(bot);// calculate distance to nearest seller
        *action = ACTION_MOVE;
        *n = seller;
    // move to buyer when the bot is carrying commodity and haven't reach the buyer
    } else if(l -> type != LOCATION_BUYER && l -> type != LOCATION_SELLER && bot -> cargo != NULL){
        l = bot -> location;
        buyer = nearest_buyer(bot);// calculate distance to nearest buyer
        *action = ACTION_MOVE;
        *n = buyer;
    // buy things after reaching seller
    } else if(l -> type == LOCATION_SELLER && bot -> cargo == NULL && l -> quantity != 0 && bot -> fuel >= nearest_buyer(bot)){
        l = bot -> location;
        needs = 0;
        *action = ACTION_BUY;
        needs = need(bot);// calculate need for the commodity at this location
        *n = needs;
    // go to buyer after purchasing commodity
    } else if(l -> type == LOCATION_SELLER && bot -> cargo != NULL){
        l = bot -> location;
        buyer = nearest_buyer(bot);// calculate distance to nearest buyer
        *action = ACTION_MOVE;
        *n = buyer;
    // sell your cargo at the correct buyer
    } else if(l -> type == LOCATION_BUYER && bot -> cargo != NULL && l -> quantity != 0 && strcmp(l -> commodity -> name,bot -> cargo -> commodity -> name) == 0){
        l = bot -> location;
        *action = ACTION_SELL;
        *n = bot -> cargo -> quantity;
    // if at a wrong buyer (wrong commodity type)
    } else if(l -> type == LOCATION_BUYER && bot -> cargo != NULL && l -> quantity != 0 && strcmp(l -> commodity -> name,bot -> cargo -> commodity -> name) != 0){
        l = bot -> location;
        buyer = nearest_buyer(bot);
        *action = ACTION_MOVE;
        *n = buyer;
    // find a new seller after selling everything
    } else if(l -> type == LOCATION_BUYER && bot -> cargo == NULL){
        l = bot -> location;
        seller = nearest_seller(bot);
        *action = ACTION_MOVE;
        *n = seller;
    // when a buyer doesn't need more and you're still carrying good, go to another buyer
    } else if(l -> type == LOCATION_BUYER && bot -> cargo != NULL && l -> quantity == 0){
        l = bot -> location;
        buyer = nearest_buyer(bot);
        *action = ACTION_MOVE;
        *n = buyer;
    // find a new commodity after one is no longer profitable
    } else if(l -> type == LOCATION_SELLER && needs == 0){
        l = bot -> location;
        seller = nearest_seller(bot);
        *action = ACTION_MOVE;
        *n = seller;
    // else stand still
    } else {
        *action = ACTION_MOVE;
        *n = 0;
    }

}

