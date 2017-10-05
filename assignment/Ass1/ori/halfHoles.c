// 27/04/2017
// Frank Wang
// Determine some 3s



#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

int threes(int height, int width, int config[height][width]){

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


    i = height - 1;
    j = 0;
    while(i >= 0){
        j = 1;
        if(store[i][0] != 0 && store[i][2] != 0 && store[i][4] == 0 && store[i+1][2] == 0 && store[i+1][0] != 0){
            if(store[i+1][0] < store[i][1] && store[i+1][1] > store[i][2]){            
                
                while(store[i][2] != 0){
                    k = 0;
                    while(k < width){
                        if(k <= store[i][1] || k >= store[i][2]){
                            pixels[i][k] = 7;
                        }
                        k = k + 1;
                    }
                    i = i - 1;
                }

            } else {
                while(store[i][2] != 0){
                    k = 0;
                    while(k < width){
                        if(k <= store[i][1] || k >= store[i][2]){
                            pixels[i][k] = 7;
                        }
                        k = k + 1;
                    }
                    i = i - 1;
                }
            }
        } else if (store[i][0] != 0 && store[i][2] == 0 && store[i + 1][4] == 0 && store[i+1][2] != 0 && store[i+1][0] != 0 && i < height/2){
            if(store[i][0] < store[i+1][1] && store[i][1] > store[i+1][2]){            
                m = i;

                while(store[m+1][2] != 0){
                    k = 0;
                    while(k < width){
                                               
                        k = k + 1;
                    }
                    m = m + 1;
                }
                i = i - 1;
            } else {
                m = i;
                while(store[m+1][2] != 0){
                    k = 0;
                    while(k < width){
                        pixels[m][k]=7;
                        k = k + 1;
                    }
                    m = m + 1;
                }
                i = i - 1;
            }
        } else if (store[i][4] != 0){
            k = 0;
            while(k < width){
                if(k <= store[i][1] || k >= store[i][4]){
                    pixels[i][k]=7;
                } else if(k >= store[i][2] && k <= store[i][3]){
                    pixels[i][k]=0;
                }
                k = k + 1;
            }
            i = i - 1;
        } else {
            while(j < width){
                pixels[i][j] = 7;
                j = j + 1;
            }
            i = i - 1;
        }

    }

    i = height - 1;
    while(i >= 0){
        if(store[i][2] == 0){
            k = 0;
            while(k < width){
                pixels[i][k] = 7;
                k = k + 1;            
            }
        }
        i = i - 1;
    }
// finish changing

     // The array finished at [height-1]
    i = height - 1;
    // Variables for boundary points
    // Put the start to 0, so that any number larger than 0 will replace its value(doing from the top to the bottom)
    int start_row = 0;
    // The opposite for end - we want the smallest number
    int end_row = width;

    // Find out the start and end rows/columns
    while(i >= 0){
        int j = 0;
        while(j < width){
            if(config[i][j] == 1){
                if(i < end_row){
                    end_row = i;
                } else if(i > start_row){
                    start_row = i;               
                }
            }
            j = j + 1;
        }
    i = i - 1;
    }

    //printf("start row %d, end row %d\n",start_row,end_row);
    // END OF FIND OUT MAX MINs




   // start of determination
    i = height - 1;
    j = 0;
    int cont = 1;
    int start = height;
    int end = 0;
    int startPre = 0;
    int endPre = 0;
    int count[height];
    int contPre = 0;
    
    while(i >= 0){
        count[i] = 0;
        i = i - 1;
    }

    i = height - 1;
    k = 0;
    while(i >= 0){
        j = 0;
        m = 0;
        while(j < width && m == 0){
            if(pixels[i][j] == 0){
                count[i] = 1;
                m = 1;
            }
            j = j + 1;
        }
        i = i - 1;
    }
     
    i = height - 1;
    while(i > 1){
        m = 0;
        cont = 0;
        while(m == 0){
            if(count[i] == 1){
                start = i;
                while(count[i-1] != 0){
                    cont = cont + 1;
                    i = i - 1;
                    end = i;
                }
                m = 1;        
            } else {
                i = i - 1;
                if(i == 1){
                    m = 1;
                }
            }     
        }

        if(cont > 3){
            //printf("%d cont\n",cont);
            number = number + 1;
        }
        
        i = i - 1;
    }

    int midzone = (startPre + endPre)/2;
    int midpic = (start_row + end_row)/2;
    //printf("midzone %d midpic %d\n",midzone,midpic);
    //printf("3 number %d\n",number);
    if(number == 2){
        number = 3;
    } else if(contPre != 0){
        if(midzone > midpic){
           number = 2;
       } else {
            number = 5;
       }
    }


    return number;
}

