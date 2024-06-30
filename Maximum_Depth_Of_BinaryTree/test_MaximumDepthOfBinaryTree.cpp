#include <cassert>
#include "MaximumDepthOfBinaryTree.h"

int main() {
    // Test case 1: Empty tree
    Solution solution;
    TreeNode* root = nullptr;
    assert(solution.maxDepth(root) == 0);

    // Test case 2: Single node tree
    root = new TreeNode(1);
    assert(solution.maxDepth(root) == 1);

    // Test case 3: Tree with multiple levels
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    assert(solution.maxDepth(root) == 3);

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}