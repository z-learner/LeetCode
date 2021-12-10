#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),[](int a, int b){return a < b;});
        sort(s.begin(),s.end(),[](int a, int b){return a < b;});
        int chlid = 0;
        int cookie = 0;
        while (chlid < g.size() && cookie < s.size())
        {
            /* code */
            if(g[chlid] <= s[cookie]) chlid++;
            cookie++;
        }
        return chlid;
    }
};

