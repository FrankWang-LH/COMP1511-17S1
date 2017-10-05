// Frank and Tanya
// MAY 15 2017
// turn grades into labmark

#include <stdio.h>
#include <stdlib.h>

double grades2labmark(char grades[]);

int main(int argc, char * argv[]){

    // run the function and get the mark
    double mark = grades2labmark(argv[1]);
    printf("%.1lf \n",mark);

    return 0;
}

double grades2labmark(char grades[]){
    double mark = 0.0;
    // go through the array
    int i = 0;
    while(grades[i] != 0){ 
        // add points for each mark       
        if(grades[i] == 'A'){
            mark = mark + 1.0;
        } else if(grades[i] == '+'){
            mark = mark + 0.2;// A+ = 1.2 and A = 1.0, which means "+" = 0.2
        } else if(grades[i] == 'B'){
            mark = mark + 0.8;
        } else if(grades[i] == 'C'){
            mark = mark + 0.5;
        } 
        i = i + 1;
    }

    // maximum mark is 10.0
    if(mark > 10.0){
        mark = 10.0;
    }
    
    return mark;
}
