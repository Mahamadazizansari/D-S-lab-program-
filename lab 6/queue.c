#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** stack, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *stack;
    *stack = new_node;
}

int pop(struct Node** stack) {
    if (*stack == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct Node* temp = *stack;
    *stack = (*stack)->next;
    int data = temp->data;
    free(temp);
    return data;
}

void enqueue(struct Node** queue, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*queue == NULL) {
        *queue = new_node;
    } else {
        struct Node* temp = *queue;
        while (temp->next) temp = temp->next;
        temp->next = new_node;
    }
}

int dequeue(struct Node** queue) {
    if (*queue == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = *queue;
    *queue = (*queue)->next;
    int data = temp->data;
    free(temp);
    return data;
}

void display(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* stack = NULL;
    struct Node* queue = NULL;
    int n, data;

    printf("Enter the number of elements for the Stack: ");
    scanf("%d", &n);
    printf("Enter elements for the Stack):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        push(&stack, data);
    }

    printf("Stack: ");
    display(stack);
    printf("Popped: %d\n", pop(&stack));
    display(stack);

    printf("Enter the number of elements for the Queue: ");
    scanf("%d", &n);
    printf("Enter elements for the Queue:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(&queue, data);
    }

    printf("Queue: ");
    display(queue);
    printf("Dequeued: %d\n", dequeue(&queue));
    display(queue);

    return 0;
}
