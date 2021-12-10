/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        reverse(head);

        return res;
    }

    void reverse(ListNode* head)
    {
        if (head == nullptr) return;
        reverse(head->next);
        res.push_back(head->val);
    }
};