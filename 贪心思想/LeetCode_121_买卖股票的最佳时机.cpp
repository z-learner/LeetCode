#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int minVal = prices[0]; //记录出现过的最小股票值
        int maxVal = 0;//记录最大收益

        for (int i = 1; i < prices.size(); i++)
        {
            minVal = min(minVal, prices[i]);
            maxVal = max(maxVal, prices[i] - minVal);
        }
        return max(maxVal, 0);
    }
};