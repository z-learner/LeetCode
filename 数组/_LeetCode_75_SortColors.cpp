#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0;
        int w = 0;
        int b = 0;
        for (auto num : nums)
        {
            if (num == 0) r++;
            if (num == 1) w++;
            if (num == 2) b++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (r > 0)
            {
                nums[i] = 0;
                r--;
            }
            else if (w > 0)
            {
                nums[i] = 1;
                w--;
            }
            else
            {
                nums[i] = 2;
            }
            
        }
    }
};



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                ++p1;
            } else if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/sort-colors/solution/yan-se-fen-lei-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。