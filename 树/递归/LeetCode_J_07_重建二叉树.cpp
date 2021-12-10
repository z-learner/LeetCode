/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        TreeNode* root = buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pleft, int pright, int ileft,  int iright)
    {
        if (pleft > pright) return nullptr;
        if (ileft > iright) return nullptr;

        TreeNode* root = new TreeNode(preorder[pleft]); //前序遍历的第一个 根节点

        int leftCount = 0; //在中序遍历中， 根节点左右分别为左右子树， temp 记录 左子树的数目
        int rootIndex = 0;

        for (int i = ileft; i <= iright; i++)
        {
            if (preorder[pleft] == inorder[i])
            {
                rootIndex = i;
                break;
            }
            leftCount++;
        }

        root->left = buildTree(preorder, inorder, pleft + 1, pleft + leftCount, ileft, rootIndex - 1);
        root->right = buildTree(preorder, inorder, pleft + leftCount + 1, pright, rootIndex + 1,  iright);

        return root;
    }
};