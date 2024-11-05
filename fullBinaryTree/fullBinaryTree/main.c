//
//  main.c
//  fullBinaryTree
//
//  Created by 임준형 on 11/5/24.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 이진 트리의 노드 구조체
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 새로운 노드 생성
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 포화 이진 트리 생성
Node* createFullBinaryTree(int* values, int index, int size) {
    // 종료 조건: 인덱스가 배열 크기를 초과하면 NULL 반환
    if (index >= size) {
        return NULL;
    }

    // 현재 인덱스의 값을 가진 노드 생성
    Node* root = createNode(values[index]);
    
    // 왼쪽 및 오른쪽 자식을 재귀적으로 생성
    root->left = createFullBinaryTree(values, 2 * index + 1, size);  // 왼쪽 자식
    root->right = createFullBinaryTree(values, 2 * index + 2, size); // 오른쪽 자식

    return root;
}


// 메모리 해제
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

//이진 트리 출력 함수
void printTree(Node* root, int space) {
    //현재 노드가 NULL인 경우 종료
    if (root == NULL) return;

    //각 레벨 간의 간격 늘리기
    space += 5;

    //오른쪽 자식을 먼저 처리
    printTree(root->right, space);

    // 현재 노드를 출력하기 전에 줄 바꿈을 추가
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    // 왼쪽 자식을 먼저 처리
    printTree(root->left, space);
}

int main() {
    // 포화 이진 트리를 구성할 데이터 배열
    int values[] = {5, 3, 1, 4, 2, 6, 7};
    int size = sizeof(values) / sizeof(values[0]);

    // 포화 이진 트리 생성
    Node* root = createFullBinaryTree(values, 0, size);

    printf("포화 이진 트리의 구조:\n");
    printTree(root, 0);
    printf("\n");

    // 메모리 해제
    freeTree(root);

    return 0;
}

