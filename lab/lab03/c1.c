// challenge 2

#include <stdio.h>

int main (void) {

    int a,b,c;

    printf("Enter integer: ");
    scanf("%d",&a);

    printf("Enter integer: ");
    scanf("%d",&b);

    printf("Enter integer: ");
    scanf("%d",&c);

    int max,min,avg;

    (max=((a >= b) &&  a))||(max=((a < b) &&  b));
    printf("%d\n",max);
    ((a <= b) && (min = a))||((a > b) && (min = b));
    ((max >= c) && (max = max -1 + 1))||((max < c) && (max = c));
    ((min <= c) && (min = min -1 + 1))||((min > c) && (min = c));

    // max=(a>=b)*a+(a<b)*b;
    // min=(a<=b)*a+(a>b)*b;
    // max=(max>=c)*max+(max<c)*c;
    // min=(min<=c)*min+(min>c)*c;


    avg = a + b + c - min -max;
        
    printf("The integers in order are: %d %d %d\n",min,avg,max);


        return 0;
}


