//
//  main.c
//  selection sorting
//
//  Created by 임준형 on 10/16/24.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int arr[20] = {
        3,5,2,2,4,
        6,1,3,7,8,
        2,11,2,21,20,
        12,14,1,6,16};
    int n = sizeof(arr)/sizeof(int);
    int count;
    int min,index;
    for(int i =  0 ; i < n ; i++){
        min = 10000000000;
        for(int j = i ; j < n ; j++){
            if(min > arr[j]){
                min = arr[j];
                index = j;
                count++;
            }
        }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    
    
    
    for (int k = 0 ; k < n ; k++){
        printf("%d ",arr[k]);
    }
    printf("\nn^%d",count/n);
    return 0;
}
