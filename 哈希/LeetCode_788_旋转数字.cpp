#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        
        set<int> mapOne = {2,5,6,9};

        set<int> mapTwo = {0,1,8};
        int res = 0;

        for (int i = 1; i <= N; i++)
        {
            if (judgeNumber(i, mapOne, mapTwo))
                res++;
        }

        return res;

    }

    bool judgeNumber(int num, set<int>& mapOne, set<int>& mapTwo)
    {
        bool flag = false;
        while (num > 0)
        {
            if (mapOne.find(num % 10) != mapOne.end())
            {
                flag = true;
                num = num / 10;
            }
            else if (mapTwo.find(num % 10) != mapTwo.end())    
            {
                num = num / 10;
            }
            else  
            {
                return false;
            }
        }

        return flag;
    }
};


class Solution {
public:
    int rotatedDigits(int N) {

        set<int> mapOne = {2,5,6,9};

        set<int> mapTwo = {0,1,8};

        vector<int> dp(N + 10, -1);
        //1 ： 好数
        //0 : 普数（旋转之后仍为自己）
        //-1： 旋转之后不为有效的数字
        dp[0] = 0;
        dp[1] = 0;
        dp[8] = 0;

        dp[2] = 1;
        dp[5] = 1;
        dp[6] = 1;
        dp[9] = 1;

        int res = 0;

        if (N < 10)
        {
            for (int i = 1; i <= N; i++)
            {
                if (dp[i] == 1) res++;
            }
        }
        else
        {
            res = 4;
            for (int i = 10; i <= N; i++)
            {
                if (mapOne.find(i % 10) == mapOne.end() && mapTwo.find(i % 10) == mapTwo.end())
                {
                    dp[i] = -1;
                }
                else if (mapOne.find(i % 10) != mapOne.end())
                {
                    if (dp[i / 10] != -1)
                    {
                        dp[i] = 1;
                        res++;
                    }
                    else   
                    {
                        dp[i] = -1;
                    }
                }
                else
                {
                    if (dp[i / 10] == 1)
                    {
                        dp[i] = 1;
                        res++;
                    }
                    else if (dp[i / 10] == 0)
                    {
                        dp[i] = 0;
                    }
                    else  
                    {
                        dp[i] = -1;
                    }
                }
            }
        }

        return res;


    }


};