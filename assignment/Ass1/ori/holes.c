// 24/04/2016
// Frank Wang
// Determine holes

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

int holes(int height, int width, int config[height][width]){

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
        while(j < width - 2){
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

    // ELIMINATE ERRORS
    i = height - 2;
    j = 0;
    m = 0;
    while(i > 0){
        if(store[i+1][0] == 0 && store[i][0] != 0 && store[i][2] != 0 && store[i+1][2] == 0){
            
            store[i][1] = store[i][3];
            j = 2;
            while(j < 10){
                store[i][j] = 0;
                j = j + 1;
            }
        } else if(store[i+1][0] != 0 && store[i][0] != 0 && store[i][2] != 0 && store[i+1][2] == 0 && store[i+1][1] == 0 && store[i-1][0] != 0 && store[i-1][2] == 0){
            store[i][1] = store[i][3];
            j = 2;
            while(j < 10){
                store[i][j] = 0;
                store[i-1][j] = 0;
                j = j + 1;
            }
        } else if(store[i][4] != 0 && store[i+1][2] == 0){
            store[i][1]=store[i][4];
            j = 2;
            while(j < 10){
                store[i][j] = 0;
                store[i-1][j] = 0;
                j = j + 1;
            }
        }
        i = i - 1;
    }

    // changing all non-holes digits to 7
    i = height - 1;
    j = 0;
    m = 0;
    while(i >= 0){
        j = 0;
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
        } else if (store[i][0] != 0 && store[i][2] == 0 && store[i + 1][4] == 0 && store[i+1][2] != 0 && store[i+1][0] != 0 && i >= height*3/7){
            // upper half, remove the half-closed area of 6 and 3
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
        } else if (store[i][0] != 0 && store[i][2] == 0 && store[i - 1][4] == 0 && store[i-1][2] != 0 && store[i-1][0] != 0){
            // lower half, remove half-closed zones for 9 and 3
            if(store[i][0] < store[i-1][1] && store[i][1] >= store[i-1][2]){            
                m = i;

                while(store[m-1][2] != 0){
                    k = 0;
                    while(k < width){
                                               
                        k = k + 1;
                    }
                    m = m - 1;
                }
                i = i - 1;
            } else {
                m = i;
                while(store[m-1][2] != 0){
                    k = 0;
                    while(k < width){
                        pixels[m][k]=7;
                        k = k + 1;
                    }
                    m = m - 1;
                }
                i = i - 1;
            }
        } else if (store[i][4] != 0){
            // handle 0 with a point inside circle and some of the 4s
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
            // everything out of the holes become 0
            while(j < width){
                pixels[i][j] = 7;
                j = j + 1;
            }
            i = i - 1;
        }

    }

    // clean all lines with only 1 "1" zone
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
    // end of changing digits, after this holes remain "0",some non-hole zones may have small number of lines of 0, which helps with further determination


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

    i = height - 1;
    j = 0;
    int cont = 1;
    int start = height;
    int end = 0;
    int count[height];
    
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
            if(pixels[i][j] != 7 && pixels[i][j] != 1){
                count[i] = 1;
                m = 1;
            }
            j = j + 1;
        }
        i = i - 1;
    }
     

    // determination of numbers
    i = height - 1;
    while(i > 0){
        m = 0;
        cont = 0;
        while(m == 0){
            if(count[i] == 1){
                start = i;
                while(count[i-1] != 0){
                    cont = cont + 1;
                    i = i - 1;
                }
                m = 1;        
            } else {
                i = i - 1;
                if(i == 1){
                    m = 1;
                }
            }     
        }

        if(cont > 5){
            //printf("%d cont\n",cont);
            number = number + 1;
        }
        i = i - 1;
    }


    i = 0;

    return number;
}

