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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> output;
        if(root == NULL)
            return output;
        if(root->left == NULL && root->right == NULL)
        {
            output.push_back(root->val);
            return output;
        }
        
        stack<TreeNode*> first, second;
        first.push(root);
        while(!first.empty())
        {
            TreeNode* node = first.top();
            first.pop();
            if(node)
            {
                second.push(node);
                if(node->left)
                    first.push(node->left);
                if(node->right)
                    first.push(node->right);
            }
        }
        while(!second.empty())
        {
            output.push_back(second.top()->val);
            second.pop();
        }
        return output;
    }
};
