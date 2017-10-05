// Frank Wang and Matthew Tran
// 01/05/2017
// Read, and print out the first 10 lines of a file

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 1024

int main(int argc, char *argv[]){

    FILE *f;
    char line[10];
    int i = 0;
    int number = 0;
    
    if(argv[2] == 0){
        f = fopen(argv[1],"r");
        if(f == NULL){
            printf("Can't open file!\n");
            return 1;
        }

        i = 0;
        while(i < 10){           
            if(fgets(line,MAX_LENGTH,f) != NULL){
                printf("%s",line);
            } else {
                break;
            }
            i = i + 1;
        }
    } else {
        f = fopen(argv[3],"r");
        if(f == NULL){
            printf("Can't open file!\n");
            return 1;
        }

        number = atoi(argv[2]);
        i = 1;
        while(i <= number){
            if(fgets(line,MAX_LENGTH,f) != NULL){
                printf("%s",line);
            } else {
                break;
            }
            i = i + 1;
        }
    }

    fclose(f);

    return 0;
}
