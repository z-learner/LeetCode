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
    int maxNumber = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxNumber;
    }

    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        maxNumber = max(maxNumber, left + right);

        return max(left, right) + 1;
    }
};

class Solution {
public:
    int maxLine = 0;
    int diameterOfBinaryTree(TreeNode* root) {

        maxDeepth(root);
        return maxLine;

    }

    int maxDeepth(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int left = maxDeepth(root->left);
        int right = maxDeepth(root->right);

        maxLine = max(maxLine, left + right);

        return max(left, right) + 1;  
    }
};
