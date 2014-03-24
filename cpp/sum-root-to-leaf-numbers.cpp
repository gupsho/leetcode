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
    int sumNumbers(TreeNode *root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return root->val;
        if(root->left == NULL)
            return sumPath(root->right, root->val);
        else if(root->right == NULL)
            return sumPath(root->left, root->val);
        else
            return sumPath(root->left, root->val) + sumPath(root->right, root->val);
    }
    
    int sumPath(TreeNode* root, int currentSum)
    {
        int sum = currentSum*10 + root->val;
        if(root->left == NULL && root->right == NULL)
            return sum;
        if(root->left == NULL)
            return sumPath(root->right, sum);
        else if(root->right == NULL)
            return sumPath(root->left, sum);
        else
            return sumPath(root->left, sum) + sumPath(root->right, sum);
    }
};
