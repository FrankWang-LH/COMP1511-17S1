#include <stdio.h>

int main (void){
        
    int length;
    printf("Enter Length: ");
    scanf("%d", &length);

    int col=1;
    int row=1;
    while (row <= (2*length-1)){
        while(col <= (2*length-1))
        {
           if(col= (length/2)){
                printf("*");
            } else {
                printf(" ");
            }
        col = col + 1;
        }
    row = row +1;
    }

        return 0;
}







            return 0;

}
