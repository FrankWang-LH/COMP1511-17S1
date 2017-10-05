// Count the number of arkles
// Frank Wang and Matthew Tran
// 26/03/2017

#include <stdio.h>
#include "farnarkle.h"

// return number of arkles
int count_arkles(int sequence1[N_TILES], int sequence2[N_TILES]) {

    int a = 0;
    int sequence3[N_TILES];
    int sequence4[N_TILES];

    // initialize the sequence to be judged
    while(a < N_TILES){
        sequence3[a]=sequence1[a];
        sequence4[a]=sequence2[a];
        a = a + 1;
    }    

    // remove the farnarkles
    int i = 0;
    int j = 0;
    int k = 0;
    int num = 0;


    while(i < N_TILES){
        while(j < N_TILES){
            if (sequence3[j] == sequence4[j]){
                sequence3[j] = MAX_TILE + 11; 
                sequence4[j] = MAX_TILE + 12;               
            }
            j = j + 1;
        } 
        
        i = i + 1;
    }


    // find out arkles, and remove the values so that it's only counted once
    while(k < N_TILES){ 
        int m = 0;

        while(m < N_TILES){            
            if(sequence3[k] == sequence4[m]){            
                sequence3[k] = MAX_TILE + 7;
                sequence4[m] = MAX_TILE + 6;
                num = num + 1;
            
            }
        
            m = m + 1;
        }

        k = k + 1;

        }

    return num;
}











