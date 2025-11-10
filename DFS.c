#include <stdio.h>

#define MAX 10

int stack[MAX], visited[MAX], adj[MAX][MAX];
int top = -1, n;

void push(int item) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void DFS(int adj[MAX][MAX], int n, int start) {
    int vertex, i;
    push(start);
    visited[start] = 1;
    printf("DFS Traversal starting from vertex %d:\n", start);

    while (top != -1) {
        vertex = pop();
        printf("%d ", vertex);

        // Visit adjacent vertices in reverse order
        for (i = n - 1; i >= 0; i--) {
            if (adj[vertex][i] == 1 && visited[i] == 0) {
                push(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex : ");
    scanf("%d", &start);

    DFS(adj, n, start);

    return 0;
}

