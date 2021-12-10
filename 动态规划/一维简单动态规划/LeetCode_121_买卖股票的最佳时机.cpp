#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = 0;
        stack<int> minStack;
        for (int i = 0; i < prices.size(); i++)
        {
            while (!minStack.empty() && prices[i] < minStack.top())
            {
                minStack.pop();
            }
            if (minStack.empty())
            {
                minStack.push(prices[i]);
                minPrice = prices[i];
            }
            else   
            {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
            
        }

        return maxProfit;
        
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int(*dp)[2] = new int[prices.size()][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][1] = max(dp[i - 1][1], -prices[i]); //是否 买入
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); //是否 卖出
        }
        return max(dp[prices.size() - 1][0],0);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        //record min number
        int minPrice = prices[0];
        //record max profit
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
        
    }
};




