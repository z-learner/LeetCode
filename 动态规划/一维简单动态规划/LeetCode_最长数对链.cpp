#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), _cmp);

        // for (int i = 0; i < pairs.size(); i++)
        // {
        //     cout << pairs[i][0] << " : " << pairs[i][1] << endl;
        // }

        int size = pairs.size();
        vector<int> dp(size, 1);
        int Max = 1;
        for (int i = 1; i < size; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i], dp[j] + 1);

            }
            Max = max(Max, dp[i]);
        }

        return Max;


    }
    static bool _cmp(vector<int>& lhs, vector<int>& rhs)
    {
        return (lhs[0]==rhs[0]&&lhs[1]<rhs[1])||(lhs[0]<rhs[0]);
    }
};



class Solution {
public:
    //题解1：动态规划，时间复杂度O(n^2)，空间复杂度O(n)
    //思路与354. 俄罗斯套娃的题一模一样，就是题目背景换了，哈哈伪装者
    int findLongestChain_1(vector<vector<int>>& pairs) {
        if(pairs.empty())return 0;
        sort(pairs.begin(),pairs.end(),[](const vector<int>& a,const vector<int>& b){
            return (a[0]==b[0]&&a[1]<b[1])||(a[0]<b[0]);
        });
        int n=pairs.size(),res=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};

// 作者：xiaoneng
// 链接：https://leetcode-cn.com/problems/maximum-length-of-pair-chain/solution/cdong-tai-gui-hua-er-fen-fa-tan-xin-fa-yi-ti-duo-j/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。