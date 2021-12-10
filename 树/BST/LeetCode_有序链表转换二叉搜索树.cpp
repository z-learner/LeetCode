#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);
        ListNode* mid = getMidNode(head);
        ListNode* midNext = mid->next;
        mid->next = nullptr;
        TreeNode* root = new TreeNode(midNext->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(midNext->next);
        return root;
    }
    ListNode* getMidNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            pre = slow; 
            slow = slow->next;
            fast = fast->next->next;
        }
        return pre;
    }
};