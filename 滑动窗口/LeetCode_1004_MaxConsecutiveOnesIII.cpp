#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {

        
        int maxCount = 0; //记录当前窗口下有多少个 1 
        int left = 0;
        int right = 0;
        int res = 0;
        while (right < A.size())
        {
            // 当前值为1 计数加一
            if (A[right] == 1)
            {
                maxCount++;
            }
            //判断当前窗口是否满足要求
            if (maxCount + K >= right - left + 1)
            {
                res = max(res, right - left + 1);
                //window expand
                right++;
            }
            else   
            {
                //平移窗口
                if(A[left] == 1)
                {
                    maxCount--;
                }
                left++;
                right++;
            }
        }

        return res;

    }
};