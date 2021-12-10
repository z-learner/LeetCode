#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorderTraversal(root, res);

        return res;
    }

    void inorderTraversal(TreeNode* root, vector<int>& res)
    {

        if (root == nullptr) return;
        inorderTraversal(root->left, res);

        res.push_back(root->val);

        inorderTraversal(root->right, res);
    }
};

//栈1


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stc;

        while (root != nullptr || !stc.empty())
        {
            //从当前结点一直向其最左孩子搜索，直到没有左孩子了停止，这个过程中将路程中的所有结点入栈
            while (root != nullptr)
            {
                stc.push(root);
                root = root->left;
            }
            //弹出栈顶元素，将其记录在答案中，并把当前结点置为弹出元素的右孩子并重复上述1过程
            root = stc.top();
            stc.pop();
            res.push_back(root->val);
            root = root->right;

        }
        return res;
    }
};


//栈2

class TreeNodePair
{
public:
    TreeNode* node;
    bool flag;
    TreeNodePair(TreeNode* _node, bool _flag) : node(_node), flag(_flag) {}
    ~TreeNodePair() {}
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        stack<TreeNodePair*> stc;
        stc.push(new TreeNodePair(root, false));

        while (!stc.empty())
        {
            TreeNodePair* p = stc.top();
            stc.pop();

            if (!p->flag)
            {
                if (p->node->right != nullptr) stc.push(new TreeNodePair(p->node->right, false));

                stc.push(new TreeNodePair(p->node, true));
                if (p->node->left != nullptr) stc.push(new TreeNodePair(p->node->left, false));
                

            }
            else
            {
                res.push_back(p->node->val);
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*, bool>> stackNode;
        vector<int> res;
        if (root == nullptr) return {};
        stackNode.push(make_pair(root, false));
        while (!stackNode.empty())
        {
            auto NodePair = stackNode.top();
            stackNode.pop();
            if (NodePair.second == true || (NodePair.first->left == nullptr && NodePair.first->right == nullptr))
            {
                res.push_back(NodePair.first->val);
            }
            else  
            {
                NodePair.second = true;
                if (NodePair.first->right != nullptr) stackNode.push(make_pair(NodePair.first->right, false));
                stackNode.push(NodePair);
                if (NodePair.first->left != nullptr) stackNode.push(make_pair(NodePair.first->left, false));
            }

        }

        return res;
    }
};