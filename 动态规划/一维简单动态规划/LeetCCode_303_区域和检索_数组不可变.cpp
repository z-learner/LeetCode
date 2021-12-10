#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        dp = nums;
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] += dp[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) return dp[j];
        return dp[j] - dp[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */