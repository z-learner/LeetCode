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
//递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode* s, TreeNode* t)
    {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;

        if (s->val != t->val) return false;

        return isSymmetric(s->left, t->right) && isSymmetric(s->right, t->left);
    }
};

//BFS
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        deque<pair<TreeNode*,int>> temp;
        if (root->left != NULL)
            temp.push_back({ root->left,1});
        if (root->right != NULL)
            temp.push_back({ root->right,2 });
        while (!temp.empty())
        {
            if (temp.size() % 2)
                return false;
            auto node1 = temp.front();
            auto node2 = temp.back();
            if (node1.first->val != node2.first->val || node1.second == node2.second)
                return false;
            temp.pop_back();
            temp.pop_front();
            if (node1.first->right != NULL)
                temp.push_front({ node1.first->right , 2});
            if (node1.first->left != NULL)
                temp.push_front({ node1.first->left , 1 });
            if (node2.first->left != NULL)
                temp.push_back({ node2.first->left , 1 });
            if (node2.first->right != NULL)
                temp.push_back({ node2.first->right , 2 });
        }
        return true;
    }
};