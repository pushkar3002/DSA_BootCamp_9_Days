#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_QUEUE_SIZE 20


typedef struct {
    int front;
    int rear;
    int items[MAX_QUEUE_SIZE];
} Queue;


Queue* createQueue();
int isFull(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, int floor);
int dequeue(Queue* q);
void displayQueue(Queue* q);
void manageLift(Queue* q);

int main() {
    Queue* queue = createQueue();
    int choice, floor;

    while (1) {
        printf("\nLift Management System\n");
        printf("1. Request Lift\n");
        printf("2. Show Requests\n");
        printf("3. Manage Lift\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter floor number (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                if (floor >= 0 && floor < MAX_FLOORS) {
                    enqueue(queue, floor);
                    printf("Lift requested from floor %d.\n", floor);
                } else {
                    printf("Invalid floor number!\n");
                }
                break;
            case 2:
                displayQueue(queue);
                break;
            case 3:
                manageLift(queue);
                break;
            case 4:
                free(queue);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}


int isFull(Queue* q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}


int isEmpty(Queue* q) {
    return q->front == -1;
}


void enqueue(Queue* q, int floor) {
    if (isFull(q)) {
        printf("Request queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->items[q->rear] = floor;
}


int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("No requests in the queue!\n");
        return -1; // Indicating no requests
    }
    int floor = q->items[q->front];
    if (q->front == q->rear) { // Queue has only one element
        q->front = -1; // Resetting queue
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    return floor;
}


void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("No requests in the queue.\n");
        return;
    }
    
    printf("Current requests in the queue: ");
    
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    
    printf("\n");
}


void manageLift(Queue* q) {
    while (!isEmpty(q)) {
        int nextFloor = dequeue(q);
        printf("Lift moving to floor %d...\n", nextFloor);
        // Simulate some delay for moving between floors
        for (int i = 0; i < 100000000; i++); // Simple delay loop
        printf("Lift arrived at floor %d.\n", nextFloor);
    }
}