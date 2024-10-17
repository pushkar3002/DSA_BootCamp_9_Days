#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void insertFront(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("\nDeque Overflow!");
        return;
    }
    newNode->data = value;
    newNode->next = front;
    newNode->prev = NULL;
    if(front == NULL) {
        front = rear = newNode;
    } else {
        front->prev = newNode;
        front = newNode;
    }
    printf("\nInserted %d at the front", value);
}

void insertRear(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("\nDeque Overflow!");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;
    if(rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\nInserted %d at the rear", value);
}

void deleteFront() {
    if(front == NULL) {
        printf("\nDeque Underflow!");
        return;
    }
    struct Node* temp = front;
    printf("\nDeleted %d from the front", front->data);
    front = front->next;
    if(front == NULL) {
        rear = NULL;
    } else {
        front->prev = NULL;
    }
    free(temp);
}

void deleteRear() {
    if(rear == NULL) {
        printf("\nDeque Underflow!");
        return;
    }
    struct Node* temp = rear;
    printf("\nDeleted %d from the rear", rear->data);
    rear = rear->prev;
    if(rear == NULL) {
        front = NULL;
    } else {
        rear->next = NULL;
    }
    free(temp);
}

void display() {
    if(front == NULL) {
        printf("\nDeque is Empty!");
        return;
    }
    struct Node* temp = front;
    printf("\nDeque elements are:\n");
    while(temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void main() {
    int choice, value;

    while(1) {
        printf("\n\n*** DEQUE MENU ***\n");
        printf("1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter the value to insert at front: ");
                    scanf("%d", &value);
                    insertFront(value);
                    break;
            case 2: printf("Enter the value to insert at rear: ");
                    scanf("%d", &value);
                    insertRear(value);
                    break;
            case 3: deleteFront();
                    break;
            case 4: deleteRear();
                    break;
            case 5: display();
                    break;
            case 6: exit(0);
            default: printf("\nInvalid choice! Try again.");
        }
    }
}
