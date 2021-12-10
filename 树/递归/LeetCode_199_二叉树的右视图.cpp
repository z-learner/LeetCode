#include <iostream>
#include <vector>
#include <unordered_set>
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        unordered_set<int> memo;
        vector<int> res;
        rightSideView(root, res, 0, memo);
        return res; 
    }

    void rightSideView(TreeNode* root, vector<int>& res, int index, unordered_set<int>& memo)
    {
        if (root == nullptr) return;
        if (memo.find(index) == memo.end())
        {
            res.push_back(root->val);
            memo.insert(index);
        }
        rightSideView(root->right, res, index + 1, memo);
        rightSideView(root->left, res, index + 1, memo);
        return;
    }
};