#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
int data[MAX];
int front;
int rear;
} CircularQueue;

void initializeQueue(CircularQueue *q) {
q->front = -1;
q->rear = -1;
}

int isFull(CircularQueue *q) {
return (q->rear + 1) % MAX == q->front;
}

int isEmpty(CircularQueue *q) {
return q->front == -1;
}

void insert(CircularQueue *q, int value) {
if (isFull(q)) {
printf("Queue Overflow! Cannot insert %d\n", value);
return;
}
if (isEmpty(q)) {
q->front = 0;
}
q->rear = (q->rear + 1) % MAX;
q->data[q->rear] = value;
printf("Inserted %d into the queue\n", value);
}

int delete(CircularQueue *q) {
if (isEmpty(q)) {
printf("Queue Underflow! Cannot delete\n");
return -1;
}
int value = q->data[q->front];
if (q->front == q->rear) {
q->front = -1;
q->rear = -1;
} else {
q->front = (q->front + 1) % MAX;
}
printf("Deleted %d from the queue\n", value);
return value;
}

void display(CircularQueue *q) {
if (isEmpty(q)) {
printf("Queue is empty\n");
return;
}
printf("Queue elements: ");
int i = q->front;
while (1) {
printf("%d ", q->data[i]);
if (i == q->rear) break;
i = (i + 1) % MAX;
}
printf("\n");
}

int main() {
CircularQueue q;
initializeQueue(&q);
int choice, value;

while (1) {
printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit");
printf("\nChoose an operation: ");
scanf("%d", &choice);

switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(&q, value);
            break;
        case 2:
            delete(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice, please try again.\n");
    }
}
}
