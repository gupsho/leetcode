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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int len = num.size();
        if(len == 0)
            return NULL;
        return makeBST(num, 0, len - 1);
    }
    
    TreeNode *makeBST(vector<int> &num, int start, int end)
    {
        if(start > end)
            return NULL;
        if(start == end)
            return new TreeNode(num[start]);
        else
        {
            int mid = (start + end)/2;
            TreeNode* root = new TreeNode(num[mid]);
            root->left = makeBST(num, start, mid - 1);
            root->right = makeBST(num, mid + 1, end);
            return root;
        }
    }
};
