#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int value;
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Circular Queue is full! Cannot insert more elements.\n");
    } else {
        printf("Enter the value to insert: ");
        scanf("%d", &value);
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        queue[rear] = value;
        printf("%d inserted into the circular queue.\n", value);
    }
}

void delete() {
    if (front == -1) {
        printf("Circular Queue is empty! Nothing to delete.\n");
    } else {
        printf("%d deleted from the circular queue.\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Circular Queue is empty! Nothing to display.\n");
    } else {
        printf("Circular Queue elements are:\n");
        if (rear >= front) {
            for (i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (i = front; i < MAX; i++) {
                printf("%d ", queue[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}

void peep() {
    if (front == -1) {
        printf("Circular Queue is empty! Nothing to peep.\n");
    } else {
        printf("Front element is %d.\n", queue[front]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. DISPLAY\n");
        printf("4. PEEP\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: peep(); break;
            case 5: printf("Exiting program.\n"); return 0;
            default: printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}
