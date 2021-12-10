#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        vector<int> dp(A.size(), 0); //dp[i] 为 以  A【i】 结尾的等差数列个数
        int sum = 0;
        for (int i = 2; i < A.size(); i++)
        {
            if ((A[i] - A[i - 1]) == (A[i - 1] - A[i - 2]))
            {
                dp[i] = dp[i - 1] + 1;
                sum += dp[i];
            }
        }

        return sum;
    }
};