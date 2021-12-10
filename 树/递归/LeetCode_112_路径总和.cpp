//搜索
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr)
        {
            return false;
        }

        return deepIn(root,sum,root->val);

    }

    bool deepIn(TreeNode *root,int sum, int cur_sum)
    {
        if(root->left == nullptr && root->right == nullptr && sum == cur_sum)
        {
            return true;
        }
        else if(root->left == nullptr && root->right == nullptr)
        {
            return false;
        }

        if(root->left != nullptr && deepIn(root->left,sum,cur_sum+root->left->val))
        {
            return true;
        }
        if(root->right != nullptr && deepIn(root->right,sum,cur_sum+root->right->val))
        {
            return true;
        }

        return false;
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum) return true;

        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};