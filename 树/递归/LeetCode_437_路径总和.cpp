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
public:

    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        int ret = deepIn(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);

        return ret;
    }

    int deepIn(TreeNode* root, int sum)
    {
        if (root == nullptr) return 0;
        int ret = 0;
        if (root->val == sum) ret++;

        ret += (deepIn(root->left, sum - root->val) + deepIn(root->right, sum - root->val));

        return ret; 
    }
};