#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    
    bool exist(vector<vector<char>> &board, string &word) {
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if(deepIn(board,word,i,j,0,visited))
                    return true;
            }
        }

        return false;
        
    }

    bool deepIn(vector<vector<char>> &board, string &word, int index_x, int index_y, int index,vector<vector<int>> &visited)
    {
        vector<int> direction{-1,0,1,0,-1};

        if(visited[index_x][index_y] == 1)
        {
            return false;
        }

        if(board[index_x][index_y] == word[index] && index == word.size() - 1)
        {
            return true;
        }
        bool temp = false;
        

        visited[index_x][index_y] = 1;

        if(board[index_x][index_y] == word[index])
        {
            for (int i = 0; i < 4; i++)
            {
                int x = index_x + direction[i];
                int y = index_y + direction[i+1];
                if(x >=0 && x < board.size() && y >= 0 && y < board[0].size())
                {
                    
                    temp = deepIn(board,word,x,y,index+1,visited);
                    
                    if(temp)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            temp = false;
        }

        visited[index_x][index_y] = 0;
        return temp;
        
    }
};