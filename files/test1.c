// tut example 2 week 2
// score report

#include <stdio.h>
#include <stdlib.h> 

int main (void) {
   int grade;
   printf("Please enter a number: ");
   scanf("%d", &grade);
   
   if (grade >= 50 && grade <= 100) {
       printf("Pass\n");
   } else if (grade >= 0 && grade < 50) {
       printf("Fail\n");
   } else {
       printf("Error\n");
   }

   return 0;
)
