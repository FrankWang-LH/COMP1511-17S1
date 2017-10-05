// 09.04.2017
// Frank Wang 
// Calculate the density inside the bounding box

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

double find_tallness(int height, int width, int pixels[height][width]){

    int i = height - 1;
    int j = 0;
    double tallness = 0.0;

    // Determine the tallness
    tallness = 1.0 * (1.0 * height)/(width);

    return tallness;

}



