#include <iostream>
#include <vector>
#include <string>

using namespace std;

// dp[i][j]  ---  i -- j 之间的字符串是否为回文字符串
 class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i; j < n; j++)
        //     {
        //         if (j == i) dp[i][j] = true;

        //         if (s[i] == s[j] && dp[i+1][j-1])
        //     }
        // }
        int maxLen = 0;
        int beginInex = 0;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i <= j; i++)
            {
                if (i == j) dp[i][j] = true;
                else if (s[i] != s[j]) dp[i][j] = false;
                else
                {
                    if (i + 1 >= j - 1)
                        dp[i][j] = true;
                    else  
                        dp[i][j] = dp[i+1][j-1];
                }

                if (dp[i][j] && (j - i + 1 > maxLen))
                {
                    beginInex = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(beginInex, maxLen);
    }
};





class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty() || s.size() == 1) return s;
        int length = 1;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(),false));
        for (int i = 0; i < s.size(); i++)
            dp[i][i] = true;
        int maxLen = 1;
        int begin = 0;
        for (int i = s.size() - 2; i >=0; i--)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] != s[j])
                    dp[i][j] = false;
                else
                {
                    if (j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }

                // 只要 dp[i][j] == true 成立，就表示子串 s[i..j] 是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
             }
        }
        return s.substr(begin, maxLen);
    }
};