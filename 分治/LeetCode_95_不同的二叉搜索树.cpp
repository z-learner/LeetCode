#include <iostream>
#include <vector>
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
    vector<TreeNode*> generateTrees(int n) {
        if (n ==0) return {};
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int left, int right)
    {
        //这里的结果是 从left -> right 所生成的不同的 树的根节点
        vector<TreeNode*> res;
        if (left > right)
            return {nullptr};
        for (int i = left; i <= right; i++)
        {
            for (auto& l : generateTrees(left, i - 1))
            {
                for (auto& r : generateTrees(i + 1, right))
                {
                    TreeNode* root = new TreeNode(i , l , r);
                    res.push_back(root);
                }
            }
        }
        return res;
        
    }
};




class Solution {
    vector<vector<vector<TreeNode*>> > memo;    //1 加上记忆化后果然好多了，可见真的重复计算了好多
public:
    vector<TreeNode*> generateTrees(int st,int ed) {
        // 边界条件
        vector<TreeNode*> ans;
        if(st > ed) return {NULL};
        if(!memo[st][ed].empty()) return memo[st][ed];  //4 记忆化代码
        // 递归代码
        for(int i=st;i<=ed;i++){
            for(auto& l : generateTrees(st,i-1)){
                for(auto& r : generateTrees(i+1,ed)){
                    TreeNode* root = new TreeNode(i,l,r);
                    ans.push_back(root);
                }
            }            
        }
        return memo[st][ed]=ans;        //3 记忆化添加得代码
    }
    vector<TreeNode*> generateTrees(int n) {
        memo.resize(n+1,vector<vector<TreeNode*>>(n+1));    //2 记忆化添加得代码
        if(n == 0) return {};
        return generateTrees(1,n);
    }

/*
作者：nuo-_yan
链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii/solution/he-qian-mian-man-er-cha-shu-de-ti-ting-xiang-de-by/
来源：力扣（LeetCode）
*/
