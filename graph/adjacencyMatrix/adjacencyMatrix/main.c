//
//  main.c
//  adjacencyMatrix
//
//  Created by 임준형 on 11/7/24.
//

#include <stdio.h>
#include <stdlib.h>

// 그래프 구조체
typedef struct Graph {
    int V;       // 정점의 수
    int** matrix;   // 인접 행렬
} Graph;

// 그래프 생성 함수
Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;

    // 인접 행렬 초기화
    graph->matrix = (int**) malloc(V * sizeof(int*));
    for (int i = 0; i < V; ++i) {
        graph->matrix[i] = (int*) calloc(V, sizeof(int));
    }

    return graph;
}

// 그래프에 변 추가 함수
void addEdge(Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1; // 무향 그래프이므로 대칭적이다
}

// 그래프 출력 함수
void printGraph(Graph* graph) {
    printf("Adjacency Matrix:\n");
    for (int v = 0; v < graph->V; ++v) {
        for (int e = 0; e < graph->V; ++e) {
            printf("%d ", graph->matrix[v][e]);
        }
        printf("\n");
    }
}

// 그래프 시각화 함수
void visualizeGraph(Graph* graph) {
    printf("Adjacency Matrix Visualization:\n");
    for (int v = 0; v < graph->V; ++v) {
        for (int u = 0; u < graph->V; ++u) {
            if (graph->matrix[v][u] == 1) {
                printf("%d --(1)--> %d\n", v, u);
            }
        }
    }
    printf("\n");
}

int main() {
    int V = 4; // 정점의 수

    Graph* graph = createGraph(V);

    // 변을 정의
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);
    visualizeGraph(graph);

    // 메모리 해제
    for (int i = 0; i < V; ++i) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);

    return 0;
}
