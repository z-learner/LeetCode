#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i- 1][j - 1] + 1;
                else   
                    dp[i][j] = max(
                        dp[i - 1][j - 1],
                        max(
                            dp[i - 1][j],
                            dp[i][j - 1]
                        )
                    );
            
            }
        }

        return dp[n][m];
    }
};





class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1));
        int dp[n+1][m+1];
        for(int i = 0 ; i <n+1;i++)
            for(int j = 0 ; j < m+1;j++)
                dp[i][j]=0;
        
        int res = 0;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m;j++){
                
                if(s1[i]==s2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                }
                else{
                     dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
                }
                res = max(res,dp[i+1][j+1]);
                
            }
        }
        

        return res;
    }
};

// 作者：dongSSP
// 链接：https://leetcode-cn.com/problems/longest-common-subsequence/solution/8ms-by-dongssp-6vpr/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。