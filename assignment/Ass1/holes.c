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


    // ELIMINATE ERRORS

    i = height - 2;
    j = 0;
    m = 0;
    while(i > 0){
        if(store[i+1][0] == 0 && store[i][0] != 0 && store[i][2] != 0 && store[i+1][2] == 0){
            
            store[i][1] = store[i][3];
            j = 2;
            while(j < 20){
                store[i][j] = 0;
                j = j + 1;
            }
        } else if(store[i+1][0] != 0 && store[i][0] != 0 && store[i][2] != 0 && store[i+1][2] == 0 && store[i+1][1] == 0 && store[i-1][0] != 0 && store[i-1][2] == 0){
            store[i][1] = store[i][3];
            j = 2;
            while(j < 20){
                store[i][j] = 0;
                store[i-1][j] = 0;
                j = j + 1;
            }
        } else if(store[i][4] != 0 && store[i-1][2] == 0 ){
            store[i][1]=store[i][5];
            j = 2;
            while(j < 20){
                store[i][j] = 0;
                j = j + 1;
            }
        }
        i = i - 1;
    }

    //i = height - 1;
    //while(i >= 0){
    //    j = 0;
    //    printf("line %d ",i);
    //    while(store[i][j] != 0){
    //        printf("%d ",store[i][j]);
    //        j = j + 1;
    //    }
    //    printf("\n");
    //    i = i - 1;
    //}



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
        } else if (store[i][0] != 0 && store[i][4] != 0 && store[i][6] == 0 && store[i][8] == 0){
            // handle 0 with a point inside circle and some of the 4s
            k = 0;
            store[i][1] = store[i][5];
            store[i][2] = 0;
            store[i][3] = 0;
            store[i][4] = 0; 
            store[i][5] = 0;
            while(k < width){
                if(k < store[i][0] || k > store[i][1]){
                    pixels[i][k]= 7;
                } 
                k = k + 1;
            }
            i = i - 1;
        } else if (store[i][0] != 0 && store[i][2] == 0 && store[i][4] == 0){
            k = 0;
            while(k < width){
                if(k < store[i][0] || k > store[i][1]){
                    pixels[i][k] = 7;
                } 
                k = k + 1;
            }
            i = i - 1;
        } else if (store[i][0] == 0 && store[i][1] != 0 && store[i][2] != 0 && store[i][4] == 0){
            k = 0;
            while(k < width){
                if(k < store[i][0] || k > store[i][3]){
                    pixels[i][k] = 7;
                } 
                k = k + 1;
            }
            i = i - 1;
        } else if (store[i][0] == 0 && store[i][1] != 0 && store[i][2] == 0 && store[i][4] == 0){
            k = 0;
            while(k < width){
                if(k < store[i][0] || k > store[i][1]){
                    pixels[i][k] = 7;
                } 
                k = k + 1;
            }
            i = i - 1;
        } else if (store[i][0] == 0 && store[i][1] != 0 && store[i][4] != 0){
            k = 0;
            while(k < width){
                if(k < store[i][0] || k > store[i][5]){
                    pixels[i][k] = 7;
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
                if(pixels[i][j] != 1 && pixels[i][j] != 0){
                    pixels[i][j] = 7;
                }
                j = j + 1;
            }
            i = i - 1;
        }

    }




    // change half closed area to 7
    i  = height - 2;
    while(i > 0){
        j = 0;
        if(store[i][2] != 0 && store[i][4] == 0){
            while(j < width){
                if(pixels[i][j] == 0 && pixels[i+1][j] != 1 && pixels[i+1][j] != 0) {

                    k = i;
                    m = 0;
                    while(store[k-1][2] != 0){
                        m = 0;
                        while(m < width){
                            pixels[k][m] = 7;
                            m = m + 1;
                        }
                        k = k - 1;
                    }
                }
                j = j + 1;
            }
        } 
        i = i - 1;
    }

    i  = height - 2;
    while(i > 0){
        j = 0;
        if(store[i][2] != 0 && store[i][4] == 0){
            j = 0;
            while(j < width){
                if(pixels[i][j] == 0 && pixels[i-1][j] != 1 && pixels[i-1][j] != 0){

                    k = i;
                    m = 0;
                    while(store[k+1][2] != 0 && k < height - 1){
                        m = 0;
                        while(m < width){
                            pixels[k][m] = 7;
                            m = m + 1;
                        }
                        k = k + 1;
                    }
                }
                j = j + 1;
            }
        } 
        i = i - 1;
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


    // start of determination

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
            if(pixels[i][j] == 0){
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
            if(count[i] == 1 && i > 1 && m == 0){
                start = i;
                while(count[i-1] != 0 && i > 1){
                    cont = cont + 1;
                    if(i > 1){
                        i = i - 1;
                    } else {
                        m = 1;
                    }
                }
                m = 1;        
            } else {
                m = 1;
            }     
        }

        if(cont > 4){
            //printf("%d cont\n",cont);
            number = number + 1;
        }
        i = i - 1;
    }


    return number;
}

