#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        if (nums.size() == 0) return 0;

        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] == val)
            {
                swap(nums[left], nums[right]);
                right--;
            }
            else
            {
                left++;
            }
            
        }

        return nums[left] == val ? left : left + 1;

    }
};


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] != val)
            {
                nums[left] = nums[right];
                left++;
            }
        }

        return left;
    }
};

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0; 
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {  
            if (val != nums[fastIndex]) { 
                nums[slowIndex++] = nums[fastIndex]; 
            }
        }
        return slowIndex;
    }
};

// 作者：carlsun-2
// 链接：https://leetcode-cn.com/problems/remove-element/solution/27-yi-chu-yuan-su-bao-li-jie-fa-shuang-zhi-zhen-ji/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。