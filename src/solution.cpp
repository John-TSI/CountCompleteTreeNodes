#include"../inc/solution.hpp"


int Solution::countNodes(TreeNode* root)
{
    if(!root){ return 0; }  // handle empty (sub)tree case
    int height{1};  // tree has at least a root node

    TreeNode* leftRoot{root->left}, * rightRoot{root->right};
    bool filledRootLevel{false};  // tracks whether root level is filled ==> tree has maximum number of nodes

    while(true)
    {
        // left/right subtrees have simultaneously stepped below root level, root level must have been filled  
        if(!leftRoot && !rightRoot){ filledRootLevel = true; break; }
        // left/right subtrees differ in depth, need to treat them separately
        if(!leftRoot || !rightRoot){ break; }
        // current level is filled, increment height and step down a level
        ++height;
        leftRoot = leftRoot->left; rightRoot = rightRoot->right;
    }

    // compute number of nodes of completely filled tree, or recursively call for the two subtrees 
    return filledRootLevel ? (1<<height) - 1 : 1 + countNodes(root->left) + countNodes(root->right);
}