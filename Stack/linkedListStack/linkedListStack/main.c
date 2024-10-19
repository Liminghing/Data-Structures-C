//
//  main.c
//  linkedListStack
//
//  Created by 임준형 on 10/19/24.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;
typedef struct {
    Node *top;
}Stack;



void init(Stack *s){
    s->top = NULL;
}
int isEmpty(Stack *s){
    if(s->top == NULL){
        return 1;
    }else{
        return 0;
    }
}
void push(Stack *s,int insertData){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = insertData;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("연결리스트가 비어있습니다.\n");
        return -1;
    }else{
        Node *tempNode = s->top;
        int temp = s->top->data;
        s->top = s->top->next;
        free(tempNode);
        return temp;
    }
}
void printfStack(Stack *s){
    Node *temp = s->top;
    for(;temp;temp = temp->next){
        printf("%d ",temp->data);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    Stack s;
    init(&s);
    
    printf("비어있는가? %d\n",isEmpty(&s));
    push(&s,10);
    printfStack(&s);
    push(&s,11);
    printfStack(&s);
    push(&s,12);
    push(&s,14);
    printf("비어있는가? %d\n",isEmpty(&s));
    push(&s,11);
    printfStack(&s);
    pop(&s);
    printfStack(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    push(&s,12);
    push(&s,14);
    push(&s,122);
    push(&s,124);
    printfStack(&s);
    init(&s);
    printfStack(&s);
    push(&s,12);
    push(&s,14);
    printfStack(&s);
}
