//revision 4

#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000

int main(void){

    int i = 0;
    int array[MAX_NUM];
    int c = 0;    

    while(scanf("%d", &c) == 1){
        array[i] = c;
        i++;
    }

    int number = i;
    printf("Odd numbers were: ");
    i = 0;
    while(i < number){
        if(array[i] % 2 != 0){
            printf("%d ",array[i]);
        }
        i++;
    }
    printf("\n");
    
    printf("Even numbers were: ");
    i = 0;
    while(i < number){
        if(array[i] % 2 == 0){
            printf("%d ",array[i]);
        }
        i++;
    }
    printf("\n");

    return 0;
}
