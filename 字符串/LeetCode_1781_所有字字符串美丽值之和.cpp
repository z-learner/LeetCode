#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int beautySum(string s) 
    {
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> charMemo(26, 0);
            charMemo[s[i] - 'a']++;
            for (int j = i + 1; j < s.size(); j++)
            {
                charMemo[s[j] - 'a']++;
                auto temp = getFre(charMemo);
                int charMin = temp.first;
                int charMax = temp.second;
                res += (charMax - charMin);
            }
        }

        return res;


    }


    pair<int, int> getFre(const vector<int> charMemo)
    {
        int charMin = INT16_MAX;
        int charMax = INT16_MIN;
        for (auto fre : charMemo)
        {
            if (fre != 0)
            {
                charMin = min(charMin, fre);
                charMax = max(charMax, fre);
            }
        }
        if (charMax == INT16_MIN || charMin == INT16_MAX) return make_pair(0, 0); 
        return make_pair(charMin, charMax);
    }

};

// 构造前缀和
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        vector<vector<int> > memo(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                memo[i][s[i] - 'a']++;
            }
            else  
            {
                memo[i] = memo[i - 1];
                memo[i][s[i] - 'a']++;
            }
        }

        // 
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                res += getBeauty(memo, i, j);
            }
        }

        return res;
    }

    int getBeauty(vector<vector<int> >& memo, int left, int right)
    {
        int charMin = INT16_MAX;
        int charMax = INT16_MIN;
        if (left == 0)
        {
            for (int i = 0; i < 26; i++)
            {
                if (memo[right][i] != 0)
                {
                    charMin = min(charMin, memo[right][i]);
                    charMax = max(charMax, memo[right][i]);
                }
            }
            return charMax - charMin;
        }
        else  
        {
            left = left - 1;
            for (int i = 0; i < 26; i++)
            {
                if (memo[right][i] - memo[left][i] != 0)
                {
                    charMin = min(charMin, memo[right][i] - memo[left][i]);
                    charMax = max(charMax, memo[right][i] - memo[left][i]);
            
                }
            }
            return charMax - charMin;
        }
    }

};


