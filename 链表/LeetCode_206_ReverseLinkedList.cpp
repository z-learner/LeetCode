#include <iostream>
#include <vector>

using namespace std;

  struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };



//递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newHead;


    }
};


//头插法
class Solution {

public:
    ListNode* reverseList(ListNode* head) {

        //先定义一个辅助节点
        ListNode* newHead = new ListNode(-1);

        while (head != nullptr)
        {
            ListNode *next = head->next;
            head->next = newHead->next;
            newHead->next = head;
            head = next;
        }
        
        return newHead->next;


    }
};



//头插法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prePtr = nullptr;
        ListNode* nowPtr = head;
        //ListNode* nextPtr = 
        while (nowPtr != nullptr)
        {
            ListNode* temp = nowPtr->next;
            nowPtr->next = prePtr;
            prePtr = nowPtr;
            nowPtr = temp;
        }

        return prePtr;

    }
};


//递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newHead;


    }
};



