#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; i++)
        {
            //遍历拆分
            int curMax = 0;
            for (int j = 1; j < i; j++)
            {
                curMax = max(
                    curMax,
                    max(j * (i - j), j * dp[i - j]) // i 插入出一个 j 之后 是否继续拆分 
                );
            }
            dp[i] = curMax;
        }

        return dp[n];
    }
};  