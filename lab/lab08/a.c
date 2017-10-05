// even

int even(int array[i],int i){

    int j = 0;
    int num = 0;
    while(j < i){
        if(array[j] % 2 == 0){
            num = num + 1;
        }
        j++;
    }
        
    return num;
}
    
// 2

int recur(int array[i],int i){
