// Play Farnarkles
// Frank Wang and Matthew Tran
// 26/03/2017

#include <stdio.h>
#include "farnarkle.h"

int main(void) {
    int hidden_sequence[N_TILES];
    int guess[N_TILES] = {0};

    // create random tiles to guess
    create_random_tiles(hidden_sequence);
    
    // guess it by keep trying
    int i = 1;

    /*printf("Enter guess for turn %d: ", i);
    //initialize
    read_tiles(guess);

    //results for turn 1
    printf("%d farnarkles ", count_farnarkles(hidden_sequence, guess));
    printf("%d arkles\n", count_arkles(hidden_sequence, guess));
    i = i + 1;*/

    //results for turn 2+
    while (count_farnarkles(hidden_sequence, guess) != N_TILES){
        
        printf("Enter guess for turn %d: ", i);
        if (read_tiles(guess) != 1){
            printf("Could not read guess\n");
            return 1;
        }    

        // print the results
        printf("%d farnarkles ", count_farnarkles(hidden_sequence, guess));
        printf("%d arkles\n", count_arkles(hidden_sequence, guess));

        i = i + 1;
    }
    
    //print the end message
    printf("You win \n");

    return 0;
}











