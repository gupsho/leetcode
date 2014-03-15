/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        
        queue<TreeLinkNode*> q;
        q.push(root);
        TreeLinkNode* dummy = NULL;
        q.push(dummy);
        while(!q.empty())
        {
            TreeLinkNode* node = q.front();
            q.pop();
            if(node == NULL)
                break;
            while(node!= NULL)
            {
                q.push(node->left);
                q.push(node->right);
                node->next = q.front();
                node = q.front();
                q.pop();
            }
            q.push(dummy);
        }
        
    }
};
