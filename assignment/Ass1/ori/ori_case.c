// 19/04/2017
// Determine closed area
#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"
int condition(int height, int width, int pixels[height][width]){
    int store[height][10];
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;
    int n = 0;
    // initialize array
    while(i < height){
        j = 0;
        while(j < 10){
            store[i][j] = 0;
            j = j + 1;
        }
        i = i + 1;
    }
    // find out the boudaries of '1' zones and store data
    j = 1;
    i = height - 2;
    while(j < width - 1){
        if(pixels[i][j] == 1 && pixels[i][j-1] == 0){
            store[i][k] = j;
            k = k + 1;
        } else if(pixels[i][j] == 1 && pixels[i][j+1] == 0){
            store[i][k] = j;
            k = k + 1;
        }
        j = j + 1;
    }
    i = i - 1;
    while(i > 0){
        j = 1;
        k = 0;
        while(j < width - 1){
            if(pixels[i][j] == 1 && pixels[i][j-1] == 0){
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
    // determine the case of the number
    int conditions = 0; // variable for case
    k = 0;
    i = 0;

    // case 1 : maximum 2 '1' zones a line and either no circle or being 0
    i = height - 2;
    k = 0;
    m = 0;
    int cont = 1;
    int start = 0;
    int end = height;
    
    while(i > 0){
        j = 0;
        if(store[i][0] != 0 && store[i-1][2] != 0){
            if(i > start){
                start = i;
            }
            while(store[i][2*j] != 0){
                m = 0;
                k = store[i-1][2*j];
                while(k <= store[i-1][2*j+1] && k >= store[i-1][2*j] && m == 0){
                    if(k >= store[i][2*j] && k <= store[i][2*j+1] && k <= store[i-1][2*j+1] && k >= store[i-1][2*j]){
                        m = 1;
                        cont = cont + 1;
                    }
                    k = k + 1;
                }        
                j = j + 1;     
            }   
            i = i - 1;
        } else if(store[i][0] != 0 && store[i + 1][2] != 0){
            if(i < end){
                end = i;
            }
            while(store[i][2*j] != 0){
                m = 0;
                k = store[i-1][2*j];
                while(k <= store[i-1][2*j+1] && k >= store[i-1][2*j] && m == 0){
                    if(k >= store[i][2*j] && k <= store[i][2*j+1] && k <= store[i-1][2*j+1] && k >= store[i-1][2*j]){
                        m = 1;
                        cont = cont + 1;
                    }
                    k = k + 1;
                }        
                j = j + 1;     
            }   
            i = i - 1;
        } else {
            i = i - 1;
        }
    }
    //printf("cont%d start%d end%d\n",cont,start,end);
    
    if(cont == (start-end) * 2){
        //printf("success, 1 circle\n");
        conditions = 1;
    } else {
        // case 2 : 1 circle, and 2 circles; '6''9''8'
        i = height - 2;
        k = 0;
        m = 0;
        while(i > 0){
            if(store[i][2] != 0 && store[i-1][2] == 0 && store[i-1][0] != 0 && m == 0){
                //printf("%d\n",i);
                k = i - 1;
                while(store[k][0] != 0 && k >= 0 && m == 0){
                    if(store[k][0] <= width/2 && store[k][1] <= width/2){
                        conditions = 2;
                        m = 1;
                    } else if(store[k][0] >= width/2 && store[k][1] >= width/2){
                        conditions = 3;
                        m = 1;
                    } else {
                        conditions = 4;
                        m = 1;
                    }

                    k = k - 1;
                }
            }
            i = i - 1;
        }

}
                        //printf("%d\n",conditions);
    return conditions;
}
