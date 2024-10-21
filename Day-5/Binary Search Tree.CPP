#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void main() {
    struct Node* root = NULL;
    int choice, value;
    struct Node* result;

    while(1) {
        printf("\n\n*** BST MENU ***\n");
        printf("1. Insert\n2. Search\n3. Display Inorder\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter value to insert: ");
                    scanf("%d", &value);
                    root = insert(root, value);
                    break;
            case 2: printf("Enter value to search: ");
                    scanf("%d", &value);
                    result = search(root, value);
                    if (result != NULL) {
                        printf("\nValue %d found in the BST", value);
                    } else {
                        printf("\nValue %d not found in the BST", value);
                    }
                    break;
            case 3: printf("\nInorder traversal of BST: ");
                    inorder(root);
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice! Try again.");
        }
    }
}
