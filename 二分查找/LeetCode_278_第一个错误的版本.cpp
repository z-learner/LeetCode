#include <iostream>
#include <vector>

using namespace std;

bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        long long left = 1;
        long long right = n;
        while (left < right)
        {
            long long mid = (left + right) / 2;
            if (!isBadVersion(mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
            
            
        }

        return left;
    }
};