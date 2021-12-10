//BFS
class Solution {
public:
    int minDepth(TreeNode* root) {

        queue<TreeNode*> BFS;
        if (root == nullptr) return 0;

        BFS.push(root);

        int res = 1;

        while (!BFS.empty())
        {
            int n = BFS.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode* top = BFS.front();
                BFS.pop();

                if(top != nullptr && top->left == nullptr && top->right == nullptr)
                {
                    return res;
                }

                if(top->left != nullptr)
                {
                    BFS.push(top->left);
                }

                if (top->right != nullptr)
                {
                    BFS.push(top->right);
                }
            }

            res++;
        }

        return -1;

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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if (left == 0 || right == 0) return left + right + 1; //两个 只有一个 为 0 不是 叶子节点

        return min(left, right) + 1;
    }
};