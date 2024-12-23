
#include <stdio.h>
#define MAX 8

void bfs(int adj[MAX][MAX], int visited[MAX], int start) {
    int queue[MAX], rear = -1, front = -1, i;

    for (i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    queue[++rear] = start;
    ++front;
    visited[start] = 1;


    while (rear >= front) {
        start = queue[front++];
        printf("%d -> ", start);

        for (i = 0; i < MAX; i++) {
            if (adj[start][i] && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("NULL\n");
}



int main() {
    int visited[MAX] = {0};
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
    };

    printf("BFS Traversal\n");
    bfs(adj, visited, 0);

    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }


    return 0;
}

