//中序遍历解法
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;

        kthSmallest(root, res);

        return res[k - 1];
    }

    void kthSmallest(TreeNode* root, vector<int>& res)
    {
        if (root == nullptr) return;

        kthSmallest(root->left, res);
        res.push_back(root->val);

        kthSmallest(root->right, res);

    }
};

//递归
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
    int kthSmallest(TreeNode* root, int k) {
        int leftCount = count(root->left);

        if (leftCount == k - 1) return root->val;

        if (leftCount > k - 1) return kthSmallest(root->left, k);

        return kthSmallest(root->right, k - 1 - leftCount);
    }

    int count(TreeNode* root)
    {
        if (root == nullptr) return 0;

        return 1 + count(root->left) + count(root->right);
    }

    
};