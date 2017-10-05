// 16.04.2017
// Frank Wang 
// Crack bpm images - changed from test_horizontal_balance.c

#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) {
    int height, width, start_row, start_column, box_width, box_height;
    double horBalance = 0;
    double verBalance = 0;
    double density = 0;
    double tallness = 0;
    int number = 0;
    int conditions = 0;
    int half = 0;
    int noHole = 0;
    int oneSeven = 0;
    int twoFive = 0;

    // first read pbm files
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }

    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) {
        get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);

        int box_pixels[box_height][box_width];
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels);


        // now, operate calculation functions
        horBalance = get_horizontal_balance(box_height, box_width, box_pixels);

        verBalance = get_vertical_balance(box_height, box_width,box_pixels);

        number = holes(box_height,box_width,box_pixels);
        
        conditions = condition(box_height,box_width,box_pixels);
    
        noHole = noHoles(box_height,box_width,box_pixels);
        
        oneSeven = oneSev(box_height, box_width, box_pixels, noHole);

        twoFive = tfive(box_height,box_width,box_pixels);

        //printf("number %d\n",number);
        // judgement
        // first for digit with holes
        if(number == 2){
            printf("8\n");
        } else if(number == 1){
            if(conditions == 1){
                printf("0\n");
            } else if(conditions == 4){
                printf("4\n");
            } else if(conditions == 6){
                printf("6\n");
            } else if(conditions == 9){
                printf("9\n");
            } else {
                printf("0\n");
            } 
        // then 1 and 7, and then 2,3,5
        } else {
            if(noHole == 1){
                if(verBalance >= 0.519 && oneSeven == 7){
                    printf("7\n");
                } else if(oneSeven == 1){
                    printf("1\n");
                } else {
                    printf("1\n");
                }
            } else if(noHole == 2){
                if(twoFive == 3){
                    printf("3\n");
                } else if(twoFive == 2){
                    printf("2\n");
                } else if(twoFive == 5){
                    printf("5\n");
                } else {
                    printf("3\n");
                }
            }
        }

    }
    

    return 0;
}






