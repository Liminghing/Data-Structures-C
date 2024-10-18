//
//  main.c
//  linkedlist
//
//  Created by 임준형 on 10/18/24.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head;
/*------출력함수 부분------*/
void printList(void){
    if(head == NULL){
        printf("제공한 헤드의 값이 NULL\n");
        return ;
    }else{
        Node *ptr = head;
        printf("링크드리스트 : ");
        for(;ptr;ptr = ptr->next){
            printf("%d ",ptr->data);
        }
        printf("\n");
        return ;
    }
}


/*------맨앞 삽입함수 부분------*/
void insertAtHead(int insertData){
    Node* newNodePoint = (Node *)malloc(sizeof(Node));
    newNodePoint->data = insertData;
    newNodePoint->next = NULL;
    
    if(head == NULL){
        head = newNodePoint;
        return ;
    }else{
        newNodePoint->next = head;
        head = newNodePoint;
        return ;
    }
}
/*------맨뒤 삽입함수 부분------*/
void insertAtTail(int insertData){
    Node* newNodePoint = (Node *)malloc(sizeof(Node));
    newNodePoint->data = insertData;
    newNodePoint->next = NULL;
    
    if(head == NULL){
        head = newNodePoint;
        return ;
    }else{
        Node *ptr = head;
        for(;ptr->next;ptr = ptr->next);
        ptr->next = newNodePoint;
        return ;
    }
}
/*------중간 삽입함수 부분(크기순)------*/
void insertAtPosition(int insertData){
    Node* newNodePoint = (Node *)malloc(sizeof(Node));
    newNodePoint->data = insertData;
    newNodePoint->next = NULL;
    
    if(head == NULL){
        head = newNodePoint;
        return ;
    }else{
        if(head->data >= insertData){
            insertAtHead(insertData);
                    return;
        }else{
            Node *ptr = head;
            for(;ptr->next;ptr = ptr->next){
                if((ptr->data < newNodePoint->data) && (newNodePoint->data < ptr->next->data)){
                    newNodePoint-> next = ptr->next;
                    ptr->next = newNodePoint;
                    break;
                }
            }
            if(ptr->next == NULL){
                insertAtTail(insertData);
            }
            return ;
        }

    }
}
/*------맨앞 삭제함수 부분------*/
void deleteAtHead(void){
    if(head == NULL){
        printf("제공한 헤드의 값이 NULL\n");
        return ;
    }else{
        Node *ptr = head;
        head = head->next;
        free(ptr);
        return ;
    }
}
/*------맨뒤 삭제함수 부분------*/
void deleteAtTail(void){
    if(head == NULL){
        printf("제공한 헤드의 값이 NULL\n");
        return ;
    }else{
        Node *prevPtr = head;
        Node *curPtr = head;
        if(curPtr->next==NULL){
            head = NULL;
            free(curPtr);
            return ;
        }else{
            while(1){
                curPtr = curPtr->next;
                if(curPtr->next == NULL){
                    prevPtr->next = NULL;
                    free(curPtr);
                    return ;
                }
                prevPtr = prevPtr->next;
            }
        }

    }
}
/*------원하는 인덱스의 노드 삭제함수 부분(원하는 인덱스)------*/
void deleteIndex(int index){
    if (index < 0) {
         printf("유효하지 않은 인덱스입니다.\n");
         return;
     }
    if(head == NULL){
        printf("제공한 헤드의 값이 NULL\n");
        return ;
    }else{
        Node *prevPtr = head;
        Node *curPtr = head;
        int countIndex = 0;
        if(countIndex==index){
            deleteAtHead();
            return ;
        }else{
            while(1){
                if(curPtr->next==NULL) {
                    printf("해당하는 인덱스는 존재하지않습니다.\n");
                    return ;
                }
                curPtr = curPtr->next;
                countIndex++;
                if(countIndex == index){
                    prevPtr->next = curPtr->next;
                    free(curPtr);
                    return ;
                }
                prevPtr = prevPtr->next;
            }
        }
    }
    
}
/*------원하는 데이터를 가지는 노드 삭제함수 부분(원하는 데이터)------*/
void deleteData(int data){
    if(head == NULL){
        printf("제공한 헤드의 값이 NULL\n");
        return ;
    }else{
        Node *prevPtr = head;
        Node *curPtr = head;
        if(curPtr->data==data){
            deleteAtHead();
            return ;
        }else{
            while(1){
                if(curPtr->next==NULL) {
                    printf("해당하는 데이터는 존재하지않습니다.\n");
                    return ;
                }
                curPtr = curPtr->next;
                if(curPtr->data == data){
                    prevPtr->next = curPtr->next;
                    free(curPtr);
                    return ;
                }
                prevPtr = prevPtr->next;
            }
        }
    }
    
}
int main(int argc, const char * argv[]) {
    head = NULL;
    
    insertAtHead(100);
    insertAtHead(98);
    insertAtTail(102);
    insertAtPosition(96);
    printList();

    return 0;
}
