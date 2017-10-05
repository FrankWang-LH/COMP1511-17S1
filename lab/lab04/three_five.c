// to show the multiples of three and five
// 20/03/2017
// Frank Wang and Edmond Lung

#include <stdio.h>

int main (void)
{

    // Get a number
    printf("Enter Number: ");

    int num;
    scanf("%d", &num);

    // Work out the multiples within the limit
    int i = 1;
    while (i < num) {

        if ((i % 3 == 0)||(i % 5 == 0)) {
            printf("%d \n",i);

        }

    i=i+1;

    }


return 0;

}
