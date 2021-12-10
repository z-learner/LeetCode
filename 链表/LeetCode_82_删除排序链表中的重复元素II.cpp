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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* preNode = nullptr;
        ListNode* nowNode = head;
        //ListNode* nextNode = head->next;

        while (nowNode != nullptr)
        {
            bool isDelete = false;
            ListNode* nextNode = nowNode->next;
            if (nextNode != nullptr && nowNode->val == nextNode->val)
                isDelete = true;

            if (!isDelete)
            {
                preNode = nowNode;
                nowNode = nowNode->next;
                
            }
            else
            {
                int value = nowNode->val;
                //cout << "Value : " << value << endl;
                ListNode* pToBedel = nowNode;
                while (pToBedel != nullptr && pToBedel->val == value)
                {
                    nextNode = pToBedel->next;
                    //cout << "Delete " << pToBedel->val << endl;
                    delete pToBedel;
                    
                    pToBedel = nextNode;
                }
                if (preNode == nullptr)
                {
                    head = nextNode;
                }
                else
                {
                    preNode->next = nextNode;
                }

                nowNode = nextNode;
            }
        }

        return head;
    }
};