// Frank Wang and Matthew Tran
// 02/04/2017
// Caculate the frequency of letters from a sentence

#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int c = 0;
    int i = 0;
    int j = 0;
    double k = 0;
    int total = 0;
    double times[26];
    c = getchar(); 

    // initialise the array
    while(i < 26){
        times[i] = 0;
        i = i + 1;
    }
    

    while (c >= 0 && c <= 127) {
        // handle upper case letters
        if(c >= 'A' && c <= 'Z'){
            i = 0;
            while(i < 26){
                if(c == (i+'A')){
                    times[i] = times[i] + 1;
                } 
                i = i + 1;
            }
            total = total + 1;
        } else if(c >= 'a' && c <= 'z'){
            // handle lower case letters
            i = 0; 
            while(i < 26){
                if(c == (i+'a')){
                    times[i] = times[i] + 1;
                }
                i = i + 1;
            }
            total = total + 1;
        } 

        c = getchar();

    }

    i = 0;
    // print out results
    if(total != 0){
        while(i < 26){
            k = times[i] / total;
            // print out letters
            printf("'");        
            putchar(i + 'a');
            printf("'");
            // print out ratio
            printf(" %lf ",k);
            // print out times
            printf("%.0lf",times[i]);
            printf("\n");
               
            i=i+1;
        }
    } else {
        // deal with the condition when total = 0 (empty imput)
        while(i < 26){
            times[i] = 0;
            printf("'");        
            putchar(i + 'a');
            printf("'");        
            printf(" %lf ",times[i]);
            printf("%.0lf",times[i]);
            printf("\n");
               
            i=i+1;
        }
    }    

    return 0;
}
    
