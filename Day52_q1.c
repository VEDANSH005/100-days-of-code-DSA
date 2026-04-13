#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// LCA function
struct TreeNode* findLCA(struct TreeNode* root, int p, int q) {
    // Base case
    if (root == NULL)
        return NULL;

    if (root->val == p || root->val == q)
        return root;

    // Recurse left & right
    struct TreeNode* left = findLCA(root->left, p, q);
    struct TreeNode* right = findLCA(root->right, p, q);

    // If both sides return non-null → this is LCA
    if (left != NULL && right != NULL)
        return root;

    // Otherwise return non-null side
    return (left != NULL) ? left : right;
}