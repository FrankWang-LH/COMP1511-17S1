// Frank Wang
// 17/04/2017
// horizontal scan for assessment 1

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h" 

void hor_scan(int height, int width, int pixels[height][width], int h_scan[height],int store[height][10]){

    int i = height - 1;
    int j = 0;
    int k = 0;
    int m = 0;
    int sum = 0;

    while(j < width){
        if(pixels[i][j] == 1 && pixels[i][j-1] != 0){
            *store[i][k] = i;
            *store[i][k+1] = j;
            k = k + 2;
        } else if(pixels[i][j] == 1 && pixels[i][j+1] != 0){
            *store[i][k] = i;
            *store[i][k+1] = j;
            k = k + 2;
            sum = sum + 1;
            *h_scan [m] = sum;
        }
        j = j + 1;
    }

    i = i - 1;
    while(i > 0){
        j = 0;
        k = 0;
        sum = 0;
        while(j < width){
            if(pixels[i][j] == 1 && pixels[i][j-1] == 0){
                *store[i][k] = i;
                *store[i][k+1] = j;
                k = k + 2;
            } else if(pixels[i][j] == 1 && pixels[i][j+1] == 0){
                *store[i][k] = i;
                *store[i][k+1] = j;
                k = k + 2;
                sum = sum + 1;
            }
            j = j + 1;
        }
    if(sum != *h_scan[m]){
        m = m + 1;
        *h_scan[m] = sum;
    }
    i = i - 1;
    } 

}
