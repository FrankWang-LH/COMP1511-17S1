//revision 4

#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000

int main(void){

    int i = 0;
    int array[MAX_NUM];
    
    while(i < MAX_NUM){
        scanf("%d", &array[i]);
        if(array[i] < 0){
            array[i] = 0;
            break;
        }
        i++;
    }

    printf("Odd numbers were: ");
    i = 0;
    while(array[i] != 0){
        if(array[i] % 2 != 0){
            printf("%d ",array[i]);
        }
        i++;
    }
    printf("\n");
    
    printf("Even numbers were: ");
    i = 0;
    while(array[i] != 0){
        if(array[i] % 2 == 0){
            printf("%d ",array[i]);
        }
        i++;
    }
    printf("\n");

    return 0;
}
