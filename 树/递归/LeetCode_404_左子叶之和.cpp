//1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ret = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;

        sumOfLeftLeaves(root, 1);

        return ret;
    }

    void sumOfLeftLeaves(TreeNode* root, int flag)
    {
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr && flag == 0){
            ret += root->val;
            return;
        }

        if (root->left == nullptr && root->right == nullptr && flag == 1)
        {
            return;
        }

        sumOfLeftLeaves(root->left, 0);
        sumOfLeftLeaves(root->right, 1);
        return;
    }

};
//2
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;

        if (isLeaf(root->left)) return root->left->val + sumOfLeftLeaves(root->right);
        
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        
    }

    bool isLeaf(TreeNode* root)
    {
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr) return true;

        return false;
    }

};