#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev; // Pointer to the previous node
    struct node* next; // Pointer to the next node
};

struct node* head = NULL; // Initialize head as NULL

void create() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL; // Initialize prev to NULL
    newnode->next = NULL; // Initialize next to NULL

    if (head == NULL) {
        // If the list is empty, set head to the new node
        head = newnode;
    } else {
        struct node* temp = head; // Start from the head
        // Traverse to the end of the list
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Link the new node to the end of the list
        temp->next = newnode;
        newnode->prev = temp; // Set the prev pointer
    }
}

void insert_end() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insert_beg() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL) {
        head->prev = newnode;
    }
    head = newnode;
}

void insert_position() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0) {
        printf("Position should be greater than 0.\n");
        return;
    }

    if (pos == 1) {
        insert_beg();
        return;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;

    struct node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds. Inserting at the end.\n");
        free(newnode);
        insert_end();
    } else {
        newnode->next = temp->next;
        newnode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
    }
}

void delete_beg() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL; // List had only one node
    }
    free(temp);
}

void delete_position() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0 || head == NULL) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    struct node* temp = head;

    if (pos == 1) {
        delete_beg();
        return;
    }

    for (int i = 1; temp != NULL && i < pos; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

void display() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice = 0; // Initialize choice
    while (choice != 8) {
        printf("\n1. Add node (end)\n2. Add node (beginning)\n3. Add node (position)\n");
        printf("4. Delete node (beginning)\n5. Delete node (end)\n6. Delete node (position)\n");
        printf("7. Display list\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert_end();
                break;
            case 2:
                insert_beg();
                break;
            case 3:
                insert_position();
                break;
            case 4:
                delete_beg();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                delete_position();
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
