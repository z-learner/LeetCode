#include <iostream>


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


//插入排序
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        if (head == nullptr) return nullptr;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* lastSorted = head;
        ListNode* curr = head->next;
        while (curr != nullptr)
        {
            if (lastSorted->val <= curr->val)
                lastSorted = lastSorted->next; //此时lastsorted == curr
            else  
            {
                ListNode* prev = dummyHead;
                while (prev->next->val <= curr->val)
                    prev = prev->next;
                lastSorted->next = curr->next; //为最后的curr做准备
                curr->next = prev->next;
                prev->next = curr;
            }

            curr = lastSorted->next;
        }
        return dummyHead->next;
    }
};

//归并排序 自顶向下归并排序
/*
找到链表的中点，以中点为分界，将链表拆分成两个子链表。
寻找链表的中点可以使用快慢指针的做法，快指针每次移动 22 步，慢指针每次移动 11 步，
当快指针到达链表末尾时，慢指针指向的链表节点即为链表的中点。对两个子链表分别排序。
将两个排序后的子链表合并，得到完整的排序后的链表。可以使用「21. 合并两个有序链表」的做法，将两个有序的子链表进行合并。
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode* tail)
    {
        if (head == nullptr) return head;

        //断开连接 以便于后续的merge
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
                fast = fast->next;
        }

        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr)
        {
            if (temp1->val < temp2->val)
            {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else   
            {
                temp->next = temp2;
                temp2 = temp2->next;
            }

            temp = temp->next;
        }

        if (temp1 == nullptr)
            temp->next = temp2;
        else  
            temp->next = temp1;

        return dummyHead->next;
        
    }
};



//自底向上归并排序
/*
用 \textit{subLength}subLength 表示每次需要排序的子链表的长度，初始时 \textit{subLength}=1subLength=1。
每次将链表拆分成若干个长度为 \textit{subLength}subLength 的子链表（最后一个子链表的长度可以小于 \textit{subLength}subLength），按照每两个子链表一组进行合并，合并后即可得到若干个长度为 \textit{subLength} \times 2subLength×2 的有序子链表（最后一个子链表的长度可以小于 \textit{subLength} \times 2subLength×2）。
合并两个子链表仍然使用「21. 合并两个有序链表」的做法。
将 \textit{subLength}subLength 的值加倍，重复第 2 步，对更长的有序子链表进行合并操作，直到有序子链表的长度大于或等于 \textit{length}length，整个链表排序完毕。
*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/sort-list/solution/pai-xu-lian-biao-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。