// 09.04.2017
// Frank Wang and Matthew Tran
// Print bpm images

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

void print_image(int height, int width, int pixels[height][width]){

    // Print from the top of image (e.g. row 19 of a 20-row image)
    int i = height - 1;
    int j = 0;

    while(i >= 0){
        // Start from [i][0]
        j = 0;

        while(j < width){
            // Print image
            if(pixels[i][j] == 0){
                printf(".");
            } else {
                printf("*");
            }
            j = j + 1;
        }
        // Change line after one line is completed
        printf("\n");
        i = i - 1;
    }



}
