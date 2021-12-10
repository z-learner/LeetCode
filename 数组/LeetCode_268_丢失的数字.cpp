#include <iostream>
#include <vector>

using namespace std;

// O(n) O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> memo(n + 1, false);

        for (auto nu : nums)
        {
            memo[nu] = true;
        }

        for (int i = 0; i <= n; i++)
        {
            if (!memo[i]) return i;
        }

        return -1;

    }
};


// O(nlog(n)) O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        if (nums[0] != 0) return 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] != 1)
                return nums[i - 1] + 1;
        }

        return nums.size();

    }
};

// 亦或操作
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }
};


// 数学方法  求和 然后相相减
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            sum += (i - nums[i]);
        }

        return sum;
    }
};

