#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void printReverse(struct Node* node) {
    if(node == NULL) {
        return;
    }
    printReverse(node->next);
    printf("%d\n", node->data);
}

void display() {
    if(head == NULL) {
        printf("\nLinked List is Empty!");
        return;
    }
    printf("\nLinked List in reverse order:\n");
    printReverse(head);
}

void main() {
    int choice, value;

    while(1) {
        printf("\n\n*** LINKED LIST MENU ***\n");
        printf("1. Insert\n2. Print in Reverse\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter the value to insert: ");
                    scanf("%d", &value);
                    insert(value);
                    break;
            case 2: display();
                    break;
            case 3: exit(0);
            default: printf("\nInvalid choice! Try again.");
        }
    }
}
