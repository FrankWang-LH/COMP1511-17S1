// Input and output for farnarkle
// Frank Wang and Matthew Tran
// 26/03/2017


#include <stdio.h>
#include "farnarkle.h"

// read N_TILES tiles into array tiles
// return 1 if successful, 0 otherwise
int read_tiles(int tiles[N_TILES]) {
    int i = 0;
    int j = 0;
    int k = 0;
    int num = 0;
    int scan = 0;
    int scanArray[N_TILES];

    while (i < N_TILES){
        scanArray[i] = scanf("%d", &tiles[i]);
                        
        i = i + 1; 
    }

    while (k < N_TILES){
        if(scanArray[k] == 1){
            scan = scan + 1;
        }
        k = k + 1;
    }

    if(scan == N_TILES){
        while (j < N_TILES){
            if (tiles[j] <= MAX_TILE && tiles[j] > 0){
                num = num + 1;
            } 
            j = j + 1;
        }
    
        if(num == N_TILES) {
            return 1;
        } 

        return 0;
    } else {
        return 0;
    }
    
}

// print tiles on a single line
void print_tiles(int tiles[N_TILES]) {
    int k = 0;
    
    while (k < N_TILES){
        printf("%d ", tiles[k]);
        k = k + 1;
    }

    
    printf("\n");

}

