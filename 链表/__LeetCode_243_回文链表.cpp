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
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        int n = 1;
        ListNode *r_head = head;
        ListNode *l_head = head;
        while (head->next != nullptr)
        {
            head = head->next;
            n++;
        }
        if(n == 1) return true;

        for (int i = 0; i < n/2; i++)
        {
            r_head = r_head->next;
        }
        ListNode *newHead = reverseList(r_head);
        for (int i = 0; i < n/2; i++)
        {
            if (newHead->val != l_head->val)
            {
                /* code */
                return false;
            }
            newHead = newHead->next;
            l_head = l_head->next;
            
        }
        
        return true;
        
    }

    ListNode* reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};





/*
快指针走到末尾，慢指针刚好到中间。其中慢指针将前半部分反转。然后比较。 思路果然666
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = head;
        ListNode* prepre = nullptr;
        //快指针走到末尾，慢指针刚好到中间。其中慢指针将前半部分反转。
        while (fast != nullptr && fast->next != nullptr)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
            pre->next = prepre;
            prepre = pre;
        }

        if (fast != nullptr) //链表节点个数为奇数的情况下
            slow = slow->next;

        while (pre != nullptr && slow != nullptr)
        {
            if (pre->val != slow->val)
            {
                return false;
            }
            slow = slow->next;
            pre = pre->next;
        }

        return true;
      
        
    }

    
};


/*
hash1前三次取值(0),括号表示次方
    hash1 = 0 + p1.val = seed(0) * p1.val;
    hash1 = seed(0) * p1.val *seed + p2.val = seed(1) * p1.val + seed(0) * p2.val;
    hash1 = (seed(1) * p1.val + seed(0) * p2.val) * seed + p3.val = seed(2) * p1.val + seed(1) * p2.val + seed(0) * p3.val;
hash2前三次取值
    hash2 = p1.val= seed(0) * p1.val; h=seed(1);
    hash2 = seed(0) * p1.val + seed*p2.val = seed(0)*p.val + seed(1)* p2.val; h = seed(2);
    hash2 = seed(0)*p1.val + seed(1)* p2.val + seed(2)* p3.val = seed(0)*p1.val + seed(1)* p2.val + seed(2)*p3.val;
对比第三次结果, 
只要p1.val = p3.val 
则必然满足 seed(2) * p1.val + seed(1) * p2.val + seed(0) * p3.val = seed(0)*p1.val + seed(1)* p2.val + seed(2)*p3.val 
思路新奇, 难理解,hash1 hash2的递推公式是要倒着写出来,有点难 
再想想跟hash没啥关系, hash冲突存在另外一个链表计算出来hash值相同, 但这已经不是某一个链表是否对称的问题, 
这就是一个数学问题,就是证明一下在x足够大的时候,
公式a1*x(0) + a2*x(1) + a3x(3) + a4x(4)... 如果要等于 a4*x(0) + a3*x(1) + a2*x(3) + a1x(4)... 
是不是有且仅有的解是 a4 == a1 && a3 == a2 && a2 == a3 && a1 == 4
JAVA 代码
class Solution {
    public boolean isPalindrome(ListNode head) {
        long hash1 = 0, hash2 = 0, h = 1;
        long seed = (long) (1e9 + 7);
        ListNode p = head;
        while (p != null) {
            hash1 = hash1 * seed + p.val;
            hash2 = hash2 + h * p.val;
            h *= seed;
            p = p.next;
        }
        return hash1 == hash2;
    }
}

作者：tcan1993
链接：https://leetcode-cn.com/problems/palindrome-linked-list/solution/ha-xi-bian-li-yi-ci-jiu-xing-by-tcan1993/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        unsigned long hash1 = 0;
        unsigned long hash2 = 0;
        ListNode* p = head;
        unsigned long seed = 1e3 + 7;
        unsigned long h = 1; 
        while (p != nullptr)
        {
            hash1 = hash1*seed + p->val;
            hash2 = hash2 + p->val * h;

            h *= seed;
            p = p->next;
        }

        return hash1 == hash2;
        
    }
};

