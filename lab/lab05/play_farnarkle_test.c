// Play Farnarkles
// Frank Wang and Matthew Tran
// 26/03/2017

#include <stdio.h>
#include "farnarkle.h"

int main(void) {
    int hidden_sequence[N_TILES];
    int guess[N_TILES];

    // create random tiles to guess
    create_random_tiles(hidden_sequence);
    
    // guess it by keep trying
    int i = 1;

    while (count_farnarkles(hidden_sequence, guess) != N_TILES){
        printf("Enter guess for turn %d: ", i);
        
        read_tiles(guess);    

        // print the results
        printf("%d farnarkles ", count_farnarkles(hidden_sequence, guess));
        printf("%d arkles\n", count_arkles(hidden_sequence, guess));

        i = i + 1;
    }
    
    //print the end message
    printf("You win \n");

    return 0;
}











