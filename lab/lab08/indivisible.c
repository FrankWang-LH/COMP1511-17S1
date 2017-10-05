//revision 6

#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000

int main(void){

    int i = 0;
    int j = 0;
    int array[MAX_NUM];
    int c = 0;  
    int cont = 0;  

    while(scanf("%d", &c) == 1){
        array[i] = c;
        i++;
    }

    int number = i;
    printf("Indivisible numbers: ");
    i = 0;
    while(i < number){
        j = 0;
        cont = 0;
        while(j < number){
            if(array[i] % array[j] == 0){
                cont ++;
            }
            j++;
        }
        if(cont == 1){
            printf("%d ",array[i]);
        }
        i++;
    }
    printf("\n");
    

    return 0;
}
