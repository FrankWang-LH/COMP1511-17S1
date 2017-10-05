// Frank Wang
// 19/04/2017
// Determine closed area

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"

int holes(int height, int width, int pixels[height][width], int conditions){

    int number = 0;
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
    while(j < width){
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
        j = 0;
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

    //printf("%d\n",conditions);

    //find out where to start
    i = height - 1;
    k = 0;
    while(i >= 0){
        if(store[i][2] != 0 && store[i-1][2] == 0 && store[i-1][0] != 0){
            k = i;
            while(store[k][0] != 0 && k >= 0 && store[k][1] >= store[k-1][2] && m == 0){
                if(store[k-1][2] != 0 && store[k][2] == 0){
                    n = k;
                    m = 1;
                }
                k = k - 1;
            }
        }
        i = i - 1;
    }


    // deal with case 1
    i = height - 2;
    k = 0;
    m = 0;
    int cont = 1;
    int start = 0;
    int end = height;
    
    while(i >= 0 && conditions == 1){
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
    
        if(cont == (start-end) * 2){
        //printf("success, 1 circle\n");
        number = number + 1;
    } else {
        //printf("fail, no circles\n");
        number = number + 1 - 1;
    }

    // deal with case 2
    if(conditions == 2){
        i = n;
        j = 0;
        k = 0;
        m = 0;
        cont = 1;
        start = 0;
        end = height;
        
        // first find upper and lower boundaries
        while(i >= 0){
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

        //printf("%d %d\n",cont,(start-end)*2);
        if(cont == (start-end) * 2){
            //printf("success, 1 circle\n");
            number = number + 1;
        } else {
            //printf("fail, no circles\n");
            number = number + 1 - 1;
        }
    }

    // deal with case 3, lower half
    if(conditions == 3 || conditions == 4){
        i = n;
        j = 0;
        k = 0;
        m = 0;
        cont = 1;
        start = 0;
        end = height;
        
        // first find upper and lower boundaries
        while(i >= 0){
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

        if(cont == (start-end) * 2){
            //printf("success, 1 circle\n");
            number = number + 1;
        } else {
            //printf("fail, no circles\n");
            number = number + 1 - 1;
        }

        // upper half
        i = height - 2;
        j = 0;
        k = 0;
        m = 0;
        cont = 1;
        int nA = 0;
        int nB = 0;
        start = nA;
        
        while(i >= 0){
            if(store[i][2] != 0 && store[i+1][2] == 0 && store[i+1][0] != 0 && m == 0){
            nA = i;       
            m = 1;    
            }
            i = i - 1;
        }
        start = nA + 1; 

        i = height - 2;
        m = 0;
        while(i > 0){
            if(store[i][2] == 0 && store[i+1][2] != 0 && store[i+1][0] != 0 && m == 0 && store[i][0] != 0){
            nB = i;       
            m = 1;
            end = nB;    
            }
            i = i - 1;
        }


        //printf("%d %d\n",nA,nB);
        i = nA + 1;
        m = 0;
        
        while(i >= nB){
            j = 0;
            if(store[i][0] != 0 && store[i-1][2] != 0){
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
    
        if(cont == (start-end) * 2){
        //printf("success, 1 circle\n");
        number = number + 1;
    } else {
        //printf("fail, no circles\n");
        number = number + 1 - 1;
    }
   
}





    return number;
}
