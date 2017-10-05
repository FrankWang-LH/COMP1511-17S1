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


// start changing
// changing all non-holes digits to 7
    i = height - 1;
    j = 0;
    m = 0;
    while(i >= 0){
        j = 0;
        if(store[i][0] != 0 && store[i][2] != 0 && store[i][4] == 0 && store[i][6] == 0 && store[i][8] == 0 && store[i][10] == 0){
                k = 0;
                while(k < width){
                    if(k < store[i][0] || k > store[i][3]){
                        pixels[i][k] = 7;
                    }
                    k = k + 1;
                }
                i = i - 1;
        } else if (store[i][4] != 0 && store[i][6] == 0 && store[i][8] == 0){
            // handle 0 with a point inside circle and some of the 4s
            k = 0;
            store[i][4] = store[i][1];
            store[1][2] = 0;
            store[1][3] = 0;
            store[1][4] = 0;            
            while(k < width){
                if(k < store[i][0] || k > store[i][5]){
                    pixels[i][k]=7;
                } 
                k = k + 1;
            }
            i = i - 1;
        } else if (store[i][6] != 0){
            // handle 0 with a point inside circle and some of the 4s
            k = 0;
            while(k < width){
                if(k < store[i][0] || k > store[i][7]){
                    pixels[i][k]=7;
                } 
                k = k + 1;
            }
            i = i - 1;
        } else {
            // everything out of the holes become 7
            j = 0;
            while(j < width){
                if(j <= store[i][0] || j >= store[i][1]){
                    pixels[i][j] = 7;
                }
                j = j + 1;
            }
            i = i - 1;
        }

    }


    // finally, remove 1
    i = height - 1;
    while(i >= 0){
        j = 0;
        while(j < width){
            if(pixels[i][j] == 1){
                pixels[i][j] = 7;
            }
            j = j + 1;
        }
        i = i - 1;
    }            
    // end of changing digits, after this holes remain "0",some non-hole zones may have small number of lines of 0, which helps with further determination
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

