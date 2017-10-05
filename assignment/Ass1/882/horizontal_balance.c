// 09.04.2017
// Frank Wang and Matthew Tran
// Calculate the horizontal balance of the image

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

double get_horizontal_balance(int height, int width, int pixels[height][width]){

    int i = height - 1;
    int j = 0;
    double h_balance = 0.0;
    int col_sum = 0;
    int n_black_pixels = 0;

    while(i >= 0){
        // Start from [i][0]
        j = 0;

        // Calculate the sum
        while(j < width){
            // Calculate the column sum
            col_sum = j * pixels[i][j] + col_sum;
            if(pixels[i][j] == 1){
                // Calculate the number of black pixels
                n_black_pixels = n_black_pixels + 1;    
            } 
            j = j + 1;
        }
        i = i - 1;
    }

    // Determine the balance
    h_balance = (1.0 * col_sum/ n_black_pixels + 0.5)/width;

    return h_balance;

}



