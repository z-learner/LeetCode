#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        } //找到第一个 正序对
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            } // 找到第i个数 右面的 比第i的最靠左的
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());  // 然后 把 i + 1 到 末尾的数翻转
    }
};

//https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode-solution/