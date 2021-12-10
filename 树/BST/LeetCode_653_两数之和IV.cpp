#include <iostream>
using namespace std;
/*
使用中序遍历得到有序数组之后，再利用双指针对数组进行查找。
应该注意到，
这一题不能用分别在左右子树两部分来处理这种思想，因为两个待求的节点可能分别在左右子树中。
*/

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> res;
        inordered(root, res);

        int left = 0;
        int right = res.size() - 1;

        while (left < right)
        {
            if (res[left] + res[right] == k) return true;
            if (res[left] + res[right] < k) left++;
            else right--;
        }
        return false;
    }

    void inordered(TreeNode* root, vector<int>& res)
    {
        if (root == nullptr) return;

        inordered(root->left, res);
        res.push_back(root->val);
        inordered(root->right, res);

        return;
    }
};