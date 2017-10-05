// Frank Wang and Edmond Lung
// 20/03/2017
// print a spiral

#include <stdio.h>

int main (void) {
    
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int row = 1;
    int col = 1;

  
    while (row <= n) {
        //print the first half
        if (row <= (n+1)/2) {
            //print even rows
            if (row % 2 == 0){
                col = 1;
                while (col <= n){
                     if (col <= (row-3) && col % 2 == 1){
                        printf("*");
                     } else if (col >= n-row+2 && col % 2 ==1) {
                        printf("*");
                     } else {
                        printf("-");
                     }
                col = col + 1;
                }
            //print odd rows
            } else if (row % 2 == 1){
                col = 1;
                while (col <= n){
                    if (col <= (row-3) && col % 2 == 0){
                        printf("-");
                    } else if (col >= n-row+2 && col % 2 == 0){
                        printf("-");
                    } else {
                        printf("*");
                    }
                col = col + 1;
                }
            }
        //print the second half
        } else if (row > (n+1)/2) {
            //print even rows
            if (row % 2 == 0){
                col = 1;
                while (col <= n){
                    if (col <= (n-row) && col % 2 == 1){
                        printf("*");
                    } else if (col >= row + 1 && col % 2 == 1){
                        printf("*");
                    } else {
                        printf("-");
                    }
                col = col + 1;
                }
            //print odd rows
            } else if (row % 2 == 1){
                col = 1;
                while (col <= n){
                    if (col <= (n-row) && col % 2 == 0){
                        printf("-");
                    } else if ( col >= row+1 && col % 2 == 0){
                        printf("-");
                    } else {
                        printf("*");
                    }
                col = col + 1;
                }
            }
        }
        row = row + 1;
        printf("\n");
    }

        return 0;
}


                
     
