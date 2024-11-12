#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create the initial deque
struct Node* createQueue(int count) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int value;

    for (int i = 0; i < count; i++) {
        printf("Enter the value for Input Restricted Deque: ");
        scanf("%d", &value);

        struct Node* nextNode = (struct Node*)malloc(sizeof(struct Node));
        nextNode->data = value;
        nextNode->next = NULL;

        if (head == NULL) {
            head = nextNode;
        } else {
            temp->next = nextNode;
        }
        temp = nextNode;
    }
    return head;
}

// Function to insert at the rear
struct Node* insertRear(struct Node* head, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to delete from the front
struct Node* deleteFront(struct Node* head) {
    if (head == NULL) {
        printf("Input restricted deque is empty\n");
        return head;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete from the rear
struct Node* deleteRear(struct Node* head) {
    if (head == NULL) {
        printf("Input restricted deque is empty\n");
        return head;
    }

    if (head->next == NULL) { // Only one element
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL; // Remove the last node
    free(temp);
    return head;
}

// Function to display the deque
void display(struct Node* head) {
    struct Node* temp = head;
    printf("The values in the Input Restricted Deque are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice = 0, element, count;

    printf("Enter the number of values to create the Input Restricted Deque: ");
    scanf("%d", &count);
    head = createQueue(count);

    while (choice != 5) {
        printf("\nMenu:\n");
        printf("1. Insert at rear\n");
        printf("2. Delete from front\n");
        printf("3. Delete from rear\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the end: ");
                scanf("%d", &element);
                head = insertRear(head, element);
                break;
            case 2:
                head = deleteFront(head);
                break;
            case 3:
                head = deleteRear(head);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
