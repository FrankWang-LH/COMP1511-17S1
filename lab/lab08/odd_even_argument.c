// revision 5

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[]){

    int i = 0;
    int array[1000];
    
    i = 0;
    while(i < argc - 1){
        array[i] = atoi(argv[i+1]);
        i++;
    }

    printf("Odd numbers were: ");
    i = 0;
    while(i < argc - 1){
        if(array[i] % 2 != 0){
            printf("%d ",array[i]);
        }
        i++;
    }
    printf("\n");
    
    printf("Even numbers were: ");
    i = 0;
    while(i < argc - 1){
        if(array[i] % 2 == 0){
            printf("%d ",array[i]);
        }
        i++;
    }
    printf("\n");

    return 0;

}
