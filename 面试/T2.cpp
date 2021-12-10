#include <bits/stdc++.h>

using namespace std;


map<int, vector<pair<int,int> > > road;  // first dest  second cost
map<int, int> Ai;
int res = INT32_MIN;
int T;
int n;

void deepIn(int src, int T, int restemp, vector<bool>& memo, map<int, vector<pair<int,int> > >& road, map<int, int>& Ai)
{
    if (T == 0 && src == 1)
        res = max(res, restemp);
    if (T == 0) return;

    for (int i = 0; i < road[src].size(); i++)
    {
        if (memo[road[src][i].first] == true) continue;
        memo[road[src][i].first] = true;
        deepIn(road[src][i].first, T - 1, restemp + road[src][i].second, memo, road, Ai);
        memo[road[src][i].first] = false;
    }
    return;
}


int main(int argc, char const *argv[])
{
    cin >> n >> T;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        Ai.insert({i + 1, temp});
    }
    for (int i = 0; i < n - 1; i++)
    {
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        road[temp1].push_back(make_pair(temp2, temp3));
    }

    vector<bool> memo(n + 1, false);
    deepIn(1, T, 0, memo, road, Ai);

    cout << res << endl;



    return 0;
}
