//
//  main.c
//  sequential sorting
//
//  Created by 임준형 on 10/16/24.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {

    int i,j;
    int arr[20] = {
        3,5,2,2,4,
        6,1,3,7,8,
        2,11,2,21,20,
        12,14,1,6,16};
    int count = 0;
    int n =  sizeof(arr)/sizeof(int);
    for (i = 0 ; i < n ; i++){
        for(j = i + 1 ; j < n ; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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
