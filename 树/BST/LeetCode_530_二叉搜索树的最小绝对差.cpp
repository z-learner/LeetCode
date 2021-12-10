#include <iostream>
#include <vector>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int Min = INT16_MAX;
    int getMinimumDifference(TreeNode* root) {
        vector<int> res;
        inordered(root,res);
        return Min;
    }

    void inordered(TreeNode* root, vector<int>& res)
    {
        if (root == nullptr) return;
        inordered(root->left,res);
        if (!res.empty()) Min = min(Min, abs(root->val - res.back()));
        res.push_back(root->val);
        inordered(root->right, res);
        return;
    }
};