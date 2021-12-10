#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> operator+(pair<int, int>& temp1, pair<int, int>& temp2)
{
    return make_pair(temp1.first + temp2.first, temp1.second + temp2.second);
} 


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.size() == 0 && grid[0].size() == 0) return -1;

        int n = grid.size();
        //int m = grid[0].size();
        vector<pair<int, int>> distance{ {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        vector<vector<bool>> memo(n, vector<bool>(n, false));

        queue<pair<int, int>> que;
        if (grid[0][0] == 1) return -1;
        que.push(make_pair(0, 0));
        memo[0][0] = true;
        int level = 0;
        while (!que.empty())
        {
            int s = que.size();
            level++;
            for (int i = 0; i < s; i++)
            {
                auto temp = que.front();
                if (temp.first == n -1 && temp.second == n - 1) return level;
                que.pop();
                for (auto dis : distance)
                {
                    pair<int, int> t = dis + temp;
                    //cout << temp.first << "," << temp.second << ";" << t.first << "," << t.second << endl;
                    if (t.first >= 0 && t.first < n && t.second >= 0 && t.second < n && (grid[t.first][t.second] == 0)&& !memo[t.first][t.second])
                    {
                        que.push(t);
                        memo[t.first][t.second] = true;
                    }
                }
            }
        }

        return -1;
        

    }   
};


