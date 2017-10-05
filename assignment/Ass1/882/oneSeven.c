// 29/04/2017
// Frank Wang
// Determine 1 and 7

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

int oneSev(int height, int width, int config[height][width], int noHoles){

    int number = 0;

    if(noHoles == 1){

        height = height / 2;
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
                } else if(j == 0 && pixels[i][j] == 1){
                    store[i][k] = j;
                    k = k + 1;
                } else if(pixels[i][j] == 1 && pixels[i][j+1] == 0 && pixels[i][j-1] == 0){
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
                j = j + 1;
            }
            i = i - 1;
        } 

        // initialize array
        int cont = 0;  
        int count[height];
        i = 0;
        while(i < height){
            count[i] = 0;
            i = i + 1;
        }

        // find out number of boundaries for each row
        i = height - 1;
        j = 0;
        while(i >= 0){
            j = 0;
            while(j < 20){
                if(store[i][j] != 0){
                    count[i] = count[i] + 1;
                }
                j = j + 1;
            }
            i = i - 1;
        }
    

        // now determine cases 
        i = height - 1;
        while(i >= 0){
            if(cont < count[i]){
             cont = count[i];
            }
            i = i - 1;
        }

        if(cont > 2){
            number = 1;
        } else if(cont == 2){
            number = 7;
        } else {
            number = 1;
        }

    } else {
        number = 1;
    }

    return number;

}

