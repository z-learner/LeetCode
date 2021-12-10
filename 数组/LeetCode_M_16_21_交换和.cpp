#include <bits/stdc++.h>
using namespace std;



// 超时
class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int sum1 = accumulate(array1.begin(), array1.end(), 0);
        int sum2 = accumulate(array2.begin(), array2.end(), 0);

        for (int i = 0; i < array1.size(); i++)
        {
            int tempSum1 = sum1 - array1[i];
            for (int j = 0; j < array2.size(); j++)
            {
                int tempSum2 = sum2 - array2[j];
                if (tempSum1 + array2[j] == tempSum2 + array1[i])
                    return {array1[i], array2[j]};
            }

        }
        return {};
    }
};


// 二分查找
class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int sum1 = accumulate(array1.begin(), array1.end(), 0);
        int sum2 = accumulate(array2.begin(), array2.end(), 0);

        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());

        int target = sum1 - sum2;
        if (target == 0 || abs(target) % 2 == 1) return {};
        if (target > 0) 
        {
            auto res = findSwapValuesCore(array2, array1, target);
            reverse(res.begin(), res.end());
            return res;
        }
        else return findSwapValuesCore(array1, array2, -target);

    }

    // sum(array1) <= sum(array2)
    vector<int> findSwapValuesCore(vector<int>& array1, vector<int>& array2, int different)
    {

        for (int i = 0; i < array1.size(); i++)
        {
            int target = array1[i] + different / 2;
            int right = array2.size() - 1;
            //在array2中寻找target
            int left = 0;
            while (left < right)
            {
                int mid = (right + left) / 2;
                if (array2[mid] < target)
                    left = mid + 1;
                else  
                    right = mid;
            }
            if (array2[left] == target) return {array1[i], target};
            
        }

        return {};
    }
};
