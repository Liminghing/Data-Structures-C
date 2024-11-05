//
//  main.c
//  completeBinaryTree
//
//  Created by 임준형 on 11/5/24.
//

#include <stdio.h>
#include <stdlib.h>

//구조체 정의
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

//완전 이진트리
typedef struct CompleteBinaryTree {
    Node* root; // 루트 노드
    int size;   // 현재 노드 수
} CompleteBinaryTree;

// 노드 생성 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 완전 이진트리 생성 함수
CompleteBinaryTree* createCompleteBinaryTree() {
    CompleteBinaryTree* tree = (CompleteBinaryTree*)malloc(sizeof(CompleteBinaryTree));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

// 노드 추가 함수 (완전 이진트리의 특성을 유지)
void addNode(CompleteBinaryTree* tree, int data) {
    Node* newNode = createNode(data);
    if (tree->root == NULL) {
        tree->root = newNode; // 트리가 비어 있을 경우 루트 노드 설정
    } else {
        Node* current = tree->root;
        Node* parent;
        int isLeft = 1; // 왼쪽 자리에 추가할지 여부

        // 적절한 위치 찾기
        while (current != NULL) {
            parent = current;
            if (tree->size % 2 == 0) { // 짝수 인덱스에서 왼쪽 자식
                current = current->left;
            } else { // 홀수 인덱스에서 오른쪽 자식
                current = current->right;
                isLeft = 0; // 오른쪽 자식
            }
        }

        // 노드를 부모의 자식으로 연결
        if (isLeft) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
    tree->size++;
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

// 메모리 해제 함수
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    CompleteBinaryTree* tree = createCompleteBinaryTree();
    
    int dataArray[] = {10, 20, 30, 40, 50}; // 정 이진트리에 추가할 데이터
        int size = sizeof(dataArray) / sizeof(dataArray[0]); // 배열 크기

        // 배열의 각 요소를 정 이진트리에 추가
        for (int i = 0; i < size; i++) {
            addNode(tree, dataArray[i]);
        }
    // 이진 트리 출력
    printTree(tree->root, 0);

    // 메모리 해제
    freeTree(tree->root);
    free(tree);
    return 0;
}
