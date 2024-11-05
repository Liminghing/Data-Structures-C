//
//  main.c
//  strictlyBinaryTree
//
//  Created by 임준형 on 11/5/24.
//
#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 새로운 노드 생성 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 정이진트리에 노드를 추가하는 함수
Node* insertStrictlyBinaryTree(Node* root, int data) {
    // 현재 노드가 비어있으면 새로운 노드 추가
    if (root == NULL) {
        return createNode(data);
    }
    
    // 왼쪽 자식이 없으면 왼쪽에 추가
    if (root->left == NULL) {
        root->left = insertStrictlyBinaryTree(root->left, data);
    }
    // 오른쪽 자식이 없으면 오른쪽에 추가
    else if (root->right == NULL) {
        root->right = insertStrictlyBinaryTree(root->right, data);
    }
    // 두 자식이 모두 존재하면 추가하지 않음 (정이진트리의 특성)
    
    return root;
}

// 트리를 전위 순회로 출력하는 함수
void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// 이진 트리 출력 함수
void printTree(Node* root, int space) {
    // 현재 노드가 NULL인 경우 종료
    if (root == NULL) return;

    // 각 레벨 간의 간격 늘리기
    space += 5;

    // 오른쪽 자식을 먼저 처리
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

// 메인 함수
int main() {
    Node* root = NULL;
    int dataArray[] = {10, 20, 30, 40, 50}; // 정이진트리에 추가할 데이터
    int size = sizeof(dataArray) / sizeof(dataArray[0]); // 배열 크기

    // 배열의 각 요소를 정이진트리에 추가
    for (int i = 0; i < size; i++) {
        root = insertStrictlyBinaryTree(root, dataArray[i]);
    }


    // 이진 트리 출력
    printf("이진 트리 구조:\n");
    printTree(root, 0);
    printf("\n");

    return 0;
}


