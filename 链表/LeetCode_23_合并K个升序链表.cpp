#include <iostream>
#include <vector>
#include <queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty()) return nullptr;

        ListNode* minNode = lists[0];
        int minIndex = 0;

        for (int i = 1; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
            {
                if (minNode == nullptr || lists[i]->val < minNode->val)
                {
                    minNode = lists[i];
                    minIndex = i;
                }
            }
        }

        if (minNode == nullptr) return nullptr;
        lists[minIndex] = lists[minIndex]->next;
        minNode->next =  mergeKLists(lists);
        return minNode;

    }
};






struct cmp
{
    /* data */
    bool operator()(ListNode* left, ListNode* right)
    {
        return left->val > right->val;
    }
};

/*
最近学习STL，发现STL默认都是使用()比较的，默认比较使用less（即'<'运算符），如sort(a,a+n)，
默认将数组按照递增的顺序来排序（前面的元素<后面的嘛），
但是优先队列的源码比较奇特，虽然按道理使用less比较应该默认是小根堆（即堆顶元素最小），
但是priority_queue<>默认是大根堆的，这是因为优先队列队首指向最后，
队尾指向最前面的缘故！每次入队元素进去经排序调整后，优先级最大的元素排在最前面，
也就是队尾指向的位置，这时候队首指向优先级最小的元素！所以虽然使用less但其实相当于greater，
我们重载运算符的时候比较函数里面写>就相当于<排序方式，这点需要花点时间想想，
再来说一说优先队列的这个类型，其实有三个参数：priority_queue<class Type,class Container,class Compare>，
即类型，容器和比较器，后两个参数可以缺省，这样默认的容器就是vector，
比较方法是less，也就是默认大根堆，可以自定义写比较方法，但此时若有比较方法参数，则容器参数不可省略！
priority_queue<>的可支持的容器必须是用数组实现的容器，如vector，deque，但不能是list（推荐vector），
比较方法可以写结构体重载()运算符，
也可以用less，greater这些语言实现了的，但是灵活性不够，
建议手写重载结构体，或者——如果不想写比较结构体的话，就将后面的两个参数缺省，直接重载类型的<运算符，如：
————————————————
版权声明：本文为CSDN博主「AAMahone」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/AAMahone/article/details/82787184
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        for (int i = 0; i < lists.size(); i++)
            if (lists[i] != nullptr)
            {
              que.push(lists[i]);
              cout << lists[i]->val << "已入队列" << endl;
            }  

        if (que.empty()) return nullptr;  

        return deep(que);

    }

    ListNode* deep(priority_queue<ListNode*, vector<ListNode*>, cmp>& que)
    {
        if (que.empty()) return nullptr;
        ListNode* temp = que.top();
        cout << "processing " << temp->val << endl;
        que.pop();
        if (temp->next != nullptr) 
        {
            que.push(temp->next);
            cout << temp->next->val << "已入队列" << endl;
        }
        temp->next = deep(que);
        return temp;
    }

};



// 分治思想
class Solution {
public:
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; aPtr = aPtr->next;
            } else {
                tail->next = bPtr; bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* merge(vector <ListNode*> &lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。