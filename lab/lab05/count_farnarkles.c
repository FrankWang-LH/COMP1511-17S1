// Count farnarkles
// Frank Wang and Matthew Tran
// 26/03/2017

#include <stdio.h>
#include "farnarkle.h"

// return number of farnarkles
int count_farnarkles(int sequence1[N_TILES], int sequence2[N_TILES]) {
    
    int k = 0;
    int number = 0;

    while (k < N_TILES){
        if (sequence1[k] == sequence2[k]){
            number = number + 1;
        } 
        
        k = k + 1;
    } 

    return number;       
}
