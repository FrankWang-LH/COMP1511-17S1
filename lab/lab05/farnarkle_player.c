#include <stdio.h>
#include "farnarkle.h"

// an automated farnarkle_player
// given all previous guesses and their farnarkles and arkle counts
// make a new guess
//
// inputs:
// turn - which turn this is
// previous_guesses contains the turn - 1 previous_guesses
// farnarkles[i] contains the number of farnarkles for previous_guess[i]
// arkles[i] contains the number of arkles for previous_guess[i]
//
// output:
// guess - the next guess

void farnarkle_player(int turn, int previous_guesses[MAX_TURNS][N_TILES], int farnarkles[MAX_TURNS], int arkles[MAX_TURNS], int guess[MAX_TILE]) {
    int i = 0;
    turn = turn;
    int possible[N_TILES];
    int not_possible[N_TILES];
    int final[N_TILES];

    if (farnarkles[i] == 0 && possible[N_TILES] == 0){
        int j = 0;
        while (j < farnarkles[i]){
            possible[i-1]= i - 1;  
            j=j+1;
        }    
        while (i < MAX_TILE) {
            int k = 0;       
            while (k < N_TILES){
                guess[k]=i+1;
                k=k+1;
            }
            previous_guesses[i][i]=turn;
            previous guesses[i][i]=guess[i];
            turn = turn + 1;
            i=i+1;
    
        }   
    } else if(farnarkles[i] != 0 && possible[N_TILES] == 0){
        int j = 0;
        int n = 0;
        while (n < farnarkles[i]){
            if(possible[j]==0){            
                while(n < farnarkles[i]){                
                possible[j]= i - 1;  
                j=j+1;
                n=n+1;
            } else {
                j=j+1;
            }
        }
        while (i < MAX_TILE) {
            int k = 0;       
            while (k < N_TILES){
                guess[k]=i+1;
                k=k+1;
            }
        previous_guesses[i][i]=turn;
        previous guesses[i][i]=guess[i];
        turn = turn + 1;
        i=i+1;

        }
    } else if (possible[N_TILES] != 0 && farnarkle[i] == 0){
        int l = 0;
        while (l < N_TILES){
            int m = 0;
            int p = l;                
            while (m < N_TILES){ 
                if (p = m) {
                    guess[m]=possible[l];
                } else {
                    guess[m]=impossible[0];
                }
                m=m+1;
            }
        previous_guesses[i][i]=turn;
        previous guesses[i][i]=guess[i];
        turn = turn + 1;
        l = l + 1;
    } else if (possible[N_TILES] != 0 && farnarkle[i] != 0){
        int r=0;
        while(r < N_TILES){
            if(guess[r] == possible[r]){
                    final[r]=possible[r];
                    r = r + 1;
            }
        }
    } else {
        int s=0;
        while(s < N_TILES){
            guess[s]= final[s];
            s=s+1;
        }
    }
}
                        
            
            


    





