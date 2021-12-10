#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {

        int size = s.size();
        vector<int> dp(size);
        if (s[0] != '0')
            dp[0] = 1;

        for (int i = 1; i < size; i++)
        {
            if (s[i] != '0')
                dp[i] += dp[i - 1];
            if (s.substr(i - 1, 2) <= "26" && s[i - 1] != '0')
            {
                if (i == 1)
                    dp[i] += 1;
                else  
                    dp[i] += dp[i - 2];
            }
            
        }

        return dp[size - 1];


    }
};