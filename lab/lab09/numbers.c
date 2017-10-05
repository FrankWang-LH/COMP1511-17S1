// Frank Wang and Matthew Tran
// 01/05/2017
// Read in and create files 

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    // read the first two arguments
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    // create a new file with the name of argument 3
    FILE *fp;
    fp = fopen(argv[3], "w");
    // error message
    if (fp == NULL) {
       printf("Failure : No Argument 3\n");
        return 1;
    }

    // now write in the numbers 
    int i = num1;
    int k;
    while(i <= num2){
        k = i;
        fprintf(fp,"%d\n",k);
        i = i + 1;
    }
    // close the file
    fclose(fp);

    return 0;

}
        






