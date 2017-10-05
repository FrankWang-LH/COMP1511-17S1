// Frank Wang and Matthew Tran
// 02/04/2017
// Remove the vowel from a Sentence

#include <stdio.h>

int main (void) {

    int c=0;
    c = getchar(); 

    // for ASCII input
    while (c >= 0 && c <= 127) {//c != EOF

        // remove the vowel and output
        if (c != 'a' && c != 'e' && c!= 'i' && c != 'o' && c != 'u'){
            putchar(c);
        }
        c = getchar();
    }


    return 0;
}

