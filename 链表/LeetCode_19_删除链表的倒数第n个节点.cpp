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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int left = 0;
        int right = 0;
        ListNode *right_ptr = head;
        ListNode *left_ptr = head;
        ListNode *pre_left_ptr = nullptr;
        while (right_ptr->next != nullptr)
        {
            /* code */
            right++;
            right_ptr = right_ptr->next;
            
            if (left + n - 1 < right)
            {
                /* code */
                left++;
                pre_left_ptr = left_ptr;
                left_ptr = left_ptr->next;
            }

        }
        if (pre_left_ptr == nullptr)
        {
            return head->next;
        }
        
        pre_left_ptr->next = left_ptr->next;

        return head;
        
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //fast先定位到第n+1个节点， 也就是移动n次
        int temp = n;
        ListNode* fast = head;
        while(temp > 0)
        {
            fast = fast->next;
            temp--;
        }

        if (fast == nullptr) //正好有n个
            return head->next;
        //slow开始从头移动
        //同时fast一同移动
        //当fast到null时
        //slow恰好倒数第n个
        ListNode* slow = head;
        while(fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};


class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (k <= 0) return nullptr;

        ListNode* fastNode = head;
        ListNode* slowNode = head;

        for (int i = 0; i < k ; i++)
        {
            if (fastNode == nullptr) return nullptr;
            fastNode = fastNode->next;
        }

        while (fastNode != nullptr)
        {
            slowNode = slowNode->next;
            fastNode = fastNode->next;
        }

        return slowNode;
    }
};