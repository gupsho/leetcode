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
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;
        
        TreeLinkNode* prev = root, *current = NULL;
        while(prev)
        {
            root = prev;
            while(prev)
            {
                if(current)
                    current->next = prev->left;
                if(prev->left)
                    prev->left->next = prev->right;
                current = prev->right;
                
                prev = prev->next;
            }
            current = NULL;
            prev = root->left;
        }
    }
};
