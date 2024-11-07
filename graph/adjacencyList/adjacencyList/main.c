//
//  main.c
//  adjacencyList
//
//  Created by 임준형 on 11/7/24.
//

#include <stdio.h>
#include <stdlib.h>

// 그래프의 노드를 나타내는 구조체
typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
} AdjListNode;

// 그래프의 인접 리스트를 나타내는 구조체
typedef struct AdjList {
    AdjListNode* head; // 리스트의 헤드 포인터
} AdjList;

// 그래프 구조체
typedef struct Graph {
    int V;         // 꼭짓점의 수
    AdjList* array;
} Graph;

// 새로운 인접 리스트 노드를 생성
AdjListNode* newAdjListNode(int dest, int weight) {
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// 그래프 생성
Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;

    // 그래프의 인접 리스트 배열을 초기화
    graph->array = (AdjList*) malloc(V * sizeof(AdjList));
    for (int i = 0; i < V; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// 그래프에 변 추가
void addEdge(Graph* graph, int src, int dest, int weight) {
    // src에서 dest로의 변을 추가
    AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // 무향 그래프의 경우, dest에서 src로의 변도 추가
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// 그래프 출력
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d(%d)", pCrawl->dest, pCrawl->weight);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// 그래프 시각화 함수 추가
void visualizeGraph(Graph* graph) {
    printf("Adjacency List Visualization:\n");
    for (int v = 0; v < graph->V; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        while (pCrawl) {
            if (v < pCrawl->dest) { // 중복 출력 방지
                printf("%d --(%d)--> %d ", v, pCrawl->weight, pCrawl->dest);
            }
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int V = 5;
    Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 20);
    addEdge(graph, 1, 2, 30);
    addEdge(graph, 1, 3, 40);
    addEdge(graph, 1, 4, 50);
    addEdge(graph, 2, 3, 60);
    addEdge(graph, 3, 4, 70);

    printGraph(graph);
    visualizeGraph(graph);

    // 메모리 해제
    for (int i = 0; i < V; ++i) {
        AdjListNode* pCrawl = graph->array[i].head;
        while (pCrawl) {
            AdjListNode* temp = pCrawl;
            pCrawl = pCrawl->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);

    return 0;
}

