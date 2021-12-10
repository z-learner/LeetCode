#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        //从后面开始排

        int indexM = m - 1;
        int indexN = n - 1;
        int index = m + n - 1;
        while (indexM >= 0 && indexN >= 0)
        {
            if (nums1[indexM] >= nums2[indexN])
            {
                //swap(nums1[indexM], nums1[])
                nums1[index--] = nums1[indexM--];
            }
            else  
            {
                nums1[index--] = nums2[indexN--];
            }
        }

        while (indexM >= 0)
        {
            nums1[index--] = nums1[indexM--];
        }

        while (indexN >= 0)
        {
            nums1[index--] = nums2[indexN--];
        }
        
    }
};
