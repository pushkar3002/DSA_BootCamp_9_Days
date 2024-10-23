#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    return item;
}

void bfs(int graph[MAX][MAX], int visited[MAX], int start, int n) {
    struct Queue* q = createQueue();
    enqueue(q, start);
    visited[start] = 1;

    while (!isEmpty(q)) {
        int current = dequeue(q);
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(q, i);
                visited[i] = 1;
            }
        }
    }
    free(q);
}

int main() {
    int n, start;
    int graph[MAX][MAX], visited[MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS traversal starting from vertex %d: ", start);
    bfs(graph, visited, start, n);
    printf("\n");

    return 0;
}
