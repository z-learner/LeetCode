#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> res(n,vector<int>(n,0));
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int p = 1;
        while (left <= right && top <= bottom)
        {
            //左向右
            for (int col = left; col < right; col++)
            {
                res[top][col] = p;
                p++;
            }

            //上向下
            for (int row = top; row < bottom; row++)
            {
                res[row][right] = p;
                p++;
            }

            if (right == left && top == bottom)
            {
                res[left][top] = p;
                p++;
            }
            else
            {
                //右向左
                for (int col = right; col > left; col--)
                {
                    res[bottom][col] = p;
                    p++;
                }

                //下向上
                for (int row = bottom; row > top; row--)
                {
                    res[row][left] = p;
                    p++;
                }
            }
            

            top++;
            bottom--;
            left++;
            right--;

        }

        return res;

    }
};