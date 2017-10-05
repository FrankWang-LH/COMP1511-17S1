// main function to output the number of arkles and farnarkles

#include <stdio.h>
#include "farnarkle.h"

int main(void) {
    int hidden_sequence[N_TILES];
    int guess[N_TILES];

    // deal with faulty sequence
    printf("Enter hidden sequence: ");
    if (read_tiles(hidden_sequence) != 1) {
        printf("Could not read hidden sequence\n");
        return 1;
    }
    printf("Enter guess: ");
    if (read_tiles(guess) != 1) {
        printf("Could not read guess\n");
        return 1;
    }

    // print the result
    printf("%d farnarkles\n", count_farnarkles(hidden_sequence, guess));
    printf("%d arkles\n",count_arkles(hidden_sequence, guess));

    return 0;
}





