#include <stdio.h>

int main (void) {

    
    
    
    int a = 2, b = 7;
    double res;
    res = b/a;
    printf("%lf\n",res);

    int i = 0;
    while (i < 5) {
        printf("hi\n");
        i = i + 2;
    }

    int x, y, z = 5;
    x = (z == 4);
    y = (z = 4);
    printf("%d %d %d\n",x,y,z);

    x = 5;
    if (x < 0) {
        printf("a\n");
    } else if (x < 3) {
        printf("b\n");
    } else if (x < 6) {
        printf("c\n");
    } else if (x < 9) {
        printf("d\n");
    }

    return 0;
}
