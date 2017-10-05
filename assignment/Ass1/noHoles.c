// 27/04/2017
// Frank Wang
// Determine rest numbers

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

int noHoles(int height, int width, int config[height][width]){

    int i = 0;
    int j = 0;
    int number = 0;
    int bound[10];
    int pixels[height][width];

    i = 0;
    while(i < 10){
        bound[i] = 0;
        i = i + 1;
    }

    i = height - 1;
    while(i >= 0){
        j = 0;
        while(j < width){
            pixels[i][j]=config[i][j];
            j = j + 1;
        }
        i = i - 1;
    }

    i = height - 1;
    
    int store[width][20];
    j = 0;
    while(j < width){
        i = 0;
        while(i < 20){
          store[j][i] = 0;
          i = i + 1;
        }
        j = j + 1;
    }
    int k = 0;
    int a = 0;
    i = 0;
    j = 0;
    while(j < width){
        i = 0;
        if(pixels[height - 1][j] == 1){
            store[j][i] = height - 1;
            i = i + 1;
        }
        k = height - 2;
        while(k > 0){
            if(pixels[k][j] == 1 && pixels[k+1][j] != 1){
                store[j][i] = k;
                i = i + 1; 
            }
            k = k - 1;
        }
        j = j + 1;
    }

    //i = 0;
    //j = 0;
    //while(j < width){
    //    printf("col[%d] ",j);
    //    i = 0;
    //    while(i < 20 && store[j][i] != 0){
    //        printf("%d ",store[j][i]);
    //        i = i + 1;
    //    }
    //    printf("\n");
    //    j = j + 1;
    //}
  
    int cont = 0;  
    int count[width];
    i = 0;
    while(i < width){
        count[i] = 0;
        i = i + 1;
    }

    i = 0;
    j = 0;
    while(j < width){
        i = 0;
        while(i < 20){
            if(store[j][i] != 0){
                count[j] = count[j] + 1;
            }
            i = i + 1;
        }
        j = j + 1;
    }

    // minimize error
    j = 0;
    k = 0;
    while(j < width){
        if(count[j] == 3){
            k = k + 1;
        }
        j = j + 1;
    }

    //printf("%d\n",k);
    
    if(k <= 3){
        j = 0;
        while(j < width){
            if(count[j] == 3){
                count[j] = 2;
            }
            j = j + 1;
        }
    }   

    // now determine cases 
    j = 0;
    while(j < width){
        if(cont < count[j]){
            cont = count[j];
        }
        j = j + 1;
    }

    //printf("cont %d\n",cont);

    if(cont == 2){
        number = 1;
    } else if(cont >= 3){
        number = 2;
    } else {
        number = 1;
    }

    //printf("%d\n",number);
    return number;

}
