#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
    int maxSubArrayLen(vector<int> &nums, int k) {
        // Write your code here
        unordered_map<int, int> prifixSumIndex;
        prifixSumIndex.insert({0, -1});
        int prifixSum = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prifixSum += nums[i];
            if (prifixSumIndex.find(prifixSum - k) != prifixSumIndex.end())
                res = max(res, i - prifixSumIndex[prifixSum - k]);
            if (prifixSumIndex.find(prifixSum) == prifixSumIndex.end())
                prifixSumIndex.insert(prifixSum, i);
        }
        return res;
    }
};