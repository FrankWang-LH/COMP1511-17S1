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


    i = height - 1;
    while(i >= 0){
        j = 0;
        while(j < width){
            pixels[i][j]=config[i][j];
            j = j + 1;
        }
        i = i - 1;
    }

    i = 0;
    // initialize array
    while(i < height){
        j = 0;
        while(j < 20){
            store[i][j] = 0;
            j = j + 1;
        }
        i = i + 1;
    }


    // find out the boudaries of '1' zones and store data
    j = 0;
    i = height - 1;
    k = 0;

    while(i >= 0){
        j = 0;
        k = 0;
        while(j < width){
            if(j == width - 1 && pixels[i][j] == 1){
                store[i][k] = j;
                k = k + 1;
            } else if(j != 0){
                if(pixels[i][j] == 1 && pixels[i][j+1] == 0 && pixels[i][j-1] == 0){
                    store[i][k] = j;
                    store[i][k+1] = j;
                    k = k + 2;
                } else if(pixels[i][j] == 1 && pixels[i][j-1] == 0){
                    store[i][k] = j;
                    k = k + 1;
                } else if(pixels[i][j] == 1 && pixels[i][j+1] == 0){
                    store[i][k] = j;
                    k = k + 1;
                }
            } else if(j == 0 && pixels[i][j] == 1){
                store[i][k] = j;
                k = k + 1;
            }
            j = j + 1;
        }
        i = i - 1;
    } 
    // finish of store boundary

    i = height - 5;
    while(i >= 0){
        j = 0;
        //printf("line %d ",i);
        while(j < 8){
            //printf("%d ",store[i][j]);
            j = j + 1;
        }
        //printf("\n");
        i = i - 1;
    }

    // find out upper part on the left for 5
    i = height - 5;
    while(i >= height/2){
        if(store[i][1] != 0 && store[i][2] == 0){
            if(store[i][0] < width/2 && store[i][1] <= width * 3/5){
                number = 5;
            }
        }
        i = i - 1;
    }
    // while for 2 the upper part is on the right
    i = height*3/4;
    while(i >= height/2){
        if(store[i][1] != 0 && store[i][2] == 0){
            if(store[i][0] > width/2 && store[i][1] >= width * 3/5){
                number = 2;
            }
        }
        i = i - 1;
    }

    return number;
}
