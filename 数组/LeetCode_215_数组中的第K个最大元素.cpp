#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int,vector<int>, greater<int>> res;

        for (int i = 0; i < k; i++)
        {
            res.push(nums[i]);
        }

        for (int i = k; i < nums.size(); i++)
        {
            res.push(nums[i]);
            res.pop();
        }

        return res.top();

    }
};



//Quick Sort
class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r)
    {
        if (l >= r) return;
        int mid = nums[(l + r) / 2], i = l - 1, j = r + 1;

        while (i < j)
        {
            do i ++ ; while (nums[i] < mid);
            do j -- ; while (nums[j] > mid);
            if (i < j) swap(nums[i], nums[j]);
        }

        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        quick_sort(nums, 0, n - 1);

        return nums[n - k];
    }
};

// 作者：wo-yao-chu-qu-luan-shuo
// 链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-yqrt/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。