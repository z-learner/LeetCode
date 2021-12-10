#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        uint32_t flag = 1;

        while (flag)
        {
            if (n & flag)
                cnt++;
            flag = flag << 1;
        }

        return cnt;
    }
};


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;

        while (n)
        {
            /*
            把一个整数减去1之后，再和原来的整数做位与运算
            得到的结果相当于把整数的二进制表示中最右边的 1 变成 0 
            这种思路， 可解决很多位运算问题
            */
            n = (n - 1) & n; 
            cnt++; 
        }

        return cnt;
    }
};
