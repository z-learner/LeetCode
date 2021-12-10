#include <iostream>

using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        maxDepth(root, flag);
        return flag;
    }

    int maxDepth(TreeNode* root, bool& flag)
    {
        if (root == nullptr) return 0;
        int l = maxDepth(root->left, flag);
        int r = maxDepth(root->right, flag);
        if (abs(l - r) > 1) flag = false;

        return max(l, r) + 1;
    }
};

class Solution {
public:
    bool flag = true;
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return flag;
    }
    
    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        if (abs(left - right) > 1) 
            flag = false;
        
        return max(left, right) + 1;
    }
};
