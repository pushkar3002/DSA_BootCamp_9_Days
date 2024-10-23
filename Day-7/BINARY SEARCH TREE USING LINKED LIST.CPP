#include <stdio.h>
#include <stdlib.h>

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

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

void main() {
    struct Node* root = NULL;
    int choice, value;
    struct Node* result;

    while(1) {
        printf("\n\n*** BINARY SEARCH TREE MENU ***\n");
        printf("1. Insert\n2. Search\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2: 
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = search(root, value);
                if (result != NULL) {
                    printf("\nValue %d found in the BST", value);
                } else {
                    printf("\nValue %d not found in the BST", value);
                }
                break;
            case 3: 
                printf("\nInorder traversal: ");
                inorder(root);
                break;
            case 4: 
                printf("\nPreorder traversal: ");
                preorder(root);
                break;
            case 5: 
                printf("\nPostorder traversal: ");
                postorder(root);
                break;
            case 6: 
                exit(0);
            default: 
                printf("\nInvalid choice! Try again.");
        }
    }
}