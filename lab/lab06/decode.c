// Frank Wang and Matthew Tran
// 03/04/2017
// Susbstitution Cipher Decode 

#include <stdio.h>
#include <stdlib.h>

char subs(char cipher[],char input);

int main(int argc, char *argv[]) {

    char c = getchar();
    int i = 0;

    // use function for output
    while(c >= 0 && c <= 127){
        putchar(subs(argv[1],c));
        c = getchar();
        i = i + 1;
    }

    return 0;

}

char subs(char cipher[],char input){
    int i = 0;
    int j = 0;
    char output;
        // decode, still handle in three cases
        if(input >= 'A' && input <= 'Z'){
            // for upper case, put the input back to the output of subs
            // then compare, and output original
            while(i < 26){
                if(cipher[i] == input + 32){
                    output = i + 'A';
                }        
            i = i + 1;
            }
        } else if(input >= 'a' && input <= 'z'){
            // decode lower case in the same way
            while(j < 26){
                if(cipher[j] == input){
                    output = j + 'a';
                }
            j = j + 1;
            }
        } else {
            // nothing changed for other characters
            output = input;
        }


    return output;

}
        






