#include <iostream>
#include <vector>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  };
 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
        {
            cout << "root == nullptr, so return nullptr" << endl;
            return nullptr;
        }
        if (root == p || root == q)
        {
            cout << "root == p || root == q, so return root" << endl;
            return root;   
        }

        cout << "此时检查 root = " << root->val << endl;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        cout << "检查 root = "  << root->val << " 完毕" << endl;
        if (left == nullptr)
        {
            cout << "left == nullptr, so return right" << endl;
            if (right == nullptr)
                cout << "And right = nullptr" << endl;
            else  
                cout << "And right->val = " << right->val << endl;
            return right;
        }
        if (right == nullptr)
        {
            cout << "right == nullptr, so return left" << endl;
            if (left == nullptr)
                cout << "And left = nullptr" << endl;
            else  
                cout << "And left->val = " << left->val << endl;
            return left;
        }
        if (left && right) // p和q在两侧
        {
            cout << "left && right != nullptr" << endl;
            cout << "And left->val = " << left->val << ", and right->val = " << right->val << endl;
            cout << "return root , and root->val = " << root->val << endl;
            return root;
        }

        return nullptr; // 必须有返回值
    }
};



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr) return right;
        if (right == nullptr) return left;
        else return root;      
    }
};

