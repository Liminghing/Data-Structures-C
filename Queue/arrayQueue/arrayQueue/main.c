//
//  main.c
//  arrayQueue
//
//  Created by 임준형 on 10/20/24.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10
typedef struct {
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE]; //사용할 배열
}Queue;
void error(char *message){
    fprintf(stderr,"%s\n",message);
    exit(1);
}
void init_queue(Queue *q){
    q->front = -1;
    q->rear = -1;
}
void queue_printf(Queue *q){
    for(int i = 0 ; i < MAX_QUEUE_SIZE ; i++){
        if(i <= q->front || q->rear < i){
            printf("[ ]");
        }else{
            printf("[%d]",q->data[i]);
        }
    }
    printf("\n");
}
int is_full(Queue *q){
    if(q->rear == MAX_QUEUE_SIZE-1){
        return 1;
    }else{
        return 0;
    }
}
int is_empty(Queue *q){
    if(q->rear == q->front){
        return 1;
    }else{
        return 0;
    }
}
void enqueue(Queue *q,int item){
    if(is_full(q)){
        printf("FULL\n");
        return;
    }else{
        q->data[++q->rear] = item;
    }
}
int dequeue(Queue *q){
    int item;
    if(is_empty(q)){
        printf("EMPTY\n");
        return -1;
    }else{
        item = q->data[++q->front];
        return item;
    }
}
int main(int argc, const char * argv[]) {
    Queue queue;
    init_queue(&queue);

    
    enqueue(&queue,1);
    queue_printf(&queue);
    enqueue(&queue,2);
    queue_printf(&queue);
    enqueue(&queue,3);
    queue_printf(&queue);
    enqueue(&queue,4);
    queue_printf(&queue);
    enqueue(&queue,5);
    queue_printf(&queue);
    enqueue(&queue,6);
    queue_printf(&queue);
    enqueue(&queue,7);
    queue_printf(&queue);
    enqueue(&queue,8);
    queue_printf(&queue);
    enqueue(&queue,9);
    queue_printf(&queue);
    enqueue(&queue,10);
    queue_printf(&queue);
    dequeue(&queue);
    queue_printf(&queue);
    dequeue(&queue);
    queue_printf(&queue);
    dequeue(&queue);
    queue_printf(&queue);
    dequeue(&queue);
    queue_printf(&queue);
    dequeue(&queue);
    queue_printf(&queue);
    
    return 0;
}
