// Frank Wang and Matthew Tran
// 02/04/2017
// Caesar Cipher

#include <stdio.h>
#include <stdlib.h>
// Declare the function
int shifted(int shift,int input);


int main(int argc, char *argv[]) {
    // read in the command line argument    
    int shift = 0;
    shift = atoi(argv[1]);
    
    int c = 0;
    c = getchar();
    // use function for output
    while(c >= 0 && c <= 127){
        putchar(shifted(shift,c));
        c = getchar();
    }

    return 0;

}

// the function to output the encrypted text
int shifted(int shift,int input){
    int output = 0;
    if(input >= 'A' && input <= 'Z'){        
        // deal with upper case
        // first, change the shift to a positive integer if it's not
        while(shift < 0){
            shift = shift + 26;
        } 
        // determine the shift needed (within the limit)               
        output = (shift + input-'A') % 26 + 'A';
                  
    } else if(input >= 'a' && input <= 'z'){
        // deal with lower case
        // the same way as above
        while(shift < 0){
            shift = shift + 26;
        }
        output = (shift + input-'a') % 26 + 'a';

    } else {
        // make no changes to non-letter input
        output = input;
    }
    return output;
}
