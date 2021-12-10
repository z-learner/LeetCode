#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = new ListNode(-1);
        ListNode* now = head;
        ListNode* pre = newHead;
        while(now != nullptr && now->next != nullptr)
        {
            ListNode* temp = now->next;
            now->next = now->next->next;
            temp->next = now;
            pre->next = temp;
            pre = now;

            now = now->next;
        }

        return newHead->next == nullptr ? head : newHead->next;
    }
};