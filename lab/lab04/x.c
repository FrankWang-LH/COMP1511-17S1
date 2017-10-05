// Print an X shaped square
// 20/03/2017
// Frank Wang and Edmond Lung

#include <stdio.h>

int main (void) {

    int num;
    printf("Enter Size: ");
    scanf("%d",&num);

    int row = 1;
    
    while (row <= num) {
        int col = 1;
        while(col <= num){        
            if((col == row) || (col == (num - row + 1))){
                printf("*");
            } else {
                printf("-");
            }
            
            col = col +1;

        }
        printf("\n");
        row = row + 1;

    }
    

        return 0;

}
