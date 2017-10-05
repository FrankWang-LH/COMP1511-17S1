// Frank Wang and Matthew Tran
// 01/05/2017
// Read a string and determine if it's a palindrome

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 4096

int main(void){
    
    char line[MAX_LENGTH];

    // get an input
    printf("Enter a string: ");
    fgets(line, MAX_LENGTH, stdin);
    
    // find out the number of letters in the array
    int i = 0;
    while(line[i] != '\n'){
        i = i + 1;
    }

    int number = i;
    
    // use another array to place the array from the last letter to the first
    char rev[MAX_LENGTH];
    i = 0;
    int j = number - 1;
    while(i < number){
        rev[i] = line[j];
        j = j - 1;
        i = i + 1;
    }

    // compare two arrays
    int count = 0;
    i = 0;
    while(i < number){
        if(line[i] == rev[i]){
            count = count + 1;
        }
        i = i + 1;
    }

    // determine if it's a palindrome
    if(count == number){
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }
            
    return 0;
}
