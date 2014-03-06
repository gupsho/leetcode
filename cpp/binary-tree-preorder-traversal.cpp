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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> results;
        if(root == NULL)
            return results;
        
        stack<TreeNode*> st;
        while(!st.empty() || root)
        {
            if(root)
            {
                results.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            else
            {
                TreeNode* temp = st.top();
                st.pop();
                root = temp->right;
            }
        }
        return results;
    }
};
