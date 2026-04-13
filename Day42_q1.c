#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Queue implementation
int queue[MAX];
int front = 0, rear = -1;

// Stack implementation
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// Pop from stack
int pop() {
    return stack[top--];
}

int main() {
    int N;
    scanf("%d", &N);

    // Input elements into queue
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Queue → Stack
    while (front <= rear) {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Stack → Queue (reversed)
    while (top >= 0) {
        enqueue(pop());
    }

    // Output reversed queue
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}