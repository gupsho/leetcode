/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if(root == NULL)
            return true;
        isBST(root, INT_MIN, INT_MAX);
    }
    
private:
    bool isBST(TreeNode* root, int min, int max)
    {
        if(root == NULL)
            return true;
        if((root->val > min && root->val < max ) || (root->val > min && root->val < max))
            return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
        else
            return false;
    }
};
