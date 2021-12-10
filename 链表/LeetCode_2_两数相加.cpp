#include <iostream>
#include <vector>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* preHead = new ListNode(-1);
        ListNode* node = nullptr;
        //preHead->next = node;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int x = l1 == nullptr ? 0 : l1->val;
            int y = l2 == nullptr ? 0 : l2->val;
            cout << "x : " << x << " and y " << y << " and carry : " << carry << endl;
            if (node == nullptr) 
            {
                node = new ListNode((x + y + carry) % 10);
                preHead->next = node;
                
            }
            else   
            {
                node->next = new ListNode((x + y + carry) % 10);
                node = node->next;
            }
            carry = (x + y + carry) / 10;
            l1 = l1 == nullptr ? nullptr : l1->next;
            l2 = l2 == nullptr ? nullptr : l2->next;
        }

        return preHead->next;
    }
};