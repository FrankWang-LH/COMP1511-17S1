// Prints out plus symbol 
// 20.3.17
// Edmond Lung and Frank Wang

#include <stdio.h>

int main(void){
    
    int num;
    printf("Enter size: ");
    scanf("%d", &num);
    
    int row = 1;
    while (row <= num) {
        int col = 1;

        while(col <= num){ 

            // Print Regular Rows           
            if(row != (num + 1)/2){

                if(col == (num + 1)/2){
                    printf("*");
                } else {
                    printf("-");
                }

                col = col + 1;
                
            // Print Row (n+1)/2
            } else {
                while(col <= num){  
                printf("*");
                col = col + 1;
                }

            }
        }

        printf("\n");
        row = row + 1;

    }

            return 0;
}
