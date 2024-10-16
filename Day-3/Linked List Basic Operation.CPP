#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create(int value);
void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertAfterNode(int value, int afterValue);
void deleteFromBeginning();
void deleteFromEnd();
void deleteSpecificNode(int value);
void display();

void main() {
    int choice, value, afterValue;

    while(1){
        printf("\n\n*** LINKED LIST MENU ***\n");
        printf("1. Create\n2. Insert at Beginning\n3. Insert at End\n4. Insert After Node\n5. Delete from Beginning\n6. Delete from End\n7. Delete Specific Node\n8. Display\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        
        switch(choice) {
            case 1: 
                    printf("Enter the value to create a new node: ");
                    scanf("%d", &value);
                    create(value);
                    break;
            case 2: 
                    printf("Enter the value to insert at beginning: ");
                    scanf("%d", &value);
                    insertAtBeginning(value);
                    break;
            case 3: 
                    printf("Enter the value to insert at end: ");
                    scanf("%d", &value);
                    insertAtEnd(value);
                    break;
            case 4: 
                    printf("Enter the value to insert: ");
                    scanf("%d", &value);
                    printf("Enter the value after which to insert: ");
                    scanf("%d", &afterValue);
                    insertAfterNode(value, afterValue);
                    break;
            case 5: 
                    deleteFromBeginning();
                    break;
            case 6: 
                    deleteFromEnd();
                    break;
            case 7: 
                    printf("Enter the value of the node to delete: ");
                    scanf("%d", &value);
                    deleteSpecificNode(value);
                    break;
            case 8: 
                    display();
                    break;
            case 9: 
                    exit(0);
            default: 
                    printf("\nWrong choice! Please try again.");
        }
    }
}

void create(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if(head == NULL) {
        head = newNode;
        printf("\nNode created successfully!");
    } else {
        printf("\nLinked List already created!");
    }
}

void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("\nNode inserted at beginning!");
}

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("\nNode inserted at end!");
}

void insertAfterNode(int value, int afterValue) {
    struct Node* temp = head;
    while(temp != NULL && temp->data != afterValue) {
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("\nNode with value %d not found!", afterValue);
    } else {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        printf("\nNode inserted after %d!", afterValue);
    }
}

void deleteFromBeginning() {
    if(head == NULL) {
        printf("\nList is empty, nothing to delete!");
    } else {
        struct Node* temp = head;
        head = head->next;
        printf("\nDeleted node with value: %d", temp->data);
        free(temp);
    }
}

void deleteFromEnd() {
    if(head == NULL) {
        printf("\nList is empty, nothing to delete!");
    } else if(head->next == NULL) {
        printf("\nDeleted node with value: %d", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        struct Node* prev = NULL;

        while(temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("\nDeleted node with value: %d", temp->data);
        free(temp);
    }
}

void deleteSpecificNode(int value) {
    if(head == NULL) {
        printf("\nList is empty, nothing to delete!");
    } else if(head->data == value) {
        struct Node* temp = head;
        head = head->next;
        printf("\nDeleted node with value: %d", temp->data);
        free(temp);
    } else {
        struct Node* temp = head;
        struct Node* prev = NULL;

        while(temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL) {
            printf("\nNode with value %d not found!", value);
        } else {
            prev->next = temp->next;
            printf("\nDeleted node with value: %d", temp->data);
            free(temp);
        }
    }
}

void display() {
    if(head == NULL) {
        printf("\nList is empty!");
    } else {
        struct Node* temp = head;
        printf("\nLinked List elements are: ");
        while(temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
}