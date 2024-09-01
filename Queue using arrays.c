#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;
void insert() {
    int value;
    if (rear == MAX - 1) {
        printf("Queue is full! Cannot insert more elements.\n");
    } else {
        printf("Enter the value to insert: ");
        scanf("%d", &value);
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted into the queue.\n", value);
    }
}
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue is empty! Nothing to delete.\n");
    } else {
        printf("%d deleted from the queue.\n", queue[front]);
        front++;
        if (front > rear) front = rear = -1;
    }
}
void traversal() {
    int i;
    if (front == -1) {
        printf("Queue is empty! Nothing to display.\n");
    } else {
        printf("Queue elements are:\n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
void peep() {
    if (front == -1) {
        printf("Queue is empty! Nothing to peep.\n");
    } else {
        printf("Front element is %d.\n", queue[front]);
    }
}
int main() {
    int choice;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. TRAVERSAL\n");
        printf("4. PEEP\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: traversal(); break;
            case 4: peep(); break;
            case 5: printf("Exiting program.\n"); return 0;
            default: printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}
