#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {

        long left = 0;
        long right = floor(sqrt(c));

        while (left <= right)
        {
            long temp = left*left + right*right; 
            if (c > temp)
            {
                left++;
            }
            else if (c < temp)
            {
                right--;
            }
            else
            {
                return true;
            }
            
        }

        return false;

    }
};