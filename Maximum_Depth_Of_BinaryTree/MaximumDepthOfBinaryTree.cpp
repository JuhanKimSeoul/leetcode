#include <vector>
#include "MaximumDepthOfBinaryTree.h"

using namespace std;

int Solution::maxDepth(TreeNode* root){
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    int level = 0; 

    if(root == nullptr){
        return level;
    }

    while(nodes.size() > 0){
        level++;
        vector<TreeNode*> nextLevel;
        while(nodes.size() > 0){
            TreeNode* t = nodes.back();
            nodes.pop_back();
            if(t->left != nullptr){
                nextLevel.push_back(t->left);
            }
            if(t->right != nullptr){
                nextLevel.push_back(t->right);
            }
        }
        nodes = nextLevel;
    }

    return level;
};