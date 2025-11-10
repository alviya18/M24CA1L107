#include <stdio.h>

struct Edge {
    int u, v, w;
};

int parent[50];

int find(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int vertices, no_of_edges, minCost = 0, count = 0;
    int i, j, u, v, w, a, b;
    struct Edge edges[50], temp;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &vertices);
    printf("\nEnter the number of edges in the graph: ");
    scanf("%d", &no_of_edges);

    printf("\nEnter the edges and their weights (u v w):");
    for (i = 0; i < no_of_edges; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Sort edges by weight (Bubble Sort)
    for (i = 0; i < no_of_edges - 1; i++) {
        for (j = 0; j < no_of_edges - 1 - i; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // Initialize parent array
    for (i = 0; i < vertices; i++) {
        parent[i] = i;
    }

    printf("Edges in the Minimum Cost Spanning Tree:\n");

    i = 0;
    while (count < vertices - 1 && i < no_of_edges) {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        a = find(u);
        b = find(v);

        if (a != b) {
            printf("(%d, %d) : %d\n", u, v, w);
            unionSet(a, b);
            minCost += w;
            count++;
        }
        i++;
    }

    printf("\nMinimum Cost: %d\n", minCost);

    return 0;
}

