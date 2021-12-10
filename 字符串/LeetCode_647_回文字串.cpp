#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            res += countPalindrome(s, i, i);
            res += countPalindrome(s, i, i + 1);
        }

        return res;

    }

    int countPalindrome(string s, int start, int end)
    {
        int cnt = 0;
        while (start >= 0 && end < s.size() && s[start] == s[end])
        {
            start--;
            end++;
            cnt++;
        }
        return cnt;
    }
};