#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/spiral-matrix/solution/luo-xuan-ju-zhen-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int botton = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        vector<int> res;
        while (top < botton && left < right)
        {
            //left -> right
            for (int i = left; i < right; i++)
                res.push_back(matrix[top][i]);
            
            //top -> botton
            for (int i = top; i < botton; i++)
                res.push_back(matrix[i][right]);
            
            //right -> left
            for (int i = right; i > left; i--)
                res.push_back(matrix[botton][i]);

            //botton -> top
            for (int i = botton; i > top; i--)
                res.push_back(matrix[i][left]);

            top++;
            left++;
            right--;
            botton--;

        }


        //single row / col
        cout << "top = " << top << ", botton = " << botton << ", left = " << left << ", right = "<< right << endl;
        if (top == botton && left == right)
            res.push_back(matrix[top][left]);

        if (top < botton && left == right)
        {
            cout << "single col" << endl;
            for (int i = top; i <= botton; i++)
                res.push_back(matrix[i][left]);
        }

        if (left < right && top == botton)
        {
            cout << "single row" << endl;
            for (int i = left; i <= right; i++)
                res.push_back(matrix[top][i]);
        }


        return res;
    }
};