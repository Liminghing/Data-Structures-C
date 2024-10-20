//
//  main.c
//  linkedlistQueue
//
//  Created by 임준형 on 10/20/24.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node; // 연결 리스트의 형태를 갖추기 위한 구조체

typedef struct {
    Node* front, * rear;
}Queue; // 큐의 형태를 갖추기 위한 구조체

void init(Queue *q){
    q->front = NULL;
    q->rear = NULL;
}
int is_empty(Queue *q){
    if(q->front == NULL){
        return 1;
    }else{
        return 0;
    }
}
void enqueue(Queue *q,int insertData){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = insertData;
    newNode->next = NULL;
    if(is_empty(q)){
        q->front = newNode;
        q->rear = newNode;
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
int dequeue(Queue *q){
    Node *temp = (Node *)malloc(sizeof(Node));
    int data;
    if(is_empty(q)){
        printf("error");
        return -1;
    }else{
        temp = q->front;
        data = q->front->data;
        q->front = q->front->next;
        if(q->front == NULL){
            q->rear = NULL;
        }
        free(temp);
        return data;
    }
}
void print_queue(Queue *q){
    Node *temp;
    for(temp = q->front ; temp != NULL ; temp = temp->next){
        printf("%d->",temp->data);
    }
    printf("NULL\n");
    
}

int main(int argc, const char * argv[]) {
    Queue que;
    init(&que); // 초기화
    enqueue(&que, 10); print_queue(&que); // 10 삽입
    enqueue(&que, 30); print_queue(&que); // 30 삽입
    enqueue(&que, 40); print_queue(&que); // 40 삽입
    enqueue(&que, 60); print_queue(&que); // 60 삽입
    dequeue(&que); print_queue(&que); // 10 삭제
    dequeue(&que); print_queue(&que); // 30 삭제
    dequeue(&que); print_queue(&que); // 40 삭제
    dequeue(&que); print_queue(&que); // 60 삭제
    return 0;
}
