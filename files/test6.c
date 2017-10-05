#include <stdio.h>

void f(double x, double array[],int length);

int main(void) {
    double a[42];
    int i=0;
    f(2,a,42);
    while (i<42) {
        printf("2 to the %d = %lf\n",i,a[i]);
        i=i+1;
    }

    return 0;
}

void f(double x, double array[],int length) {
    double power=1;
    int i=0;
    
    while (i<length) {
        array[i]=power;
        power=power*x;
        i=i+1;
    }
    
}
