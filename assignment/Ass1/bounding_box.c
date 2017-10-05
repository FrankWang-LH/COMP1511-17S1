// 09.04.2017
// Frank Wang and Matthew Tran
// Find out the boundary of an image

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

void get_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width) {

    // The array finished at [height-1]
    int i = height - 1;
    // Variables for boundary points
    // Put the end to 0, so that any number larger than 0 will replace its value
    int end_row = 0;
    int end_column = 0;
    // The opposite for start - we want the smallest number
    int start_rows = width;
    int start_columns = width;

    // Find out the start and end rows/columns
    while(i >= 0){
        int j = 0;
        while(j < width){
            if(pixels[i][j] == 1){
                if(j < start_columns){
                    start_columns = j;
                } else if(i < start_rows){
                    start_rows = i;
                } else if(i > end_row){
                    end_row = i;
                } else if(j > end_column){
                    end_column = j;
                }
            }
            j = j + 1;
        }
    i = i - 1;
    }

    // Assign value to the pointers
    *box_height = end_row - start_rows + 1;
    *box_width = end_column - start_columns + 1;
    *start_row = start_rows;
    *start_column = start_columns;

}



