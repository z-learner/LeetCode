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


//递归
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorderTraversal(root, res);
        return res;
    }

    void preorderTraversal(TreeNode* root, vector<int>& res)
    {
        if (root == nullptr) return;

        res.push_back(root->val);
        preorderTraversal(root->left, res);
        preorderTraversal(root->right, res);
    }
};

//栈1
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stc;
        if (root == nullptr) return res;
        stc.push(root);
        while (!stc.empty())
        {
            TreeNode* temp = stc.top();
            stc.pop();
            if (temp == nullptr) continue;
            res.push_back(temp->val);
            stc.push(temp->right);
            stc.push(temp->left);
        }

        return res;
    }

    
};

//栈2
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stc;
        //stc.push(root);
        while(root != nullptr || !stc.empty())
        {
            while (root != nullptr)
            {
                res.push_back(root->val);
                stc.push(root);
                root = root->left;
            }

            root = stc.top();
            stc.pop();
            root = root->right;
        }

        return res;
    }
};


//设置结点访问标志
/*
顾名思义，这种方法就是给每一个结点附加一个额外的标志位，如果没访问过，标志位置为false，如果已经访问过了，则置为true，并且将已访问过的结点加入结果中。

注意：不同遍历顺序入栈的顺序不同，并且因为栈是后入先出的，所以入栈顺序应该根输出顺序相反。比如，中序遍历应该按照“右-中-左”的顺序入栈。
*/
/*
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer>();
        if (root == null) return ans;
        Stack<TreeNodePair> stack = new Stack<TreeNodePair>();
        stack.push(new TreeNodePair(root, false));
        while (!stack.isEmpty()) {
            TreeNodePair pair = stack.pop();
            if (!pair.flag) {
                if (pair.node.right != null) stack.push(new TreeNodePair(pair.node.right, false));
                if (pair.node.left != null) stack.push(new TreeNodePair(pair.node.left, false));
                stack.push(new TreeNodePair(pair.node, true));
            }
            else {
                ans.add(pair.node.val);
            }
        }
        return ans;
    }

    private class TreeNodePair {
        TreeNode node;
        boolean flag;
        TreeNodePair(TreeNode node, boolean flag) {
            this.node = node;
            this.flag = flag;
        }
    }
*/

//栈3
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    vector<int> preorderTraversal(TreeNode* root) {
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
                if (p->node->left != nullptr) stc.push(new TreeNodePair(p->node->left, false));
                stc.push(new TreeNodePair(p->node, true));

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> sta;
        if (root == nullptr) return {};
        sta.push(root);
        vector<int> res;
        while (!sta.empty())
        {
            TreeNode* temp = sta.top();
            sta.pop();
            res.push_back(temp->val);
            if (temp->right != nullptr) sta.push(temp->right);
            if (temp->left != nullptr) sta.push(temp->left);
        }

        return res;

    }
};