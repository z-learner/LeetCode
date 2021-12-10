#include <iostream>
#include <vector>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return {};
        vector<string> res;
        string temp = "";
        binaryTreePaths(res, temp, root);

        return res;
    }


    void binaryTreePaths(vector<string>& res, string temp, TreeNode* root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            temp += to_string(root->val);
            res.push_back(temp);
            return;
        }

        temp = temp + to_string(root->val) + "->";
        if (root->left != nullptr)
            binaryTreePaths(res, temp, root->left);
        if (root->right)
            binaryTreePaths(res, temp, root->right);

        return;
    }
};