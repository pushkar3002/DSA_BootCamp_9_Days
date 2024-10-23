#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Graph {
    int adj[MAX][MAX];
    int n;
};

void initGraph(struct Graph* g, int vertices) {
    g->n = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void insertEdge(struct Graph* g, int u, int v, int weight) {
    g->adj[u][v] = weight;
    g->adj[v][u] = weight;
}

void deleteEdge(struct Graph* g, int u, int v) {
    g->adj[u][v] = 0;
    g->adj[v][u] = 0;
}

int searchEdge(struct Graph* g, int u, int v) {
    return g->adj[u][v];
}

void BFS(struct Graph* g, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;
    queue[++rear] = start;
    visited[start] = 1;

    while (front <= rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < g->n; i++) {
            if (g->adj[v][i] && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void DFSUtil(struct Graph* g, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < g->n; i++) {
        if (g->adj[v][i] && !visited[i]) {
            DFSUtil(g, i, visited);
        }
    }
}

void DFS(struct Graph* g, int start) {
    int visited[MAX] = {0};
    DFSUtil(g, start, visited);
}

void dijkstra(struct Graph* g, int src) {
    int dist[MAX], visited[MAX];
    for (int i = 0; i < g->n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < g->n - 1; count++) {
        int min = INT_MAX, u;
        for (int v = 0; v < g->n; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }
        visited[u] = 1;

        for (int v = 0; v < g->n; v++) {
            if (!visited[v] && g->adj[u][v] && dist[u] != INT_MAX && dist[u] + g->adj[u][v] < dist[v]) {
                dist[v] = dist[u] + g->adj[u][v];
            }
        }
    }

    printf("Vertex Distance from Source %d:\n", src);
    for (int i = 0; i < g->n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    struct Graph g;
    int vertices, choice, u, v, weight;

    printf("Enter number of vertices in the graph: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);

    while (1) {
        printf("\n*** GRAPH MENU ***\n");
        printf("1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. BFS\n5. DFS\n6. Dijkstra's Shortest Path\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the vertices (u, v) and weight to insert an edge: ");
                scanf("%d %d %d", &u, &v, &weight);
                insertEdge(&g, u, v, weight);
                break;
            case 2:
                printf("Enter the vertices (u, v) to delete an edge: ");
                scanf("%d %d", &u, &v);
                deleteEdge(&g, u, v);
                break;
            case 3:
                printf("Enter the vertices (u, v) to search for an edge: ");
                scanf("%d %d", &u, &v);
                if (searchEdge(&g, u, v)) {
                    printf("Edge exists between %d and %d\n", u, v);
                } else {
                    printf("Edge does not exist between %d and %d\n", u, v);
                }
                break;
            case 4:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &u);
                printf("BFS traversal: ");
                BFS(&g, u);
                printf("\n");
                break;
            case 5:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &u);
                printf("DFS traversal: ");
                DFS(&g, u);
                printf("\n");
                break;
            case 6:
                printf("Enter source vertex for Dijkstra's shortest path: ");
                scanf("%d", &u);
                dijkstra(&g, u);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
