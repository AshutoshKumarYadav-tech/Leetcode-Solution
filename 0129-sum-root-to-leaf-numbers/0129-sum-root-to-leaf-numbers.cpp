class Solution {
public:

    int solve(TreeNode* root, int currnum) {

        if (root == nullptr)
            return 0;

        currnum = currnum * 10 + root->val;

        // Leaf node
        if (root->left == nullptr && root->right == nullptr)
            return currnum;

        return solve(root->left, currnum) +
               solve(root->right, currnum);
    }

    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};