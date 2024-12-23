#include <stdio.h>

#define MAX 100

void dfs(int adj[MAX][MAX], int visited[MAX], int start, int n) {
    int stack[MAX], top = -1;
    int i;

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    stack[++top] = start;
    visited[start] = 1;

    printf("DFS Traversal: ");

    while (top != -1) {
        int current = stack[top--];
        printf("%d -> ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }

    printf("NULL\n");
}

int main() {
    int n = 5;
    int adj[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };
    int visited[MAX];

    int start = 0;
    dfs(adj, visited, start, n);

    return 0;
}

