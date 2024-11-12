#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int count) {
    struct Node* head = NULL;
    struct Node* nextNode = NULL;
    struct Node* temp = NULL;
    int value;

    for (int i = 0; i < count; i++) {
        printf("Enter the value for list: ");
        scanf("%d", &value);

        nextNode = (struct Node*)malloc(sizeof(struct Node));
        if (nextNode == NULL) {
            printf("Memory allocation failed\n");
            return head; // Returning head, which might be NULL
        }
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

void display(struct Node* head) {
    struct Node* temp = head;
    printf("The values in the list are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp = head;
    struct Node* next;
    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    int count;

    printf("Enter the number of values: ");
    scanf("%d", &count);

    struct Node* head = createList(count);
    if (head == NULL) {
        return 1;
    }

    display(head);

    freeList(head);

    return 0;
}
