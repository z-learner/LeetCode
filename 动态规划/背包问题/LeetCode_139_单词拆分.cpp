#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < wordDict.size(); j++)
            {
                if (i >= wordDict[j].size())
                    dp[i] = (dp[i] || (s.substr(i - wordDict[j].size(), wordDict[j].size()) == wordDict[j] && dp[i - wordDict[j].size()]));
            }
        }

        return dp[s.size()];


    }
};