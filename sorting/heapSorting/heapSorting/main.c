//
//  main.c
//  heapSorting
//
//  Created by 임준형 on 11/4/24.
//

#include <stdio.h>

//교환 함수
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    
    int largest = i; //부모
    int left = 2 * i + 1; //왼쪽 자식
    int right = 2 * i + 2; //오른쪽 자식

    // 왼쪽 자식이 더 큰 경우
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 오른쪽 자식이 더 큰 경우
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 가장 큰 값이 루트가 아닌 경우 스왑하고 재귀적으로 힙 조정
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // 배열을 처음부터 최대 힙으로 만드는 초기화 과정
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // 하나씩 요소를 힙에서 제거하여 정렬 - 마지막요소와 루트 바꾸고 힙트리 재구성
        for (int i = n - 1; i > 0; i--) {
            // 루트와 마지막 요소를 교환
            swap(&arr[0], &arr[i]);
            
            // 남은 부분에 대해 힙 구조를 유지
            heapify(arr, i, 0);
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
    heapSort(arr, n);
    // 정렬된 배열 출력
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
