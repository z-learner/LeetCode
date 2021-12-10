#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (abs(x - 0.0) < 1e-9 && n < 0) return 0;
        unsigned int absn = abs(n);

        return n > 0 ? myPow(x, absn) : 1 / myPow(x, absn);
    }

    double myPow(double x, unsigned int absn)
    {
        if (absn == 0)
        {
            return 1;
        }
        if (absn == 1)
        {
            return x;
        }

        double res = myPow(x, absn / 2);

        res *= res;
        if (absn & 0x01)
        {
            res *= x;
        }
        return res;
    }
};