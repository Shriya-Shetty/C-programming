#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

void display(struct node* head) {
    struct node* ptr = head;
    if (head == NULL) {
        printf("empty\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d\n", ptr->data); // Print the data
        ptr = ptr->link; // Move to the next node
    }
}

void insertend(struct node* head, int data) {
    // Create a new node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    if (head == NULL) {
        // If the list is empty, return since we can't insert
        printf("The list is empty. Please initialize the head pointer.\n");
        return;
    }

    // Traverse to the end of the list
    struct node* ptr = head;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    // Link the new node at the end
    ptr->link = temp;
}

struct node* insertbeg(struct node* head, int data)
{
    // Create a new node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = head;

    if (head == NULL) {
        // If the list is empty, return since we can't insert
        printf("The list is empty. Please initialize the head pointer.\n");
        return;
    }

    // Traverse to the end of the list
    return temp;
}

void insertpos(struct node* head, int data,int position)
{
    // Create a new node
    int count=position;
    struct node* ptr=head;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while(count!=1)
    {
        ptr=ptr->link;
        count--;
    }
    ptr->link=temp;
    temp->link=ptr->link;

}
int main() {
    struct node* head = NULL; // Initialize head to NULL

    // Allocate memory for the head node and initialize it
    head = (struct node*)malloc(sizeof(struct node));
    if (head == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }
    head->data = 22; // Initialize the head node's data
    head->link = NULL; // Set the link to NULL

    // Display the list
    display(head);

    // Insert a new value
    insertend(head, 42); // Insert 42 into the linked list

    head=insertbeg(head, 44);

    // Display the updated list
    display(head);

    insertpos(head,3,2);

    display(head);

    return 0;
}
