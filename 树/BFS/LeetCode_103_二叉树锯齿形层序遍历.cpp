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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        deque<TreeNode*> memo;
        memo.push_back(root);
        bool flag = true; //true : left-> right, false : right -> left
        while (!memo.empty())
        {
            int size = memo.size();
            vector<int> temp;
            for (int i = 0; i < size; i++)
            {
                TreeNode* proot;
                if (flag)
                {
                    proot = memo.front();
                    cout << "get " << proot->val << endl;
                    memo.pop_front();
                    temp.push_back(proot->val);
                    if (proot->left != nullptr) 
                    {
                        memo.push_back(proot->left);
                        cout << "push back " << proot->left->val << endl;
                    }
                    if (proot->right != nullptr) 
                    {
                        memo.push_back(proot->right);
                        cout << "push back " << proot->right->val << endl;
                    }
                }
                else  
                {
                    proot = memo.back();
                    cout << "get " << proot->val <<endl;
                    memo.pop_back();
                    temp.push_back(proot->val);
                    if (proot->right != nullptr) 
                    {
                        memo.push_front(proot->right);
                        cout << "push front " << proot->right->val <<endl;
                    }
                    if (proot->left != nullptr) 
                    {
                        memo.push_front(proot->left);
                        cout << "push front " << proot->left->val << endl;
                    }
                }
            }
            res.push_back(temp);
            flag = !flag;
        }

        return res;
    }
};