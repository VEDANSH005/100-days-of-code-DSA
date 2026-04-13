#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate height
int height(struct Node* root) {
    // Base case
    if (root == NULL)
        return 0;

    // Recursively find height of left and right
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Return max + 1
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Driver code
int main() {
    // Example Tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Height of tree: %d\n", height(root));

    return 0;
}