//
//  main.c
//  radixSorting
//
//  Created by 임준형 on 11/4/24.
//

#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10  // 버킷의 개수, 기수 정렬에서는 0-9로 사용
#define MAX_DIGITS 5  // 최대 자릿수

// 숫자 중 최대 자릿수에 도달할 때까지 자릿수별로 버킷을 정렬
void radixSort(int *array, int size) {
    //버킷 생성 단계
    int **buckets = (int **)malloc(BUCKETS * sizeof(int *));
    int bucketSizes[BUCKETS];  // 각 버킷의 크기
    int divisor = 1;
    
    //MAX_DIGITS자리수 전까지 반복
    for (int digit = 0; digit < MAX_DIGITS; digit++) {
        //각자리수별 버킷 초기화 단계
        for (int i = 0; i < BUCKETS; i++) {
            buckets[i] = (int *)malloc(size * sizeof(int));
            bucketSizes[i] = 0;
        }
        
        //배열의 자리수의 크기별 버킷에 정렬(자리수 기준)
        for (int i = 0; i < size; i++) {
            int bucketIndex = (array[i] / divisor) % 10;
            buckets[bucketIndex][bucketSizes[bucketIndex]++] = array[i];
        }

        //자리수별 정렬된 버킷을 다시 배열에 넣기
        int index = 0;
        for (int i = 0; i < BUCKETS; i++) {
            for (int j = 0; j < bucketSizes[i]; j++) {
                array[index++] = buckets[i][j];
            }
            free(buckets[i]);  // 사용한 버킷 메모리 해제
        }
        divisor *= 10;  // 다음 자릿수로 이동
    }
    free(buckets);  // 모든 버킷 메모리 해제
}
int main(int argc, const char * argv[]) {
    int arr[20] = {
        3, 5, 2, 2, 4,
        6, 1, 3, 7, 8,
        2, 11, 2, 21, 20,
        12, 14, 1, 6, 16
    };
    int n = sizeof(arr) / sizeof(int);
    radixSort(arr, n);
    // 정렬된 배열 출력
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
