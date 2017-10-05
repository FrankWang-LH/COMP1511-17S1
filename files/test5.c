#include <stdio.h>

// function to calculate x suqare
int cube(int n) {
    int result = 0;
    result = n * n * n;
    return result;
}

// function to calculate x to the power of n
double power(double x, int n) {
    double result = 1;
    int i = 0;
    while (i < n) {
        result = result * x;
    i = i + 1;
    }
    return result;
}

//main body
int main (void) {

    //function 1 (cube)
    int x,y;
    printf("Enter a number: ");
    scanf("%d",&x);  
    y=cube(x);
    printf("The cube of %d is: %d\n",x,y);

    //function 2 (power)    
    double m,n,p;
    printf("Enter the base: ");    
    scanf("%lf",&m);
    printf("Enter the power: ");
    scanf("%lf",&n);  
    p=power(m,n);
    printf("%.0lf to the power of %.0lf is %.0lf\n",m,n,p);

    return 0;
}

