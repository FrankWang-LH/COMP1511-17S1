// Frank Wang
// Crack Captcha
// 28/04/2017

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

int main(int argc, char *argv[]) {
    int height, width;
    int start_row = 0;
    int start_column = 0; 
    int box_width = 0;
    int box_height = 0;
    double hor_balance = 0;
    double ver_balance = 0;
    int number = 0;
    int conditions = 0;
    int half = 0;
    int noHole = 0;
    int oneSeven = 0;
    int twoFive = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }

    // this code is operating crack digit for 4 times to get a captcha
    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) {

        int pixelsA[height][width/4];
        int pixelsB[height][width/4];
        int pixelsC[height][width/4];
        int pixelsD[height][width/4]; 

        // 1ST BOX
        start_row = 0;
        start_column = 0;
        box_height = height;
        box_width = width/4;
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, pixelsA);


        start_row = 0;
        start_column = 0; 
        box_width = 0;
        box_height = 0;
        hor_balance = 0;
        ver_balance = 0;
        number = 0;
        conditions = 0;
        half = 0;
        noHole = 0;
        oneSeven = 0;
        twoFive = 0;
        // same as crack digit
        get_bounding_box(height, width/4, pixelsA, &start_row, &start_column, &box_height, &box_width);

        int box_pixelsA[box_height][box_width];
        copy_pixels(height, width/4, pixelsA, start_row, start_column, box_height, box_width, box_pixelsA);

        hor_balance = get_horizontal_balance(box_height, box_width, box_pixelsA);

        ver_balance = get_vertical_balance(box_height, box_width,box_pixelsA);

        number = holes(box_height,box_width,box_pixelsA);
        
        conditions = condition(box_height,box_width,pixelsA);        
    
        noHole = noHoles(box_height,box_width,box_pixelsA);
        
        oneSeven = oneSev(box_height, box_width, box_pixelsA, noHole);

        twoFive = tfive(box_height,box_width,box_pixelsA);

        // judgement
        // first for digit with holes
        if(number == 2){
            printf("8");
        } else if(number == 1){
            if(conditions == 1){
                printf("0");
            } else if(conditions == 4){
                printf("4");
            } else if(conditions == 6){
                printf("6");
            } else if(conditions == 9){
                printf("9");
            } else {
                printf("0");
            } 
        // then 1 and 7, and then 2,3,5
        } else {
            if(noHole == 1){
                if(ver_balance >= 0.519 && oneSeven == 7){
                    printf("7");
                } else if(oneSeven == 1){
                    printf("1");
                } else {
                    printf("1");
                }
            } else if(noHole == 2){
                if(twoFive == 3){
                    printf("3");
                } else if(twoFive == 2){
                    printf("2");
                } else if(twoFive == 5){
                    printf("5");
                } else {
                    printf("2");
                }
            }
        }
        // FINISH BOX

        // 2ND BOX
        start_row = 0;
        start_column = width/4;
        box_height = height;
        box_width = width/4;
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, pixelsB);

        start_row = 0;
        start_column = 0; 
        box_width = 0;
        box_height = 0;
        hor_balance = 0;
        ver_balance = 0;
        number = 0;
        conditions = 0;
        half = 0;
        noHole = 0;
        oneSeven = 0;
        twoFive = 0;
        // same as crack digit
        get_bounding_box(height, width/4, pixelsB, &start_row, &start_column, &box_height, &box_width);

        int box_pixelsB[box_height][box_width];
        copy_pixels(height, width/4, pixelsB, start_row, start_column, box_height, box_width, box_pixelsB);

        hor_balance = get_horizontal_balance(box_height, box_width, box_pixelsB);

        ver_balance = get_vertical_balance(box_height, box_width,box_pixelsB);

        number = holes(box_height,box_width,box_pixelsB);
        
        conditions = condition(box_height,box_width,pixelsB);
            
        noHole = noHoles(box_height,box_width,box_pixelsB);
        
        oneSeven = oneSev(box_height, box_width, box_pixelsB, noHole);

        twoFive = tfive(box_height,box_width,box_pixelsB);

        // judgement
        // first for digit with holes
        if(number == 2){
            printf("8");
        } else if(number == 1){
            if(conditions == 1){
                printf("0");
            } else if(conditions == 4){
                printf("4");
            } else if(conditions == 6){
                printf("6");
            } else if(conditions == 9){
                printf("9");
            } else {
                printf("0");
            } 
        // then 1 and 7, and then 2,3,5
        } else {
            if(noHole == 1){
                if(ver_balance >= 0.519 && oneSeven == 7){
                    printf("7");
                } else if(oneSeven == 1){
                    printf("1");
                } else {
                    printf("1");
                }
            } else if(noHole == 2){
                if(twoFive == 3){
                    printf("3");
                } else if(twoFive == 2){
                    printf("2");
                } else if(twoFive == 5){
                    printf("5");
                } else {
                    printf("2");
                }
            }
        }
        // FINISH BOX
        
        // 3RD BOX
        start_row = 0;
        start_column = width/2;
        box_height = height;
        box_width = width/4;
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, pixelsC);

        start_row = 0;
        start_column = 0; 
        box_width = 0;
        box_height = 0;
        hor_balance = 0;
        ver_balance = 0;
        number = 0;
        conditions = 0;
        half = 0;
        noHole = 0;
        oneSeven = 0;
        twoFive = 0;

        // same as crack digit
        get_bounding_box(height, width/4, pixelsC, &start_row, &start_column, &box_height, &box_width);

        int box_pixelsC[box_height][box_width];
        copy_pixels(height, width/4, pixelsC, start_row, start_column, box_height, box_width, box_pixelsC);

        hor_balance = get_horizontal_balance(box_height, box_width, box_pixelsC);

        ver_balance = get_vertical_balance(box_height, box_width,box_pixelsC);

        number = holes(box_height,box_width,box_pixelsC);
        
        conditions = condition(box_height,box_width,pixelsC);
    
        noHole = noHoles(box_height,box_width,box_pixelsC);
        
        oneSeven = oneSev(box_height, box_width, box_pixelsC, noHole);

        twoFive = tfive(box_height,box_width,box_pixelsC);

        // judgement
        // first for digit with holes
        if(number == 2){
            printf("8");
        } else if(number == 1){
            if(conditions == 1){
                printf("0");
            } else if(conditions == 4){
                printf("4");
            } else if(conditions == 6){
                printf("6");
            } else if(conditions == 9){
                printf("9");
            } else {
                printf("0");
            } 
        // then 1 and 7, and then 2,3,5
        } else {
            if(noHole == 1){
                if(ver_balance >= 0.519 && oneSeven == 7){
                    printf("7");
                } else if(oneSeven == 1){
                    printf("1");
                } else {
                    printf("1");
                }
            } else if(noHole == 2){
                if(twoFive == 3){
                    printf("3");
                } else if(twoFive == 2){
                    printf("2");
                } else if(twoFive == 5){
                    printf("5");
                } else {
                    printf("2");
                }
            }
        }
        // FINISH BOX

        // 4TH BOX
        start_row = 0;
        start_column = width*3/4;
        box_height = height;
        box_width = width/4;
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, pixelsD);

        start_row = 0;
        start_column = 0; 
        box_width = 0;
        box_height = 0;
        hor_balance = 0;
        ver_balance = 0;
        number = 0;
        conditions = 0;
        half = 0;
        noHole = 0;
        oneSeven = 0;
        twoFive = 0;

        // same as crack digit
        get_bounding_box(height, width/4, pixelsD, &start_row, &start_column, &box_height, &box_width);

        int box_pixelsD[box_height][box_width]; 
        copy_pixels(height, width/4, pixelsD, start_row, start_column, box_height, box_width, box_pixelsD);

        hor_balance = get_horizontal_balance(box_height, box_width, box_pixelsD);

        ver_balance = get_vertical_balance(box_height, box_width,box_pixelsD);

        number = holes(box_height,box_width,box_pixelsD);
        
        conditions = condition(box_height,box_width,pixelsD);
    
        noHole = noHoles(box_height,box_width,box_pixelsD);
        
        oneSeven = oneSev(box_height, box_width, box_pixelsD, noHole);

        twoFive = tfive(box_height,box_width,box_pixelsD);

        // judgement
        // first for digit with holes
        if(number == 2){
            printf("8");
        } else if(number == 1){
            if(conditions == 1){
                printf("0");
            } else if(conditions == 4){
                printf("4");
            } else if(conditions == 6){
                printf("6");
            } else if(conditions == 9){
                printf("9");
            } else {
                printf("0");
            } 
        // then 1 and 7, and then 2,3,5
        } else {
            if(noHole == 1){
                if(ver_balance >= 0.519 && oneSeven == 7){
                    printf("7");
                } else if(oneSeven == 1){
                    printf("1");
                } else {
                    printf("1");
                }
            } else if(noHole == 2){
                if(twoFive == 3){
                    printf("3");
                } else if(twoFive == 2){
                    printf("2");
                } else if(twoFive == 5){
                    printf("5");
                } else {
                    printf("2");
                }
            }
        }
        // FINISH BOX
        
        printf("\n");
    }
    
    return 0;
}



