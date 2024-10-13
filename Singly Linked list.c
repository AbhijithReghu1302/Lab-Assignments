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

void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Node inserted at the front.\n");
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at the end.\n");
}

void insertSorted(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->data < data) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted in sorted order.\n");
}

void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("First node deleted.\n");
}
void deleteBeforePosition(struct Node** head, int pos) {
    if (pos <= 1 || *head == NULL || (*head)->next == NULL) {
        printf("Invalid position or list is too short.\n");
        return;
    }
    struct Node* temp = *head;
    if (pos == 2) {
        *head = temp->next;
        free(temp);
    } else {
        struct Node* prev = NULL;
        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            printf("Position is out of bounds.\n");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
    printf("Node before position %d deleted.\n", pos);
}
void deleteAfterPosition(struct Node** head, int pos) {
    struct Node* temp = *head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position or no node after this position.\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node after position %d deleted.\n", pos);
}
void traverse(struct Node* head) {
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
    int choice, data, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert in sorted order\n");
        printf("4. Delete first node\n");
        printf("5. Delete before position\n");
        printf("6. Delete after position\n");
        printf("7. Traverse list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertSorted(&head, data);
                break;
            case 4:
                deleteFirst(&head);
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteBeforePosition(&head, pos);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAfterPosition(&head, pos);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
