#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (exist(board, word, visited, i, j, 0))
                    return true;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int r, int c, int index)
    {
        if (index == word.size() - 1 && word[index] == board[r][c]) return true;
        if (word[index] != board[r][c]) return false;

        visited[r][c] = true;
        bool flag = false;
        vector<int> dir{-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dir[i];
            int nc = c + dir[i + 1];
            
            if (nr >= 0 && nr < board.size() && nc >=0 && nc < board[0].size())
            {
                if (!visited[nr][nc])
                {
                    flag = exist(board, word, visited, nr, nc, index+1);
                    if (flag == true)
                    {
                        break;
                    }
                }
            }
        }

        visited[r][c] = false;

        return flag;
    }
};