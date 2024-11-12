#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next; // Pointer to the next node
};

struct node* head = NULL; // Initialize head as NULL

// Function to create a new node
struct node* create_node(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL; // The next pointer will be linked properly in the insertion functions
    return newnode;
}

// Insert a new node at the end of the list
void insert_end()
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    struct node* newnode = create_node(data);

    if (head == NULL) {
        head = newnode;  // If the list is empty, new node becomes head
        head->next = head; // Circular link (points to itself)
    } else {
        struct node* temp = head;
        while (temp->next != head) { // Traverse till the last node
            temp = temp->next;
        }
        temp->next = newnode; // Link last node to new node
        newnode->next = head; // Make the new node's next point to head, maintaining circularity
    }
}

// Insert a new node at the beginning of the list
void insert_beg() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    struct node* newnode = create_node(data);

    if (head == NULL) {
        head = newnode;  // If the list is empty, new node becomes head
        head->next = head; // Circular link (points to itself)
    } else {
        struct node* temp = head;
        while (temp->next != head) { // Traverse till the last node
            temp = temp->next;
        }
        temp->next = newnode; // Link the last node to new node
        newnode->next = head; // Make the new node's next point to head, maintaining circularity
        head = newnode;       // Move head to the new node
    }
}

// Insert a new node at a specific position
void insert_position() {
    int pos, data;
    printf("Enter position: ");
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &data);

    struct node* newnode = create_node(data);

    if (pos <= 0) {
        printf("Position should be greater than 0.\n");
        free(newnode);
        return;
    }

    if (pos == 1) {
        insert_beg(); // If position is 1, insert at the beginning
        return;
    }

    if (head == NULL) {
        printf("List is empty. Inserting at the end.\n");
        insert_end();
        return;
    }

    struct node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of bounds. Inserting at the end.\n");
            insert_end();
            return;
        }
    }

    newnode->next = temp->next; // Link new node's next to the current node's next
    temp->next = newnode;       // Link the current node to the new node
}

// Delete the first node
void delete_beg() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == head) { // Only one node in the list
        free(head);
        head = NULL;
    } else {
        struct node* temp = head;
        struct node* last = head;
        while (last->next != head) { // Find the last node
            last = last->next;
        }
        head = head->next; // Move head to next node
        last->next = head; // Update last node's next to new head
        free(temp); // Free the old head
    }
}

// Delete the last node
void delete_end() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == head) { // Only one node in the list
        free(head);
        head = NULL;
    } else {
        struct node* temp = head;
        while (temp->next->next != head) { // Find the second last node
            temp = temp->next;
        }
        free(temp->next); // Free the last node
        temp->next = head; // Update second last node's next to head
    }
}

// Delete a node at a specific position
void delete_position() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0 || head == NULL) {
        printf("Invalid position or list is empty.\n");
        return;
    }

    if (pos == 1) {
        delete_beg();
        return;
    }

    struct node* temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of bounds.\n");
            return;
        }
    }

    struct node* to_delete = temp->next;
    temp->next = to_delete->next; // Link current node to the next of the node to be deleted
    free(to_delete); // Free the node
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice = 0;
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
