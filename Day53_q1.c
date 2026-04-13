#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue node (for BFS)
struct QNode {
    struct Node* treeNode;
    int hd;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Simple queue
struct QNode queue[1000];
int front = 0, rear = 0;

void enqueue(struct Node* node, int hd) {
    queue[rear].treeNode = node;
    queue[rear].hd = hd;
    rear++;
}

struct QNode dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    // Map using array (shift index by 500 to handle negative HD)
    int map[1000][100]; // map[hd][values]
    int count[1000] = {0};

    enqueue(root, 500); // shift HD by +500

    int min = 500, max = 500;

    while (!isEmpty()) {
        struct QNode temp = dequeue();
        struct Node* node = temp.treeNode;
        int hd = temp.hd;

        // Store node
        map[hd][count[hd]++] = node->data;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (node->left)
            enqueue(node->left, hd - 1);

        if (node->right)
            enqueue(node->right, hd + 1);
    }

    // Print result
    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}
