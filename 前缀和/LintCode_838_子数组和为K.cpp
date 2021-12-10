#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param k: an integer
     * @return: return an integer, denote the number of continuous subarrays whose sum equals to k
     */
    int subarraySumEqualsK(vector<int> &nums, int k) {
        // write your code here
        map<int, int> prifixSum;
        prifixSum.insert({0, 1});
        int temp = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            temp += nums[i];
            prifixSum[temp] += 1;
            res += (prifixSum[temp - k]);
        }

        return res;
    }
};