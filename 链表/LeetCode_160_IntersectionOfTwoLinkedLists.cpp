#include <iostream>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if (headB == nullptr || headA == nullptr) return nullptr;

        ListNode* temp = headA;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = headB;  //将A的尾与B的头相连，这样问题可转变成 判断有无环的入口，找环的入口

        ListNode* lowPoint = headA;
        ListNode* fastPoint = headA;

        while (lowPoint != nullptr && fastPoint != nullptr && fastPoint->next != nullptr)
        {
            lowPoint = lowPoint->next;
            fastPoint = fastPoint->next->next;
            if(lowPoint == fastPoint)
            {
                fastPoint = headA;
                while (fastPoint != lowPoint)
                {
                    fastPoint = fastPoint->next;
                    lowPoint = lowPoint->next;
                }

                temp->next = nullptr;

                return lowPoint;
                
            }
        }

        temp->next = nullptr;
        return nullptr;
        


    }
};






class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* l1 = headA;
        ListNode* l2 = headB;

        /*
        设 A 的长度为 a + c，B 的长度为 b + c，其中 c 为尾部公共部分长度，可知 a + c + b = b + c + a。
        当访问 A 链表的指针访问到链表尾部时，令它从链表 B 的头部开始访问链表 B；
        同样地，当访问 B 链表的指针访问到链表尾部时，令它从链表 A 的头部开始访问链表 A。这样就能控制访问 A 和 B 两个链表的指针能同时访问到交点。
        如果不存在交点，那么 a + b = b + a，以下实现代码中 l1 和 l2 会同时为 null，从而退出循环。

        如果存在交点时， l1，l2皆走过 a + b + c 时， l1， l2 会相交
        */

        while (l1 != l2)
        {
            l1 = (l1 == nullptr) ? headB : l1->next;
            l2 = (l2 == nullptr) ? headA : l2->next;


        }
        
        return l1;


    }
};



class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;

        while (l1 != l2)
        {
            l1 = (l1 == nullptr) ? headB : l1->next;
            l2 = (l2 == nullptr) ? headA : l2->next;
        }

        return l2;

    }
};