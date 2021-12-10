#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (m <= 0 || n <= 0 || k < 0)
            return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return movingCount(k, 0, 0, m, n, visited);
    }

    int movingCount(int k, int i, int j, int m, int n, vector<vector<bool>>& visited)
    {
        if (i < 0 || i >= m || j < 0 || j >=n)
        {
            return 0;
        }
        int count = 0;
        if (check(k, i, j) && !visited[i][j])
        {
            visited[i][j] = true;
            count = 1 + movingCount(k, i + 1, j, m, n, visited) + movingCount(k, i - 1, j, m, n, visited) + movingCount(k, i, j - 1, m, n, visited) + movingCount(k, i, j + 1, m, n, visited);
        }
        return count;
    }

    bool check(int k, int r, int c)
    {
        int sum = 0;
        while (r > 0)
        {
            sum += (r % 10);
            r = r / 10;
        }
        while (c > 0)
        {
            sum += (c % 10);
            c = c / 10;
        }

        return sum <= k;
    }
};