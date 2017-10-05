// Frank Wang
// 17/04/2017
// vertical scan for assessment 1

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h" 

void ver_scan(int height, int width, int pixels[height][width], int v_scan[width]){

    int i = height - 1;
    int j = 0;

    while(j < width){    
        v_scan[j] = 0;
        j = j + 1;
    }

    j = 0;
    while(j < width){
        i = height - 1;
        while(i > 0){
            if(pixels[i][j] == 1 && i != 0){
                if(pixels[i - 1][j] == 0){
                    v_scan[j] = v_scan[j] + 1;
                } 
            } else if (pixels[i][j] == 1 && i == 0){
                v_scan[j] = v_scan[j] + 1;
            }
            i = i - 1;
        }

    j = j + 1;
    } 



}
