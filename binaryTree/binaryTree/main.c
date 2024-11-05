//
//  main.c
//  binaryTree
//
//  Created by 임준형 on 11/5/24.
//

#include <stdio.h>
#include <stdlib.h>

//헤더 파일 및 구조체 정의
typedef struct Node {
    int data;
    struct Node *leftChild;  // 왼쪽 자식 링크
    struct Node *rightChild; // 오른쪽 자식 링크
} Node;

//노드 생성 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}
//순회 함수 : preOrder
void preOrder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);       // 자신
        preOrder(root->leftChild);       // 왼쪽 자식
        preOrder(root->rightChild);      // 오른쪽 자식
    }
}
//순회 함수 : inOrder
void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->leftChild);   // 왼쪽 자식
        printf("%d ", root->data);  // 자신
        inOrder(root->rightChild);  // 오른쪽 자식
    }
}
//순회 함수 : postOrder
void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->leftChild);   // 왼쪽 자식
        postOrder(root->rightChild);  // 오른쪽 자식
        printf("%d ", root->data);    // 자신
    }
}
//노드 삽입 함수 - 재귀적으로 삽입
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->leftChild = insertNode(root->leftChild, data);
    } else if (data > root->data) {
        root->rightChild = insertNode(root->rightChild, data);
    }
    return root;
}
//최소값 찾기
Node* findMin(Node* root) {
    while (root->leftChild != NULL) {
        root = root->leftChild; //왼쪽 자식으로 계속 이동 => 가장 왼쪽에 있는 노드가 최솟값
    }
    return root;
}
//노드 삭제 함수
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root; // 트리가 비어있는 경우
    
    if (data < root->data) {
        root->leftChild = deleteNode(root->leftChild, data); // 왼쪽 자식에서 삭제
    } else if (data > root->data) {
        root->rightChild = deleteNode(root->rightChild, data); // 오른쪽 자식에서 삭제
    } else {
        // 자식이 없는 경우 or 한쪽 자식만 있는 경우
        if (root->leftChild == NULL) {
            Node* temp = root->rightChild; // 현재 노드 메모리 해제
            free(root);
            return temp;
        } else if (root->rightChild == NULL) {
            Node* temp = root->leftChild; // 현재 노드 메모리 해제
            free(root);
            return temp;
        }
        // 두 자식이 모두 있는 경우
        Node* temp = findMin(root->rightChild); // 오른쪽 서브트리에서 최소값 찾기
        root->data = temp->data; // 현재 노드에 최소값 설정
        root->rightChild = deleteNode(root->rightChild, temp->data); // 최소값 삭제
    }
    return root;
}

int main() {
    // 트리 초기화
    Node* root = NULL;
    
    // 노드 삽입
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);
    
    // 전위 순회 출력
    printf("preOrder : ");
    preOrder(root);
    printf("\n\n");
    
    // 중위 순회 출력
    printf("inOrder : ");
    inOrder(root);
    printf("\n\n");
    
    // 후위 순회 출력
    printf("postOrder : ");
    postOrder(root);
    printf("\n\n");

    printf("deleteNode 20\n\n");
    root = deleteNode(root, 20);
    printf("inOrder : ");
    inOrder(root);
    printf("\n\n");

    return 0;
}
