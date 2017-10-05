// print a chessboard
// 20/03/2017
// Frank Wang and Edmond Lung

#include <stdio.h>

int main (void) {

    // Get the size
    printf("Enter size: ");

    int size;
    scanf("%d", &size);

    // Print it
    int i = 1;
    while (i <= (size * size) ) {
        
        if(i % 2 == 0){

            printf("*");
        } else {

            printf("-");
        }


        // Change a line after printing "s" Symbols
        if (i % size == 0) {

            printf("\n");

        }

    i = i + 1;

    }

      return 0;

}


