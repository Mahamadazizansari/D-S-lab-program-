#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
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

struct Node* deleteFirst(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. No element to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteElement(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* previous = NULL;
    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Element %d not found in the list.\n", key);
        return head;
    }
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    return head;
}

struct Node* deleteLast(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. No element to delete.\n");
        return NULL;
    }
    struct Node* current = head;
    struct Node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        free(current);
        return NULL;
    }
    previous->next = NULL;
    free(current);
    return head;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("1. Insert at end\n");
        printf("2. Delete first element\n");
        printf("3. Delete specified element\n");
        printf("4. Delete last element\n");
        printf("5. Display \n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 2:
                head = deleteFirst(head);
                printf("After deleting first element: ");
                displayList(head);
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                head = deleteElement(head, data);
                break;
            case 4:
                head = deleteLast(head);
                printf("After deleting last element: ");
                displayList(head);
                break;
            case 5:
                printf("Linked List contents:\n");
                displayList(head);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);
return 0;
}
