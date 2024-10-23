#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

struct Node* insert(struct Node* node, int value) {
    if (node == NULL) {
        return createNode(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    } else {
        return node; 
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && value < node->left->data) {
        return rightRotate(node);
    }

    if (balance < -1 && value > node->right->data) {
        return leftRotate(node);
    }

    if (balance > 1 && value > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && value < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            struct Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    
   if (value < root -> data){
       return search(root -> left, value);
   }
   return search(root -> right, value); 
}

void inorder(struct Node* root) {
   if (root != NULL){
       inorder(root -> left);
       printf("%d ", root -> data); 
       inorder(root -> right); 
   }
}

void preorder(struct Node* root){
   if (root != NULL){
       printf("%d ", root -> data); 
       preorder(root -> left); 
       preorder(root -> right); 
   }
}

void postorder(struct Node* root){
   if (root != NULL){
       postorder(root -> left); 
       postorder(root -> right); 
       printf("%d ", root -> data); 
   }
}

void main() { 
   struct Node* root = NULL; 
   int choice, value; 

   while(1){ 
       printf("\n\n*** AVL TREE MENU ***\n"); 
       printf("1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Exit"); 
       printf("\nEnter your choice: "); 
       scanf("%d", &choice); 

       switch(choice){ 
           case 1: printf("Enter value to insert: "); 
                   scanf("%d", &value); 
                   root = insert(root, value); 
                   break; 
           case 2: printf("Enter value to delete: "); 
                   scanf("%d", &value); 
                   root = deleteNode(root, value); 
                   break; 
           case 3: printf("Enter value to search: "); 
                   scanf("%d", &value); 
                   struct Node* result = search(root, value); 
                   if(result != NULL){ 
                       printf("Value %d found in the AVL Tree", value); 
                   } else { 
                       printf("Value %d not found in the AVL Tree", value); 
                   } 
                   break; 
           case 4: printf("\nInorder traversal: "); 
                   inorder(root); 
                   break; 
           case 5: printf("\nPreorder traversal: "); 
                   preorder(root);  
                   break;  
           case 6: printf("\nPostorder traversal: ");  
                   postorder(root);  
                   break;  
           case 7: exit(0);  
           default: printf("Invalid choice! Try again.");  
       }  
   }  
}