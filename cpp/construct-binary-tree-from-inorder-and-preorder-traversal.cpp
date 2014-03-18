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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(inorder.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int>::iterator it = find (inorder.begin(), inorder.end(), preorder[0]);
        preorder.erase(preorder.begin());
        if(inorder.begin() != it )
        {
            vector<int> l(inorder.begin(), it );
            root->left = buildTree(preorder, l);
        }
        if(it != inorder.end())
        {
            vector<int> r(it + 1, inorder.end());
            root->right = buildTree(preorder, r);
        }
        return root;
    }
};
