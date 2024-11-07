//
//  main.c
//  incidenceMatrix
//
//  Created by 임준형 on 11/7/24.
//

#include <stdio.h>
#include <stdlib.h>

// 그래프 구조체
typedef struct Graph {
    int V, E;       // V: 꼭짓점의 수, E: 변의 수
    int** matrix;   // 발생 행렬
} Graph;

// 그래프 생성 함수
Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;

    // 발생 행렬 초기화
    graph->matrix = (int**) malloc(V * sizeof(int*));
    for (int i = 0; i < V; ++i) {
        graph->matrix[i] = (int*) calloc(E, sizeof(int));
    }

    return graph;
}

// 그래프에 변 추가 함수
void addEdge(Graph* graph, int edgeNum, int src, int dest) {
    graph->matrix[src][edgeNum] = 1;
    graph->matrix[dest][edgeNum] = 1;
}

// 그래프 출력 함수
void printGraph(Graph* graph) {
    printf("Incidence Matrix:\n");
    for (int v = 0; v < graph->V; ++v) {
        for (int e = 0; e < graph->E; ++e) {
            printf("%d ", graph->matrix[v][e]);
        }
        printf("\n");
    }
}

// 그래프 시각화 함수
void visualizeGraph(Graph* graph) {
    printf("Incidence Matrix Visualization:\n");
    for (int e = 0; e < graph->E; ++e) {
        int src = -1, dest = -1;
        for (int v = 0; v < graph->V; ++v) {
            if (graph->matrix[v][e] == 1) {
                if (src == -1) {
                    src = v;
                } else {
                    dest = v;
                    break;
                }
            }
        }
        if (src != -1 && dest != -1) {
            printf("%d --(%d)--> %d\n", src, e, dest);
        }
    }
    printf("\n");
}

int main() {
    int V = 4; // 꼭짓점의 수
    int E = 5; // 변의 수

    Graph* graph = createGraph(V, E);

    // 변을 정의
    addEdge(graph, 0, 0, 1);
    addEdge(graph, 1, 0, 2);
    addEdge(graph, 2, 0, 3);
    addEdge(graph, 3, 1, 3);
    addEdge(graph, 4, 2, 3);

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
