#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }

        return cnt;
    }

    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        grid[x][y] = '0';
        vector<int> distance{-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newx = x + distance[i];
            int newy = y + distance[i + 1];

            if (newx >= 0 && newx < grid.size() && newy >= 0 && newy < grid[0].size() && (grid[newx][newy] == '1'))
            {
                dfs(grid, newx, newy);
            }

        }
    }
};



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    ++res;
                    DFS(grid, i, j);
                }
            }
        }

        return res;

    }

    void DFS(vector<vector<char>>& grid, int index_x, int index_y)
    {
        grid[index_x][index_y] = '0';

        vector<int> direction{1,0,-1,0,1};

        for (int i = 0; i < 4; i++)
        {
            int new_x = index_x + direction[i];
            int new_y = index_y + direction[i + 1];

            if (new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[index_x].size() && grid[new_x][new_y] == '1')
                DFS(grid, new_x, new_y);
        }

        return;
    }
    
};



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    ++res;
                    BFS(grid, i, j);
                }
            }
        }

        return res;

    }

    void BFS(vector<vector<char>>& grid, int x, int y)
    {
        vector<int> direction{1,0,-1,0,1};
        queue<pair<int, int>> que;
        que.push(make_pair(x ,y));
        grid[x][y] = '0';
        while (!que.empty())
        {
            auto index = que.front();
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int new_x = index.first + direction[i];
                int new_y = index.second + direction[i + 1];
                if (new_x >= 0 && new_x < grid.size() && new_y >= 0 && new_y < grid[0].size() && grid[new_x][new_y] == '1')
                {
                    que.push(make_pair(new_x, new_y));
                    grid[new_x][new_y] = '0';
                }
            }
        }
    }
};