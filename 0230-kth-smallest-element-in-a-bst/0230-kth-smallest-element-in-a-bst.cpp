class Solution {
    vector<int> arr;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        arr.push_back(root->val);

        inorder(root->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);

        return arr[k - 1];
    }
};