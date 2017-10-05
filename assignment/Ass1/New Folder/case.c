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

    // END OF FIND OUT MAX MIN

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
    i = height - 1;
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



    // ELIMINATE ERRORS
    i = height - 1;
    j = 0;
    while(i > 0){
        if(store[i][2] != 0 && store[i][2]-store[i][1] < 3 && store[i][4] == 0){
            j = 2;
            store[i][1] = store[i][3];
            while(j < 20){
                store[i][j] = 0;
                j = j + 1;
            }
        } else if (store[i][2] != 0 && store[i][2]-store[i][1] < 3 && store[i][4]!= 0){
            j = 2;
            store[i][1] = store[i][5];
            while(j < 20){
                store[i][j] = 0;
                j = j + 1;
            }
        }
        i = i - 1;
    }

 
    i = height - 2;
    j = 0;
    m = 0;
    while(i > 0){
        if(store[i-1][0] == 0 && store[i][0] != 0 && store[i][2] != 0 && store[i+1][2] == 0){
            
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
        }
        i = i - 1;
    }

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
            // everything out of the holes become 0
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
                    while(store[k+1][2] != 0){
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


    int start = height;
    int end = 0;
    // determine start and finish lines
    i = height - 1;
    m = 0;
    while(i > 0){
        if(store[i][2] != 0 && store[i][0] != 0 && store[i-1][2] != 0 && m == 0){
            start = i;
            m = 1;
        }
        i = i - 1;
    }

    i = 0;
    m = 0;
    while(i < height - 1){
        if(store[i][2] == 0 && store[i][0] != 0 && store[i + 1][2] != 0 && m == 0){
            end = i + 1;
            m = 1;
        }
        i = i + 1;
    }
 
    i = height - 1;
    j = 0;
    int cont = 1;
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

    // bound
    int bound[12];
    i = 0;
    while(i < 12){
        bound[i] = 0;
        i = i + 1;
    }

    j = 0;
    i = height - 2;
    while(i > 1){
        if(count[i] == 1 && count[i+1] == 0 && count[i-5] != 0){
            bound[j] = i;
            j = j + 1;
            i = i - 1;
        } else if(count[i] == 1 && count[i-1] == 0 && count[i+5] != 0){
            bound[j] = i;
            j = j + 1;
            i = i - 1;
        } else {
            i = i - 1;
        }
    }

    // print test for bound[i]    
    i = 0;
    while(i < 11 && bound[i] != 0){
        //printf("bound [%d] : %d\n",i,bound[i]);
        i = i + 1;
    } 


    //printf("start %d, end %d \n",start,end);
    i = 0;
    cont = 0;
    while(bound[i] != 0){
        cont = cont + 1;
        i = i + 1;
    }
    ///printf("start_row %d,end_row %d,\n",start_row,end_row);
    int zone = start_row - end_row;
    //printf("zone %d\n",zone);
    int zone1 = zone/5;
    int zone2 = zone/6;

    //printf("zone/5 %d zone/6 %d\n",zone1,zone2);
    int a = (start_row - zone2 + 1);
    int b = (start_row - 3 * zone1);
    int c = (start_row - 4 * zone1);
    int d = (start_row - 5 * zone2);
    //printf("line 1 %d line 2 %d line 3 %d line 4 %d\n",a,b,c,d);
    //printf("cont %d\n",cont);
    if(cont == 2 && bound[0] >= height*4/7 && bound[1] <= height*2/5 && start == bound[0] && end == bound[1]){
        if(start_row - start < 12){
            number = 1;
        } else {
            number = 6;
        }
    } else if(cont == 2 && start == bound[0] && bound[0] <= start_row && bound[1] >= b && (end - end_row) < 12){
        number = 9;
    } else if(cont == 2 && start == bound[0] && bound[0] <= a && bound[1] >= d){
        number = 4;    
    } else if(cont == 2){
        number = 6;
    } else if(cont == 3 && start != bound[0]){
        number = 6;
    } else if(cont == 3 && start == bound[0] && bound[0] <= start_row && bound[1] >= b && (end - end_row) < 12){
        number = 9;
    } else if(cont == 3 && start == bound[0] && bound[0] <= a && bound[1] >= d){
        number = 4; 
    } else if(cont == 4 && start == bound[0] && bound[0] <= start_row && bound[1] >= b){
        number = 9; 
    } else if(cont == 4 && start == bound[0] && bound[0] <= a && bound[1] >= d){
        number = 4;  
    } else { 
        number = 0;
    }

    return number;
}
