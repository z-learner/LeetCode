#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char,int> temp;

        for (int i = 0; i < s.size(); i++)
        {
            /* code */  
            temp[s[i]]++;
        }

        int sum = 0;
        int odd_max = 0;

        for (auto tmp: temp)
        {
            if(tmp.second % 2 == 0)
            {
                sum += tmp.second;
            }
            else
            {
                odd_max = max(odd_max, tmp.second);
                sum += (tmp.second - 1);
            }
            
        }

        return odd_max > 0 ? sum + 1 : sum;
        

    }
};




class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> map(128, 0);
        for (char c : s)
        {
            map[c]++;
        }

        int res = 0;

        for (auto temp : map)
        {
            res += (temp / 2) * 2;
        }

        return res < s.size() ? res + 1 : res;

    }
};