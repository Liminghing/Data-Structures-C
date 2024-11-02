//
//  main.c
//  shellSorting
//
//  Created by 임준형 on 11/2/24.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i,j;
    int arr[20] = {
        3,5,2,2,4,
        6,1,3,7,8,
        2,11,2,21,20,
        12,14,1,6,16};
    int n = sizeof(arr)/sizeof(int);
    int count = 0;
    //gap을 절반으로 줄여나가는 반복문
    for(int gap = n/2 ; gap > 0 ; gap /= 2){
        //gap에서 시작하여 배열의 끝까지 반복
        for(int i = gap ; i < n ; i++){
            int temp = arr[i];
            int j;
            //삽입 정렬을 수행하는 부분
            for(j = i ; (j >= gap) && (arr[j-gap] > temp) ; j -= gap ){
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    
    return 0;
}

