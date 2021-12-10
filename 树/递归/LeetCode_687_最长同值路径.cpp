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
    int ret = 0;
public:
    int longestUnivaluePath(TreeNode* root) {
        UnivaluePath(root);
        return ret;
    }

    int UnivaluePath(TreeNode* root)
    {
        if (root == nullptr) return 0;

        int left = UnivaluePath(root->left);
        int right = UnivaluePath(root->right);

        left = (root->left != nullptr && root->val == root->left->val) ? left + 1 : 0;
        right = (root->right != nullptr && root->val == root->right->val) ? right + 1 : 0;

        ret = max(ret, left + right);

        return max(left, right);
    }
};