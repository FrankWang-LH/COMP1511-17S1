// 24/04/2016
// Frank Wang
// Determine cases of holes

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

int condition(int height, int width, int config[height][width]){ 


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
            store[i][2] = store[i][4];
            store[i][3] = store[i][5];
            j = 4;
            while(j < 20){
                store[i][j] = 0;
                j = j + 1;
            }
        }
        i = i - 1;
    }

    // changing all outside digits to 7
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
                    pixels[i][k]= 7;
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
        if(store[i][2] != 0){
            while(j < width){
                if(pixels[i][j] == 0 && pixels[i+1][j] != 1 && pixels[i+1][j] != 0) {

                    k = i;
                    m = 0;
                    while(store[k][2] != 0 || store[k][4] != 0){
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
        if(store[i][2] != 0){
            j = 0;
            while(j < width){
                if(pixels[i][j] == 0 && pixels[i-1][j] != 1 && pixels[i-1][j] != 0){

                    k = i;
                    m = 0;
                    while(k < height - 1 && store[k][2] != 0){
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
    // end of changing digits, the same as in holes
    
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
 
    // find bound of holes
    int bound[12];
    i = 0;
    while(i < 12){
        bound[i] = 0;
        i = i + 1;
    }

    j = 0;
    i = height - 2;
    while(i > 1){
        if(count[i] == 1 && count[i+1] == 0 && count[i-1] != 0){
            bound[j] = i;
            j = j + 1;
            i = i - 1;
        } else if(count[i] == 1 && count[i-1] == 0 && count[i+1] != 0){
            bound[j] = i;
            j = j + 1;
            i = i - 1;
        } else {
            i = i - 1;
        }
    }



    // determination of numbers
    i = height - 1;
    while(i > 0){
        m = 0;
        cont = 0;
        while(m == 0 && i > 0){
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


        if(cont > 3){
            number = number + 1;
        }
        i = i - 1;
    }
    
    // reduce error for bound[i]
    if(number != 0){
        i = 0;
        while(bound[i] != 0){
            if(bound[i] - bound[i + 1] <= 2){
             bound[i] = bound[i+2];
             bound[i+1] = bound[i+3];
            }
            i = i + 1;
        }
    }

    // lines to limit holes
    int zone1 = height/5;
    int zone2 = height/6;
    int zone3 = height/4;

    int a = (height - zone2 + 1);
    int b = (height - 3 * zone1 - 1);
    int c = (height - 4 * zone1);
    int d = (height - 5 * zone2);
    int e = (height - zone3);
    int mid = height/2;
    int midZone = bound[0] - (bound[0]-bound[1]) / 2;
    double ratio = ((bound[0] - bound[1])*1.0)/height * 1.0;

    // determination
    if(number == 1){
        if(ratio > 0.57){
            number = 0;
        } else if(midZone < mid && start < mid + 6){
            number = 6;
        } else if(bound[0] <= height && bound[1] >= b && bound[0] > e){
            number = 9;
        } else if(bound[0] <= a && bound[1] >= d){
            number = 4;
        }
    }
    return number;
}
