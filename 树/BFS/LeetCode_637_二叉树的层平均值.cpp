#include <iostream>
#include <vector>
#include <queue>

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            vector<int> temp;
            for (int i = 0; i < size; i++)
            {
                TreeNode* proot = que.front(); 
                temp.push_back(proot->val);
                que.pop();
                if (proot->left != nullptr) que.push(proot->left);
                if (proot->right != nullptr) que.push(proot->right);
            }
            res.push_back(temp);
        }

        return res;
    }
};




class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> temp;
        vector<double> avg;
        if (root == nullptr) return avg;

        temp.push(root);
        while(!temp.empty())
        {
            double sum = 0;
            int cnt = temp.size();

            for (int i = 0; i < cnt; i++)
            {
                TreeNode* t = temp.front();
                sum += t->val;
                temp.pop();

                if (t->left != nullptr) temp.push(t->left);
                if (t->right != nullptr) temp.push(t->right);
            }

            avg.push_back(sum / cnt);

        }
        return avg;
    }
};