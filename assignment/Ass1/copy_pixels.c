// 09.04.2017
// Frank Wang and Matthew Tran
// Copy Pixels to New Array

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]){

    // Copy the Content inside the box from the bottom
    int i = start_row;
    int j = start_column;
    // For the copy array
    int k = 0;
    int l = 0;

    // Start from the bottom
    while (i < start_row + copy_height){
        j = start_column;
        l = 0;
        while(j < start_column + copy_width){
            // Copy everything from the original array to the new one
            copy[k][l]=pixels[i][j];
            l = l + 1;
            j = j + 1;
        }

        k = k + 1;
        i = i + 1;

    }    


}
