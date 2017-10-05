// to determine a perfect number
// 20/03/2017
// Frank Wang and Edmond Lung

#include <stdio.h>

int main (void)
{

    // Get a number
    printf("Enter Number: ");

    int num;
    scanf("%d", &num);

    // Find out the factors
    printf("The factors of %d are:\n",num);

    int i = 1;
    int sum = 0; 
    while (i <= num) {

        if (num % i == 0) {
            printf("%d \n",i);
            sum = sum + i;

        }

    i=i+1;

    }

    printf("Sum of factors = %d \n",sum);
    
    // Determine whether it's perfect    
    if (num == (sum/2)) {
            printf("%d is a perfect number\n",num);
    } else {
            printf("%d is not a perfect number\n",num);
    }


return 0;


}
