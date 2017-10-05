// 09.04.2017
// Frank Wang 
// Calculate the density inside the bounding box

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

double find_density(int height, int width, int pixels[height][width]){

    int i = height - 1;
    int j = 0;
    double density = 0.0;
    int n_black_pixels = 0;

    while(i >= 0){
        // Start from [i][0]
        j = 0;

        // Calculate the sum
        while(j < width){
            if(pixels[i][j] == 1){
                // Calculate the number of black pixels
                n_black_pixels = n_black_pixels + 1;    
            } 
            j = j + 1;
        }
        i = i - 1;
    }

    // Determine the density
    density = 1.0 * (1.0 * n_black_pixels)/(width*height);

    return density;

}



