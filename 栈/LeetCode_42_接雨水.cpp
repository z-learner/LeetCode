#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int, int>> sta;
        int index = 0;
        int res = 0;
        while (index < height.size())
        {
            while ((!sta.empty()) && height[index] > sta.top().first)
            {
                auto temp = sta.top();
                sta.pop();
                if (sta.empty()) break;
                int dis = index - sta.top().second - 1;
                res += dis * (min(height[index], sta.top().first) - temp.first); 
            }
            
            sta.push({height[index], index});
            
            ++index;
        }

        return res;
    }
};