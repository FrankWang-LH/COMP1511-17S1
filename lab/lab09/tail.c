// Frank Wang and Matthew Tran
// 01/05/2017
// Read, and print out the first 10 lines of a file

// sorry, this one is not working!
#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 1024

int main(int argc, char *argv[]){

    FILE *f;
    char line[10];
    char test[10];
    int i = 0;
    int number = 0;
    
    f = fopen(argv[1],"r");
    if(f == NULL){
        printf("Can't open file!\n");
        return 1;
    }

    i = 0;
    int k = 0;
    while(fgets(test,MAX_LENGTH,f) != NULL){           
        k = k + 1;
    }
    fclose(f);

    f = fopen(argv[1],"r");
    i = k - 10;
    while(i < k){           
        if(fgets(line,MAX_LENGTH,f) != NULL){
            printf("%s",line);
        } else {
            break;
        }
        i = i + 1;
    }

    fclose(f);

    return 0;
}
