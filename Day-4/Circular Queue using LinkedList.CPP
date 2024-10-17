#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("\nQueue Overflow!");
        return;
    }
    newNode->data = value;
    if(front == NULL) {
        front = rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("\nInserted %d", value);
}

void dequeue() {
    if(front == NULL) {
        printf("\nQueue Underflow!");
        return;
    }
    struct Node* temp = front;
    if(front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    printf("\nDeleted %d", temp->data);
    free(temp);
}

void display() {
    if(front == NULL) {
        printf("\nQueue is Empty!");
        return;
    }
    struct Node* temp = front;
    printf("\nQueue elements are:\n");
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while(temp != front);
}

void main() {
    int choice, value;

    while(1) {
        printf("\n\n*** CIRCULAR QUEUE MENU ***\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter the value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(value);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice! Try again.");
        }
    }
}
