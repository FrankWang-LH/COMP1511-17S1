// order 3 challenge 2

#include <stdio.h>

int main (void) {

    int a,b,c;

    printf("Enter integer: ");
    scanf("%d",&a);

    printf("Enter integer: ");
    scanf("%d",&b);

    printf("Enter integer: ");
    scanf("%d",&c);

 
    printf("The integers in order are: %d %d %d\n",((((a<=b)*a+(a>b)*b)<=c)*((a<=b)*a+(a>b)*b)+(((a<=b)*a+(a>b)*b)>c)*c),(a+b+c-((((a>=b)*a+(a<b)*b)>=c)*((a>=b)*a+(a<b)*b)+(((a>=b)*a+(a<b)*b)<c)*c)-((((a<=b)*a+(a>b)*b)<=c)*((a<=b)*a+(a>b)*b)+(((a<=b)*a+(a>b)*b)>c)*c)),((((a>=b)*a+(a<b)*b)>=c)*((a>=b)*a+(a<b)*b)+(((a>=b)*a+(a<b)*b)<c)*c));


        return 0;
}


