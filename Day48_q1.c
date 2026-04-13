#include <stdio.h>
#include <stdlib.h>

// Structure of Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to count leaf nodes
int countLeafNodes(struct TreeNode* root) {
    // Base case
    if (root == NULL)
        return 0;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Recursively count in left and right subtree
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}