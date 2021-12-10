#include <iostream>
#include <vector>
#include <deque>

using namespace std;


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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        vector<int> tempRes;
        tempRes.push_back(root->val);
        int sum = root->val;
        dfs(res, tempRes, root, targetSum, sum);
        return res;
    }

    void dfs(vector<vector<int>>&res, vector<int>&tempRes, TreeNode* root, int target, int sum)
    {
      //sum += root->val;
      if (root->left == nullptr && root->right == nullptr)
      {
          //sum += root->val;
          if (sum == target)
            res.push_back(tempRes);

          return;
      }

      if (root->left != nullptr)
      {
          tempRes.push_back(root->left->val);
          sum += root->left->val;
          dfs(res, tempRes, root->left, target, sum);
          tempRes.pop_back();
          sum -= root->left->val;

      }

      if (root->right != nullptr)
      {
          tempRes.push_back(root->right->val);
          sum += root->right->val;
          dfs(res, tempRes, root->right, target, sum);
          tempRes.pop_back();
          sum -= root->right->val;

      }
    }
};