#include <iostream>
#include <vector>

using namespace std;


//暴力法 超出时间限制
class Solution {
public:
    int maxArea(vector<int>& height) {

        int res = 0;
        for (int i = 1; i < height.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                res = max(res, (i - j) * min(height[i], height[j]));
            }
        }

        return res;

    }
};


//双指针 贪心
class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        while (left < right)
        {
            res = max(res , (right - left) * min(height[left], height[right]));
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
            
        }

        return res;

    }
};
