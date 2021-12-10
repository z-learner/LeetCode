/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归
class Solution {
public:
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        int val1 = root->val;
        if (root->left != nullptr) val1 += rob(root->left->left) + rob(root->left->right);
        if (root->right != nullptr) val1 += rob(root->right->left) + rob(root->right->right);

        int val2 = rob(root->left) + rob(root->right);

        return max(val1, val2);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归 + 备忘录
class Solution {
public:
    unordered_map<TreeNode*, int> temp;
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;

        if (temp.find(root) != temp.end()) return temp[root];
        int val1 = root->val;
        if (root->left != nullptr) val1 += rob(root->left->left) + rob(root->left->right);
        if (root->right != nullptr) val1 += rob(root->right->left) + rob(root->right->right);

        int val2 = rob(root->left) + rob(root->right);
        temp[root] = max(val1, val2);
        return max(val1, val2);
    }
};


//
class Solution {
public:
    // first : not to choose current node
    // second : choose current node
    // 类似后续遍历 === 自底向上
    pair<int, int> helper(TreeNode* root) {
        if (root== NULL) return make_pair(0, 0);
        pair<int, int> left= helper(root->left);
        pair<int, int> right= helper(root->right);
        return make_pair(max(left.first, left.second)+ max(right.first, right.second), left.first+ right.first+ root->val);
    }
    int rob(TreeNode* root) {
        pair<int, int> res= helper(root);
        return max(res.first, res.second);
    }
};


