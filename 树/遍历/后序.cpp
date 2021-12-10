//递归
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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorderTraversal(root, res);
        return res;
    }

    void postorderTraversal(TreeNode* root, vector<int>& res)
    {
        if (root == nullptr) return;

        postorderTraversal(root->left, res);
        postorderTraversal(root->right, res);

        res.push_back(root->val);
    }
};


//栈1
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stc;
        if (root == nullptr) return res;
        stc.push(root);
        TreeNode* pre = root;

        /*
        如果栈顶元素的左右孩子均非前置结点，并且该元素有左孩子结点，那么说明该结点的孩子均未访问过，按照后序遍历顺序将其左孩子入栈；
        同理，如果其没有左孩子有孩子，并且其右孩子不是前置结点，则说明其孩子未访问过，按照后序遍历顺序，其右孩子应该在它签名访问，因此将其右孩子入栈；
        如果左右孩子出现了前置结点，那么说明该结点的孩子已访问过，按照后序遍历顺序，应该接下来访问其自身，因此将其出栈并加入结果中，此时将其置为新的前置结点
        */
        while (!stc.empty())
        {
            root = stc.top();
            //stc.pop();
            
            if (root->left != nullptr && root->left != pre && root->right != pre) stc.push(root->left);
            else if (root->right != nullptr && root->right != pre) stc.push(root->right);
            else
            {
                stc.pop();
                res.push_back(root->val);
                pre = root;
            }
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
    vector<int> postorderTraversal(TreeNode* root) {
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
                stc.push(new TreeNodePair(p->node, true));
                if (p->node->right != nullptr) stc.push(new TreeNodePair(p->node->right, false));
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
    vector<int> postorderTraversal(TreeNode* root) {
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
                stackNode.push(NodePair);
                if (NodePair.first->right != nullptr) stackNode.push(make_pair(NodePair.first->right, false));
                
                if (NodePair.first->left != nullptr) stackNode.push(make_pair(NodePair.first->left, false));
            }

        }

        return res;
    }
};