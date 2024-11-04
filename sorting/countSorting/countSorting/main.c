//
//  main.c
//  countSorting
//
//  Created by 임준형 on 11/4/24.
//

#include <stdio.h>
#include <stdlib.h>

// countSort 함수 정의
void countSort(int *array, int size) {
    
    // 배열에서 가장 큰 값을 찾기
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    // 카운트 배열 할당 및 초기화
    int *count = (int *)calloc(max + 1, sizeof(int));
    int *output = (int *)malloc(size * sizeof(int));

    // 각 요소의 빈도 계산
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // 카운트 배열의 누적합 계산
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 출력 배열에 요소를 배치
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i]; //결과배열에 원본 배열의 계수 위치에 원본값 저장
        count[array[i]]--; //계수의 개수 감소
    }

    // 정렬된 값을 원래 배열에 복사
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }

    // 메모리 해제
    free(count);
    free(output);
}

int main(int argc, const char * argv[]) {
    int arr[20] = {
        3, 5, 2, 2, 4,
        6, 1, 3, 7, 8,
        2, 11, 2, 21, 20,
        12, 14, 1, 6, 16
    };
    int n = sizeof(arr) / sizeof(int);
    countSort(arr, n);
    // 정렬된 배열 출력
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
