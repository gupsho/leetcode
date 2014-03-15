class Solution {
public:
    int numTrees(int n) {
        if (n <=1) {
            return(1);
        }
        else {
            int sum = 0;
            int left, right, root;

            for (root=1; root<=n; root++) {
                left = numTrees(root - 1);
                right = numTrees(n - root);

                sum += left*right;
            }
            return(sum);
        }
    }
};
