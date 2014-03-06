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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> results;
        if(root == NULL)
                return results;
        stack<TreeNode*> st;
        st.push(root);
        root = root->left;

        while(!st.empty() || root)
        {
                if(root)
                {
                        st.push(root);
                        root = root->left;
                }
                else
                {
                        TreeNode* temp = st.top();
                        st.pop();
                        results.push_back(temp->val);
                        root = temp->right;
                }
        }
        
        return results;
        
    }
};
