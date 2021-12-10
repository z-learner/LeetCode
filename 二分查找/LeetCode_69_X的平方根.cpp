#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {

        int left = 0;
        int right = x / 2 + 1; //暂定

        while (left < right)  //要求为左侧数值
        {
            long long mid = left + (right - left) / 2 + 1;
            if (mid * mid > x) //右侧向左侧逼近， 寻左值
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }

        return left;

    }
};

class Solution {
public:
    int mySqrt(int x) {


        int left = 0;
        int right = x / 2 + 1;

        while (left < right)
        {
            long long mid = (right - left) / 2 + left + 1;
            /* C++中int和long long特别容易被忽略的点，在做乘法的时候即使单个变量在int范围内，
            如果乘积超了int，也需要将乘数定义为longlong 否则会出错 */
            if (mid * mid > x)
                right = mid - 1;
            else  
                left = mid;
        }

        return left;

    }
};