// remove same numbers

#include <stdio.h>
#define MAX_LENGTH 1024

void store(int pixels[MAX_LENGTH]){
    int c = 0;
    int i = 0;
    int j = 0;
    int cont = 0;
    while(scanf("%d",&c) == 1){
        j = 0;
        cont = 0;
        while(j < i && cont == 0){
            if(c == pixels[j]){
                cont = 1; 
            }
            j++;
        }
        if(cont != 1){
            pixels[i] = c;
            i++;
        }
    }
  
}

int main(void){
    int pixels[MAX_LENGTH];
    store(pixels);

    int j = 0;
    while(pixels[j] != 0){
        printf("%d ",pixels[j]);
        j++;
    }
    printf("\n");
    return 0;
}         

