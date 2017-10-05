// 6 March 2017
// Frank Wang and Edmond Lung
// Dating range indicator

#include <stdio.h>

int main(void) {
  int age=0;

	printf("Enter your age: ");
	scanf("%d", &age);

//Check for age range
if ( age < 16) {
    printf("You are too young to be dating.\n");
	}
else if ( age >= 16 && age < 22) {
   printf("Your dating range is 16 to 22 years old.\n");
	}
else if ( age >=22  && age < 30 ) {
   printf("Your dating range is 18 to 30 years old.\n");
	}
else if ( age >= 30 ) {
   printf("Your dating range is 29 to 74 years old.\n");
	}
	return 0;
} 

