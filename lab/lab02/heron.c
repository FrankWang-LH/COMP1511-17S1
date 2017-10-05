// March 6 2017
// Frank Wang and Edmond Lung
// Calculate Area of Triangle

#include <stdio.h>
#include <math.h>

int main (void) {
   double a;
   double b;
   double c;
   double s;
   double area;

//Enter length a
   printf("Enter side 1: ");
   scanf("%lf", &a);
   
//Enter length b
   printf("Enter side 2: ");
   scanf("%lf", &b);

//Enter length c
   printf("Enter side 3: ");
   scanf("%lf", &c);

//Calculation
   s = (a + b + c)/2;
 if (a < b + c && b < a + c && c < a + b)  {
   area = sqrt (s*(s-a)*(s-b)*(s-c));
   printf("Area = %.6lf \n", area);
} else {
    printf("Error: triangle inequality violated.\n");
	}

	return 0;
}
