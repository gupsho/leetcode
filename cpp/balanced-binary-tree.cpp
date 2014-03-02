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
    bool isBalanced(TreeNode *root) {
        if(!root)
            return true;
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        if(abs(lheight - rheight) > 1 )
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
private:
    int height(TreeNode* root) {
        if(!root)
            return 0;
        else return (1 + max(height(root->left), height(root->right)));
    }
};
