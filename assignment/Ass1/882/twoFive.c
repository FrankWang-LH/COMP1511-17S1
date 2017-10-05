// 27/04/2017
// Frank Wang
// Determine 2 and 5
#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"
int tfive(int height, int width, int config[height][width]){

    int number = 0;
    int store[height][20];
    int pixels[height][width];
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int n = 0;
    int pixelsA[height/2][width];
    int pixelsB[height/2][width];
    int count[2] = {0,0};
    int left = 0;
    int right = 0;
    int start_row = 0;
    int start_column = 0;
    int box_height = 0;
    int box_width = 0;

    i = height - 1;
    while(i >= 0){
        j = 0;
        while(j < width){
            pixels[i][j]=config[i][j];
            j = j + 1;
        }
        i = i - 1;
    }


    // work out the number of ones for the upper and lower half(2/5 height each)
    // upper half
    start_row = height*4/7;
    start_column = 0;
    box_height = height*3/7;
    box_width = width;
    copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, pixelsA);

    start_row = 0;
    start_column = 0;
    box_height = 0;
    box_width = 0;
    get_bounding_box(height*3/7, width, pixelsA, &start_row, &start_column, &box_height, &box_width);

    int box_pixelsA[box_height][box_width];
    copy_pixels(height*3/7, width, pixelsA, start_row, start_column, box_height, box_width, box_pixelsA);
    i = box_height - 1;
    while(i >= 0){
        j = 0;
        while(j < box_width/2){
            if(box_pixelsA[i][j] == 1){
                left = left + 1;
            }
            j = j + 1;
        }
        i = i - 1;
    }
    
    i = box_height - 1;
    while(i >= 0){
        j = box_width/2;
        while(j < box_width){
            if(box_pixelsA[i][j] == 1){
                right = right + 1;
            }
            j = j + 1;
        }
        i = i - 1;
    }
    if(left >= right){
        count[0] = 1;// 1 indicates a heavier left part
    } else {
        count[0] = 2;// 2 indicates a heavier right part
    }
    // box 1 finished

    // lower half
    start_row = 0;
    start_column = 0;
    box_height = height*3/7;
    box_width = width;
    copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, pixelsB);

    start_row = 0;
    start_column = 0;
    box_height = 0;
    box_width = 0;
    left = 0;
    right = 0;
    get_bounding_box(height*3/7, width, pixelsB, &start_row, &start_column, &box_height, &box_width);

    int box_pixelsB[box_height][box_width];
    copy_pixels(height/2, width, pixelsB, start_row, start_column, box_height, box_width, box_pixelsB);
    i = box_height - 1;
    while(i >= 0){
        j = 0;
        while(j < box_width/2){
            if(box_pixelsB[i][j] == 1){
                left = left + 1;
            }
            j = j + 1;
        }
        i = i - 1;
    }
    
    i = box_height - 1;
    while(i >= 0){
        j = box_width/2;
        while(j < box_width){
            if(box_pixelsB[i][j] == 1){
                right = right + 1;
            }
            j = j + 1;
        }
        i = i - 1;
    }
    if(left >= right){
        count[1] = 1;
    } else {
        count[1] = 2;
    }
    // box 2 finished

    // determination
    if(count[0] == 1 && count[1] == 2){
        // 5 has a heavier left on the upper half while the lower is right
        number = 5;
    } else if(count[0] == 2 && count[1] == 1){
        // 2 is the opposite of 5
        number = 2;
    } else if(count[0] == 2 && count[1] == 2){
        // 3 is heavier on the right for both parts
        number = 3;
    } else {
        number = 5;
    }
    
    return number;
}
