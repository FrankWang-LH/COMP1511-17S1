//revision 1

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int i = 0;
    int array[10];
    
    while(i < 10){
        scanf("%d", &array[i]);
        i++;
    }

    printf("Numbers were: ");
    i = 0;
    while(i < 10){
        printf("%d ",array[i]);
        i++;
    }
    printf("\n");
    
    return 0;
}
