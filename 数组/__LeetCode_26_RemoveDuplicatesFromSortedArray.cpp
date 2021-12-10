#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if (nums.size() == 0)
//         {
//             return 0;
//         }
//         int left = 0;
//         int right = 1;

//         while (left < nums.size() && right < nums.size())
//         {
//             while (left > 0 && right < nums.size() && nums[left] <= nums[left-1])
//             {
//                 swap(nums[left], nums[right]);
//                 right++;
//             }
//             if (right < nums.size())
//             {
//                 left++;
//             }
//         }
        
//         return left;

//     }
// };


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int left = 0,right=1;
        while(right<nums.size()){
            if (nums[right] != nums[left]) {
                left++;
                nums[left] = nums[right];
            }
            right++;
        }
        return left + 1;
    }
};

// 作者：zhou-zi-hong
// 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/kuai-man-zhi-zhen-c-by-zhou-zi-hong-wgbr/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。