#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;  // Pointer to the left child
    struct node* right; // Pointer to the right child
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to insert a node in the BST
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return create_node(data); // Create a new node if root is NULL
    }
    if (data < root->data) {
        root->left = insert(root->left, data); // Insert in the left subtree
    } else {
        root->right = insert(root->right, data); // Insert in the right subtree
    }
    return root;
}

// In-order traversal (Left, Root, Right)
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);    // Traverse left subtree
        printf("%d ", root->data); // Visit the root
        inorder(root->right);   // Traverse right subtree
    }
}

// Pre-order traversal (Root, Left, Right)
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data); // Visit the root
        preorder(root->left);      // Traverse left subtree
        preorder(root->right);     // Traverse right subtree
    }
}

// Post-order traversal (Left, Right, Root)
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);     // Traverse left subtree
        postorder(root->right);    // Traverse right subtree
        printf("%d ", root->data); // Visit the root
    }
}

int main() {
    struct node* root = NULL; // Initialize the root as NULL
    int choice, value;

    while (1) {
        printf("\n1. Insert\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value); // Insert the value into the BST
                break;
            case 2:
                printf("In-order Traversal: ");
                inorder(root); // Perform in-order traversal
                printf("\n");
                break;
            case 3:
                printf("Pre-order Traversal: ");
                preorder(root); // Perform pre-order traversal
                printf("\n");
                break;
            case 4:
                printf("Post-order Traversal: ");
                postorder(root); // Perform post-order traversal
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
