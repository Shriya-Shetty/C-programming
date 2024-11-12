#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

int main() {
    struct node* head = NULL;
    struct node* temp1 = NULL;
    struct node* temp2 = NULL;

    // Create the head node
    head = malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;

    // Create temp1 node
    temp1 = malloc(sizeof(struct node));
    temp1->data = 2;
    temp1->link = NULL;

    // Create temp2 node
    temp2 = malloc(sizeof(struct node));
    temp2->data = 3;
    temp2->link = NULL;

    // Link the nodes
    head->link = temp1;
    temp1->link = temp2;

    // Print the list
    struct node* ptr = head;
    if (head==NULL)
    {
        printf("empty");
    }
    while (ptr != NULL) {
        printf("%d\n", ptr->data); // Correctly print the data
        ptr = ptr->link; // Move to the next node
    }

    // Free the allocated memory (optional but good practice)
    free(temp2);
    free(temp1);
    free(head);

    return 0;
}
