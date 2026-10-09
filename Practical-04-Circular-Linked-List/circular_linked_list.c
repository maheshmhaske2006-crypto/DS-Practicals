
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *last = head;

        while (last->next != head) {
            last = last->next;
        }

        newNode->next = head;
        last->next = newNode;
        head = newNode;
    }

    printf("%d inserted at beginning.\n", value);
}

void insertEnd(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *last = head;

        while (last->next != head) {
            last = last->next;
        }

        last->next = newNode;
        newNode->next = head;
    }

    printf("%d inserted at end.\n", value);
}

void deleteValue(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *current = head;
    struct Node *previous = NULL;

    do {
        if (current->data == value) {
            break;
        }

        previous = current;
        current = current->next;
    } while (current != head);

    if (current->data != value) {
        printf("%d not found.\n", value);
        return;
    }

    /* Only one node */
    if (current == head && head->next == head) {
        head = NULL;
    }
    /* Deleting the first node */
    else if (current == head) {
        struct Node *last = head;

        while (last->next != head) {
            last = last->next;
        }

        head = head->next;
        last->next = head;
    }
    /* Deleting any other node */
    else {
        previous->next = current->next;
    }

    free(current);
    printf("%d deleted successfully.\n", value);
}

void display(void) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

void freeList(void) {
    if (head == NULL) {
        return;
    }

    struct Node *current = head->next;

    while (current != head) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    free(head);
    head = NULL;
}

int main(void) {
    int choice, value;

    while (1) {
        printf("\n--- Circular Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete by Value\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            freeList();
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    freeList();
                    return 1;
                }
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    freeList();
                    return 1;
                }
                insertEnd(value);
                break;

            case 3:
                printf("Enter value to delete: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    freeList();
                    return 1;
                }
                deleteValue(value);
                break;

            case 4:
                display();
                break;

            case 5:
                freeList();
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}