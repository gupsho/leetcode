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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > levels;
        if(!root)
            return levels;
            
        queue<TreeNode*> que;
        TreeNode* dummy = NULL;
        que.push(root);
        que.push(dummy);
        vector<int> level;
        while(!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();
            if(node == dummy)
            {
                if(!que.empty())
                {
                    que.push(dummy);
                }
                levels.push_back(level);
                level.clear();
                continue;
            }
            level.push_back(node->val);
            if(node->left != NULL)
                que.push(node->left);
            if(node->right != NULL)
                que.push(node->right);
                
        }
        
        return levels;
        
    }
};
