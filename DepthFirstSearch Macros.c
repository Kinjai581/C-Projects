#include <stdio.h>

#define MAX_VERTICES 4

void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int vertex) {
    printf("Visited: %d\n", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(graph, visited, i);
        }
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    int visited[MAX_VERTICES] = {0};

    graph[0][1] = 1;
    graph[1][0] = 1;

    graph[0][2] = 1;
    graph[2][0] = 1;

    graph[1][2] = 1;
    graph[2][1] = 1;

    graph[2][3] = 1;
    graph[3][2] = 1;

    DFS(graph, visited, 0);

    return 0;
}
