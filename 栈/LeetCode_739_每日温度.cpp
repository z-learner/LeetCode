#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<pair<int, int>> temp;
        temp.push({ T[0],0 });
        if (T.size() == 0) return res;
        for (int i = 1; i < T.size(); i++)
        {
            while (!temp.empty() && T[i] > temp.top().first)
            {
                res[temp.top().second] = i - temp.top().second;
                temp.pop();
            }
            temp.push({ T[i],i });
        }
        return res;
    }
};