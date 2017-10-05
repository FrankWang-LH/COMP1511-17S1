// 19.04.2017
// Frank Wang 
// Calculate the vertical balance of the image

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

double get_vertical_balance(int height, int width, int pixels[height][width]){

    int i = height - 1;
    int j = 0;
    double v_balance = 0.0;
    int row_sum = 0;
    int n_black_pixels = 0;

    while(j < width){
        // Start from [i][0]
        i = height - 1;

        // Calculate the sum
        while(i >= 0){
            // Calculate the row sum
            row_sum = i * pixels[i][j] + row_sum;
            if(pixels[i][j] == 1){
                // Calculate the number of black pixels
                n_black_pixels = n_black_pixels + 1;    
            } 
            i = i - 1;
        }
        j = j + 1;
    }

    // Determine the balance
    v_balance = (1.0 * row_sum/ n_black_pixels + 0.5)/height;

    return v_balance;

}



