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
private:
    int curCnt = 1;
    int maxCnt = 1;
    TreeNode* pre = nullptr;
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        return res;
    }

private:
    void inOrder(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr) return;
        inOrder(node->left, res);
        if (pre != nullptr)
        {
            curCnt = (pre->val == node->val) ? curCnt + 1 : 1;
        }

        if (curCnt > maxCnt)
        {
            maxCnt = curCnt;
            res.clear();
            res.push_back(node->val);
        }
        else if (curCnt == maxCnt)
        {
            res.push_back(node->val);
        }

        pre = node;
        inOrder(node->right, res);
        return;
    }
};