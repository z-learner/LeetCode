#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;

        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> noSolve(n, vector<bool>(m, false));

        /* 上边 */
        for (int i = 0; i < m; i++)
        {   
            if (!noSolve[0][i] && (board[0][i] == 'O'))
                dfs(board, noSolve, n, m, 0, i, true);
        }
        //左边
        for (int i = 1; i < n - 1; i++)
        {
            if (!noSolve[i][0] && (board[i][0] == 'O'))
                dfs(board, noSolve, n, m, i, 0, true);
        }

        //右边
        for (int i = 1; i < n - 1; i++)
        {
            if (!noSolve[i][m - 1] && (board[i][m - 1] == 'O'))
                dfs(board, noSolve, n, m, i, m - 1, true);
        }
        /* 下边 */
        for (int i = 0; i < m; i++)
        {
            if (!noSolve[n - 1][i] && (board[n - 1][i] == 'O'))
                dfs(board, noSolve, n, m, n - 1, i, true);
        }

        //中间
        // for (int i = 1; i < n - 1; i++)
        // {
        //     for (int j = 1; j < m -1; j++)
        //     {
        //         if (!noSolve[i][j] && (board[i][j] == 'O'))
        //             dfs(board, noSolve, n, m, i, j, false);
        //     }
        // }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((board[i][j] == 'O') && !noSolve[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }

        return;
        
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& noSolve, int n, int m, int x, int y, bool flag)
    {
        if (flag == true ) //未被包围的点
        {
            noSolve[x][y] = true;
        }
        else
        {
            board[x][y] = 'X';
        }

        vector<int> distance{-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newx = x + distance[i];
            int newy = y + distance[i + 1];
            if (newx >= 0 && newx < n && newy >=0 && newy < m && !noSolve[newx][newy] && (board[newx][newy] == 'O'))
            {
                dfs(board, noSolve, n, m, newx, newy, flag);
            }
        }

        return;
    }
};

















class Solution {
public:
    int n, m;

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) {
            return;
        }
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++) {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/surrounded-regions/solution/bei-wei-rao-de-qu-yu-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。