// Frank Wang and Matthew Tran
// 01/05/2017
// Read a string and print it out

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 4096

int main(void){
    
    char line[MAX_LENGTH];

    printf("Enter a string: ");
    fgets(line, MAX_LENGTH, stdin);
    
    int i = 0;
    while(line[i] != '\n'){
        putchar(line[i]);
        printf("\n");
        i = i + 1;
    }

    return 0;
}
