/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int> ans;

    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        // Agar left aur right subtree ki height same hai
        if (left == right && left != -1) {
            int height = left + 1;

            // Perfect subtree ka size
            int size = (1 << height) - 1;

            ans.push_back(size);

            return height;
        }

        return -1;
    }

public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        dfs(root);

        sort(ans.begin(), ans.end(), greater<int>());

        if (ans.size() < k) {
            return -1;
        }

        return ans[k - 1];
    }
};