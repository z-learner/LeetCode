#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * @param arr: The array 
     * @param k: the sum 
     * @return: The length of the array
     */
    int searchSubarray(vector<int> &arr, int k) {
        // Write your code here
        unordered_map<int, int> prifixSumIndex;
        prifixSumIndex.insert({0, -1});
        int prifixSum = 0;
        int res = -1;
        for (int i = 0; i < arr.size(); i++)
        {
            prifixSum += arr[i];
            if (prifixSumIndex.find(prifixSum - k) != prifixSumIndex.end())
                {res = i - prifixSumIndex[prifixSum - k]; return res;}
            if (prifixSumIndex.find(prifixSum) == prifixSumIndex.end())
                prifixSumIndex.insert({prifixSum, i});
            
        }

        return res;
    }
};