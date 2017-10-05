// Frank Wang and Matthew Tran
// 03/04/2017
// Susbstitution Cipher

#include <stdio.h>
#include <stdlib.h>

char subs(char cipher[],char input);

int main(int argc, char *argv[]) {
    // input the 1st letter
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
    char output;
    // handle upper case and lower case separately
    if(input >= 'A' && input <= 'Z'){
        // upper case comes first, so we need subtraction to output them        
        output = cipher[input-'A'] - ('a'-'A');          
    } else if(input >= 'a' && input <= 'z'){
        // the cipher is in lower case, so direct output
        output = cipher[input-'a'];
    } else {
        // other character remain unchanged
        output = input;
    }


    return output;

}
        






