//
//  main.c
//  mergeSorting
//
//  Created by 임준형 on 11/4/24.
//

#include <stdio.h>
# define MAX_SIZE 20
int sorted[MAX_SIZE]; // 추가적인 공간이 필요

void merge(int list[], int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int k = left;
    int l;
    
    while(i<=mid && j<=right){
        //쪼개진 배열 내에서 left인덱스의 값과 mid인덱스 값을 비교 후 크기순으로 sorted에 추가
        if(list[i]<=list[j])
          sorted[k++] = list[i++];
        else
          sorted[k++] = list[j++];
    }
    // 남아 있는 값들을 일괄 복사
      if(i>mid){ //mid기준 뒤쪽(j)이 남은경우
        for(l=j; l<=right; l++)
          sorted[k++] = list[l];
      }
      else{ //mid기준 앞쪽(i)이 남은경우
        for(l=i; l<=mid; l++)
          sorted[k++] = list[l];
      }
    //원래의 배열에 복사
    for(l=left; l<=right; l++){
        list[l] = sorted[l];
      }
}

// 병합 정렬
void merge_sort(int list[], int left, int right){
  int mid;
  if(left<right){
      mid = (left+right)/2;
      // 좌우 배열 재귀적으로 쪼개기
      merge_sort(list, left, mid);
      merge_sort(list, mid+1, right);
      
      // 쪼개진 두 부분을 정렬후 병합
      merge(list, left, mid, right);
  }
}

int main(int argc, const char * argv[]) {
    int arr[20] = {
        3, 5, 2, 2, 4,
        6, 1, 3, 7, 8,
        2, 11, 2, 21, 20,
        12, 14, 1, 6, 16
    };
    int n = sizeof(arr) / sizeof(int);
    merge_sort(arr, 0, n-1);

    // 정렬된 배열 출력
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
