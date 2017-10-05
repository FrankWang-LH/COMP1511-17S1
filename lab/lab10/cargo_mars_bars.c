// test

int cargo_mars_bars(struct bot *b){
    struct cargo * c = b -> cargo;
    
    while(c != NULL){
        if(strcmp("Mars Bars",c->commodity->name)==0){
            return c->quantity;
        }
        c = c -> next;
    }

    return 0;
}

int mars_bars_for_sale(struct bot *b){
    struct *location l = b -> location;
    if(l -> type != TYPE_SELLER){
        return 0;
    } else if (strcmp("Mars Bars", l -> commodity -> name) != 0){
        return 0;
	}

	return l->quantity;

}
