// Frank Wang <zhenqi.wang@student.unsw.edu.au>
// MAY 2017
// extra header files

#define LOW_PRICE 75
#define LOW_NEED 10
#define SOLD_OUT 0

// prototypes used
void read(struct bot *b);
int nearest_seller(struct bot *b);
int nearest_buyer(struct bot *b);
int need(struct bot *b);
int needSp(struct location *l);
int profit(struct location *l);
int gas(struct bot *b);
