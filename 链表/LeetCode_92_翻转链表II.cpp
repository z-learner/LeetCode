#include <iostream>
#include <vector>
using namespace std;


/*
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。
*/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* preNode = nullptr;
        ListNode* nowNode = head;

        for (int i = 0; i < left - 1; i++)
        {
            preNode = nowNode;
            nowNode = nowNode->next;
        }

        ListNode* nextNode = nowNode->next;
        ListNode* preNode2 = preNode;
        //nowNode 第一个翻转的节点
        for (int i = left; i <= right; i++)
        {
            if (preNode2 != preNode) 
                nowNode->next = preNode2;
            else   
                nowNode->next = nullptr;
            preNode2 = nowNode;
            nowNode = nextNode;
            //最后一个节点 特别处理
            if (nowNode != nullptr) nextNode = nowNode->next;
        }

        if (preNode == nullptr)
        {
            head->next = nowNode;
            head = preNode2;
        }
        else
        {
            preNode->next->next = nowNode;
            preNode->next = preNode2;

        }  

        return head;
            
        

    }
};



