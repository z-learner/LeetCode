#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int index = -1;
        for (char c : s)
        {
            index = selectFirstChar(c, t, index + 1);
            if (index == -1) return false;
        }
        return true;
    }

    int selectFirstChar(char c, string s, int index)
    {
        if (index >= s.size()) return -1;
        for (; index < s.size(); index++)
        {
            if (s[index] == c) break;
        }

        return index == s.size() ? -1 : index;
    }
};