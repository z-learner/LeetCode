#include <iostream>
#include <stack>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //两链表入栈，这里链表入栈或者里面的值入栈都可
        stack<int> s1;
        stack<int> s2;
        while (l1 != NULL)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        //两数相加
        //先建立一个辅助节点，用以建立一个链表
        ListNode* newHead = new ListNode(-1);
        int carry = 0;
        while(!s1.empty() || !s2.empty() || carry == 1)
        {
            int x,y;
            if (s1.empty())
            {
                x = 0;
            }
            else
            {
                x = s1.top();
                s1.pop();
            }

            if (s2.empty())
            {
                y = 0;
            }
            else
            {
                y = s2.top();
                s2.pop();
            }

            int sum = x + y + carry;
            ListNode* temp = new ListNode(sum % 10);
            temp->next = newHead->next;
            newHead->next = temp;
            carry = sum / 10;
        }

        return newHead->next;
    }
};