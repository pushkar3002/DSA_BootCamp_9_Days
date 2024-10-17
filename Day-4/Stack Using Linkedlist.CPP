#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("\nStack Overflow!");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("\nInserted %d", value);
}

void pop() {
    if(top == NULL) {
        printf("\nStack Underflow!");
        return;
    }
    struct Node* temp = top;
    printf("\nPopped %d", top->data);
    top = top->next;
    free(temp);
}

void display() {
    if(top == NULL) {
        printf("\nStack is Empty!");
        return;
    }
    struct Node* temp = top;
    printf("\nStack elements are:\n");
    while(temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void main() {
    int choice, value;

    while(1) {
        printf("\n\n*** STACK MENU ***\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter the value to push: ");
                    scanf("%d", &value);
                    push(value);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice! Try again.");
        }
    }
}
