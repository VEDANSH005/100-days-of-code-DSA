#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Zigzag Traversal
void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;

        int* level = (int*)malloc(sizeof(int) * size);

        for (int i = 0; i < size; i++) {
            struct Node* node = queue[front++];

            // decide index based on direction
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->data;

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }

        // print current level
        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        free(level);

        // toggle direction
        leftToRight = !leftToRight;
    }
}