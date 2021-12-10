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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //先找root
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

    }

    TreeNode* buildTree(vector<int>& preorder,int preLeft, int preRight, vector<int>& inorder, int inLeft, int inright)
    {
        if (inLeft > inright) return nullptr;
        int temp = preorder[preLeft];
        int tempIndex = inLeft;
        for (;tempIndex<= inright; tempIndex++)
            if (inorder[tempIndex] == temp) break;
        
        TreeNode* root = new TreeNode(temp);
        root->left = buildTree(preorder, preLeft + 1, preLeft + tempIndex - inLeft, inorder, inLeft, tempIndex - 1);
        root->right = buildTree(preorder, preLeft + tempIndex - inLeft + 1, preRight, inorder, tempIndex + 1, inright);
        return root;
    }
};