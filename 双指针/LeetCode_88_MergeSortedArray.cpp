#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int right1 = m - 1;
        int right2 = n - 1;
        int right = m + n - 1;

        while (right1 >= 1 || right2 >= 0)
        {
            if (right1 < 0)
            {
                nums1[right--] = nums2[right2--];
            }
            else if(right2 < 0)
            {
                nums1[right--] = nums1[right1--];
            }
            else  
            {
                if(nums1[right1] > nums2[right2])
                {
                    nums1[right--] = nums1[right1--];
                }
                else
                {
                    nums1[right--] = nums2[right2--];
                }
                
            }
        }

    }
};