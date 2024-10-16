//
//  main.c
//  bubble sorting
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
    
    int i,j;
    int count;
    int n = sizeof(arr)/sizeof(int);
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n-1 ; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
    }
    
    
    for (int k = 0 ; k < n ; k++){
        printf("%d ",arr[k]);
    }
    
    printf("\nn^%d",count/n);
    return 0;
}
