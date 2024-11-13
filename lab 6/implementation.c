#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void sort(struct Node* head) {
    struct Node *i, *j;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverse(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void concatenate(struct Node** head1, struct Node* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int n, data, choice;
printf("\nMenu:\n");
        printf("1. Insert elements in List 1\n");
        printf("2. Insert elements in List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 1 and List 2\n");
        printf("8. Exit\n");
    while (1) {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements for List 1: ");
                scanf("%d", &n);
                printf("Enter elements for List 1:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &data);
                    insert(&list1, data);
                }
                break;
            case 2:
                printf("Enter the number of elements for List 2: ");
                scanf("%d", &n);
                printf("Enter elements for List 2:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &data);
                    insert(&list2, data);
                }
                break;
            case 3:
                printf("List 1: ");
                display(list1);
                break;
            case 4:
                printf("List 2: ");
                display(list2);
                break;
            case 5:
                sort(list1);
                printf("Sorted List 1: ");
                display(list1);
                break;
            case 6:
                reverse(&list1);
                printf("Reversed List 1: ");
                display(list1);
                break;
            case 7:
                concatenate(&list1, list2);
                printf("Concatenated List: ");
                display(list1);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

