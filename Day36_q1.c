#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, count = 0;

void enqueue(int value) {
    if (count == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    count++;
}

void dequeue() {
    if (count == 0) {
        printf("Queue Underflow\n");
        return;
    }
    front = (front + 1) % MAX;
    count--;
}

void display() {
    int i, index = front;
    for (i = 0; i < count; i++) {
        printf("%d ", queue[index]);
        index = (index + 1) % MAX;
    }
}

int main() {
    int n, m, i, x;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}