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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        int res = 0;
        if (root == nullptr) return -1;

        que.push(root);
        while(!que.empty())
        {
            int cnt = que.size();

            res = que.front()->val;

            for (int i = 0; i < cnt; i++)
            {
                TreeNode* tm = que.front();
                que.pop();

                if (tm->left != nullptr) que.push(tm->left);
                if (tm->right != nullptr) que.push(tm->right);
                

            }
        }

        return res;
    }
};