#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numSquares(int n) {

        vector<int> nums = getSquares(n);
        vector<bool> memo(n + 1, false);
        queue<int> que;
        que.push(n);
        memo[n] = true;
        int level = 0;
        while (!que.empty())
        {
            int s = que.size();
            
            for (int i = 0; i < s; i++)
            {
                int temp = que.front();
                que.pop();
                if (temp == 0) return level;

                for (int num : nums)
                {
                    int next = temp - num;
                    if (next < 0 || memo[next]) continue;
                    que.push(next);
                    memo[next] = true; 
                }
            }
            level++;
        }

        return -1;

    }



    vector<int> getSquares(int n)
    {
        vector<int> res;
        for (int i = 1; i * i <= n; i++)
        {
            res.push_back(i * i);
        }
        return res;
    }
};



/* 完全背包的做法 */

class Solution {
public:
    int numSquares(int n) {
        vector<int> choices;
        int res = 1;

        // 构造物品，即所有小于给定数字的完全平方数
        while (n / res >= res) {
            choices.push_back(res * res);
            res++;
        }

        const int size = choices.size();
        vector<int> dp(n + 1, 0);

        // init
        for (int i = 0; i <= n; ++i) {
            dp[i] = i;
        }

        // 完全背包模板
        for (int i = 1; i < size; ++i) {
            for (int j = choices[i]; j <= n; ++j) {
                dp[j] = min(dp[j], dp[j - choices[i]] + 1);
            }
        }

        return dp[n];
    }
};