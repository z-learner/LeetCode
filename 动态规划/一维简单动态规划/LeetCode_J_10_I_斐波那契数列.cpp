class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int* dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1]% 1000000007 + dp[i - 2]% 1000000007;
        }
        return dp[n] % 1000000007;
    }
};

template<int N>
class Function
{
public:
    enum
    {
        val = Function<N-1>::val + Function<N-2>::val
    };
};

template<>
class Function<1>
{
public:
    enum
    {
        val = 1
    };
};


template<>
class Function<2>
{
public:
    enum
    {
        val = 2
    };
};


class Solution {
public:
    int numWays(int n) {
        const int Num = 100;
        return Function<Num>::val;
    }
};
