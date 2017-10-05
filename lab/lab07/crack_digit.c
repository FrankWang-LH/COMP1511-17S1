// 09.04.2017
// Frank Wang and Matthew Tran
// Crack bpm images - changed from test_horizontal_balance.c

#include <stdio.h>
#include "captcha.h"

int main(int argc, char *argv[]) {
    int height, width, start_row, start_column, box_width, box_height;
    double balance;

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

        balance = get_horizontal_balance(box_height, box_width, box_pixels);
        // Decide 3 and 6 - the balance of 3 is on the right, while that of 6 is on the left
        if(balance > 0.5){
            printf("3");
        } else {
            printf("6");
        }
        printf("\n");
    }
    return 0;
}






