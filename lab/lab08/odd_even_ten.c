//revision 3

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int i = 0;
    int array[10];
    
    while(i < 10){
        scanf("%d", &array[i]);
        i++;
    }

    printf("Odd numbers were: ");
    i = 0;
    while(i < 10){
        if(array[i] % 2 != 0){
            printf("%d ",array[i]);
        }
        i++;
    }
    printf("\n");
    
    printf("Even numbers were: ");
    i = 0;
    while(i < 10){
        if(array[i] % 2 == 0){
            printf("%d ",array[i]);
        }
        i++;
    }
    printf("\n");

    return 0;
}
