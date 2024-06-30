#ifndef MAXIMUM_DEPTH_OF_BINARY_TREE_H
#define MAXIMUM_DEPTH_OF_BINARY_TREE_H

#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root);
};

#endif // MAXIMUM_DEPTH_OF_BINARY_TREE_H