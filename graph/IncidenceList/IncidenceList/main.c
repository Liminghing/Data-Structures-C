//
//  main.c
//  IncidenceList
//
//  Created by 임준형 on 11/7/24.
//

#include <stdio.h>
#include <stdlib.h>

// 변 구조체
typedef struct Edge {
    int src, dest, weight;
} Edge;

// 발생 리스트 구조체
typedef struct IncidenceList {
    int V, E;       // V: 꼭짓점의 수, E: 변의 수
    Edge* edges;    // 변의 배열
} IncidenceList;

// 발생 리스트 생성 함수
IncidenceList* createIncidenceList(int V, int E) {
    IncidenceList* list = (IncidenceList*) malloc(sizeof(IncidenceList));
    list->V = V;
    list->E = E;
    list->edges = (Edge*) malloc(E * sizeof(Edge));
    return list;
}

// 발생 리스트 출력 함수
void printIncidenceList(IncidenceList* list) {
    printf("Incidence List:\n");
    for (int i = 0; i < list->E; ++i) {
        printf("Edge %d: (%d --(%d)--> %d)\n",
               i, list->edges[i].src, list->edges[i].weight, list->edges[i].dest);
    }
}

// 발생 리스트 시각화 함수
void visualizeIncidenceList(IncidenceList* list) {
    printf("Incidence List Visualization:\n");
    for (int i = 0; i < list->E; ++i) {
        printf("%d ", list->edges[i].src);
        printf("--(%d)--> %d\n", list->edges[i].weight, list->edges[i].dest);
    }
    printf("\n");
}

int main() {
    int V = 4; // 꼭짓점의 수
    int E = 5; // 변의 수

    IncidenceList* list = createIncidenceList(V, E);

    // 변을 정의
    list->edges[0].src = 0;
    list->edges[0].dest = 1;
    list->edges[0].weight = 10;

    list->edges[1].src = 0;
    list->edges[1].dest = 2;
    list->edges[1].weight = 6;

    list->edges[2].src = 0;
    list->edges[2].dest = 3;
    list->edges[2].weight = 5;

    list->edges[3].src = 1;
    list->edges[3].dest = 3;
    list->edges[3].weight = 15;

    list->edges[4].src = 2;
    list->edges[4].dest = 3;
    list->edges[4].weight = 4;

    printIncidenceList(list);
    visualizeIncidenceList(list);

    // 메모리 해제
    free(list->edges);
    free(list);

    return 0;
}
