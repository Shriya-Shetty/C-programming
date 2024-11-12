#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top];
}

struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

void enqueue(struct Queue* queue, int item) {
    push(queue->stack1, item);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    return pop(queue->stack2);
}

void displayQueue(struct Queue* queue) {
    if (isEmpty(queue->stack1) && isEmpty(queue->stack2)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    for (int i = queue->stack2->top; i >= 0; i--) {
        printf("%d ", queue->stack2->array[i]);
    }

    for (int i = 0; i <= queue->stack1->top; i++) {
        printf("%d ", queue->stack1->array[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(5);
    int choice, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to enqueue: ");
                scanf("%d", &element);
                enqueue(queue, element);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue(queue));
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                printf("Exits\n");
                free(queue->stack1->array);
                free(queue->stack1);
                free(queue->stack2->array);
                free(queue->stack2);
                free(queue);
                return 0;
            default:
                printf("Invalid\n");
        }
    }
}
