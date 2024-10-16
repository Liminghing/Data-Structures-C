//
//  main.c
//  insertion sorting
//
//  Created by 임준형 on 10/16/24.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {

    int arr[20] = {
        1, 2, 3, 4, 5, 6, 1, 8, 9, 10,
        11, 1, 13, 14, 15, 6, 17, 18, 19, 20
    };
    int n = sizeof(arr)/sizeof(int);
    int count = 0;
    int i,j,key;
    
    
    for(i = 1 ; i <  n ; i ++){
        key = arr[i];
        for(j = i-1 ; j >= 0 && arr[j]> key ; j--){
            arr[j+1] = arr[j];
            count++;
        }
        arr[j+1] = key;
    }

    
    for (int k = 0 ; k < n ; k++){
        printf("%d ",arr[k]);
    }
   printf("\nn^%d",count/n);
    return 0;
}
