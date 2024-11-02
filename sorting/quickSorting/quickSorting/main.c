#include <stdio.h>

// 두 요소를 교환하는 함수
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Median-of-Three 방식으로 피벗 선택
int medianOfThree(int arr[], int left, int right) {
    int mid = (left + right) / 2;

    // 세 값 중 중간값을 선택
    if (arr[left] > arr[mid]) swap(&arr[left], &arr[mid]);
    if (arr[left] > arr[right]) swap(&arr[left], &arr[right]);
    if (arr[mid] > arr[right]) swap(&arr[mid], &arr[right]);

    // 피벗을 right - 1 위치에 놓고 반환
    swap(&arr[mid], &arr[right - 1]);
    return arr[right - 1];
}

// 퀵정렬 함수
void quickSort(int *arr, int left, int right) {
    // 무한 재귀 탈출
    if (left >= right) return;

    // 피벗 선택
    int pivot = medianOfThree(arr, left, right);
    int i = left;
    int j = right - 2; // 조정된 인덱스

    // 피벗 기준 앞-뒤로 교환
    while (1) {
        while (arr[++i] < pivot);
        while (arr[--j] > pivot);
        if (i < j) {
            swap(&arr[i], &arr[j]);
        } else {
            break;
        }
    }

    swap(&arr[i], &arr[right - 1]); // 피벗을 최종 위치로 이동

    // 분할 후 재귀 호출
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

int main() {
    int arr[20] = {
        3, 5, 2, 2, 4,
        6, 1, 3, 7, 8,
        2, 11, 2, 21, 20,
        12, 14, 1, 6, 16
    };
    int n = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, n - 1);

    // 정렬된 배열 출력
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
