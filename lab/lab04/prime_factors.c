// Frank Wang and Edmond Lung
// 20/03/2017
// Work out the Prime Factorization

#include <stdio.h>

int main (void) {

    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    int i = 1;
    int numOfFactor = 0;
    int ori= num;
    int j = 2;
    int k = 0;
    int num1 = 0;

    // determine whether it's a prime
    while (i < num) {
        if(num % i ==0){
           numOfFactor = numOfFactor + 1;
        } else {            
           numOfFactor = numOfFactor + 1 - 1;
        }
        
        i = i + 1;
    }

    if(numOfFactor == 1){
        printf("%d is prime\n",num);
    } else {
        printf("The prime factorization of %d is:\n",num);

        // not prime, factorize it
        // 1st number
        while (j <= num){
            if(num % j == 0){
                k = j;
                printf("%d", j);
                num1 = num / j;
                num = 1; // stop this loop
                        
            } else { 
                j = j + 1 - 1;
            }
        
         j = j + 1;
        }
            
        // the following numbers        
        while (k <= num1){    
            if(num1 % k == 0){
                while (num1 % k == 0){

                    printf(" * %d", k);
                    num1 = num1 / k;

                    }
                        
            } else { 
             k = k + 1 - 1;
            }
            
            k = k + 1; 
        }
    
        // Right hand side        
        printf(" = %d\n",ori);
            
    }
    
    return 0;

}
