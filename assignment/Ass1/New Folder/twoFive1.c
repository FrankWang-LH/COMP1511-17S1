// 27/04/2017
// Frank Wang
// Determine rest numbers
#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"
int tfive(int height, int width, int pixels[height][width]){
    int i = 0;
    int j = 0;
    int number = 0;
    int bound[10];
    i = 0;
    while(i < 10){
        bound[i] = 0;
        i = i + 1;
    }
    i = width*3/5;
    j = height - 1;
    int k = 0;
    int a = 0;
    while(j >= 0){
        if(j == height - 1 && pixels[j][i] == 1){
            bound[k] = j;     
            k = k + 1;
        } else if (j != height - 1 && pixels[j][i] == 1 && pixels[j+1][i] != 1){
            bound[k] = j;     
            k = k + 1;
        } else if (j > 0 && pixels[j][i] == 1 && pixels [j-1][i] == 0){
            bound[k] = j;     
            k = k + 1;
        } else if (j == 0 && pixels[j][i] == 1 && pixels[j+1][i] == 1){
            bound[k] = j;     
            k = k + 1;
        }
        j = j - 1;
    }
    int cont = 0;
    k = 0;
    while(k < 10 && bound[k] != 0){
        //printf("bound %d line %d \n",k,bound[k]);
        cont = cont + 1;
        k = k + 1;
    }
    
    //printf("cont %d\n",cont);
    if(cont >= 5 && (bound[1]-bound[2]) < 10){
        number = 5;
    } else if(cont >= 5 && (bound[1]-bound[2]) > 10){
        number = 2;
    } else if(cont == 4 && (bound[0]-bound[1]) > 10){
        number = 5;
    } else if(cont == 4 && (bound[0]-bound[1]) < 10){
        number = 7;
    } else if(cont == 4){
        number = 2;
    } 
    //printf("twofive %d\n",number);
    return number;
}
