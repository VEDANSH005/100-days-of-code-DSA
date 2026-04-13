#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Front and Rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    // If queue is empty
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", temp->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Main function
int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char operation[20];
        scanf("%s", operation);

        if (strcmp(operation, "enqueue") == 0) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        }
        else if (strcmp(operation, "dequeue") == 0) {
            dequeue();
        }
    }

    return 0;
}