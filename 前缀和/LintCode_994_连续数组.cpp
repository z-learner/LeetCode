#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a binary array
     * @return: the maximum length of a contiguous subarray
     */
    int findMaxLength(vector<int> &nums) {
        // Write your code here
        // 1 +1
        // 0 -1
        unordered_map<int, int> prefixSumIndex; // key -- index
        prefixSumIndex.insert({0, -1});
        int temp = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1) temp += 1;
            else temp -= 1;
            if (prefixSumIndex.find(temp) == prefixSumIndex.end())
                prefixSumIndex.insert({temp, i});
            else  
                res = max(res, i - prefixSumIndex[temp]); 
        }

        return res;
    }
};