//
//  main.c
//  arrayCircleQueue
//
//  Created by 임준형 on 10/20/24.
//


#include <stdio.h>
#define MAX 5 // 큐의 최대 크기

int queue[MAX];  // 큐 배열
int front = 0;   // 큐의 앞을 가리키는 포인터
int rear = 0;    // 큐의 뒤를 가리키는 포인터

// 큐가 비어있는지 확인하는 함수
int IsEmpty() {
    return front == rear;
}

// 큐가 가득 찼는지 확인하는 함수
int IsFull() {
    return (rear + 1) % MAX == front;
}

// 큐에 데이터를 추가하는 함수
void addq(int value) {
    if (IsFull()) {
        printf("Queue is Full.\n");
    } else {
        //printf("front: %d rear : %d :", front,rear);
        rear = (rear + 1) % MAX;  // rear를 한 칸 이동
        queue[rear] = value;      // rear 위치에 값 저장
        printf("Enqueued: %d\n", value);
    }
}

// 큐에서 데이터를 제거하는 함수
int deleteq() {
    if (IsEmpty()) {
        printf("Queue is Empty.\n");
        return -1;  // 큐가 비었을 때는 -1 반환
    } else {
        int value = queue[front];  // 먼저 현재 front 위치의 값을 저장
        front = (front + 1) % MAX; // front를 한 칸 이동
        return value;
    }
}

// 큐의 현재 상태를 출력하는 함수 (for문으로 변경)
void displayQueue() {
    if (IsEmpty()) {
        printf("Queue is Empty.\n");
    } else {
        printf("Queue contents: ");
        for (int i = (front + 1) % MAX; i != (rear + 1) % MAX; i = (i + 1) % MAX) {
            printf("[%d] ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    addq(10);  // 큐에 10 추가
    addq(20);  // 큐에 20 추가
    addq(30);  // 큐에 30 추가
    addq(40);  // 큐에 40 추가
    addq(50);  // 큐에 50 추가
    addq(60);  // 큐에 60 추가
    displayQueue();  // 현재 큐 상태 출력
    deleteq();
    addq(50);  // 큐에 50 추가
    displayQueue();  // 현재 큐 상태 출력
    
    return 0;
}
