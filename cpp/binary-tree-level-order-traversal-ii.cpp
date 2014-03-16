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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > output, reverse;
        if(root == NULL)
            return output;
        
        TreeNode* DUMMY = NULL;
        queue<TreeNode*> q;
        q.push(root);
        q.push(DUMMY);
        while(q.front() != NULL)
        {
            vector<int> level;
            level.clear();
            while(true)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp == NULL)
                {
                    q.push(DUMMY);
                    reverse.push_back(level);
                    break;
                }
            
                level.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        
        for(int i = reverse.size() - 1 ; i >= 0;  i--)
        {
            output.push_back(reverse[i]);
        }
        return output;
    }
};
