#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {

        string LongStr = "";
        for (int i = 0; i < d.size(); i++)
        {
            if (LongStr.size() < d[i].size() || (LongStr.size() == d[i].size() && LongStr > d[i]))
            {
                if(isSubstr(s,d[i]))
                {
                    LongStr = d[i];
                }
            }
        }

        return LongStr;
        


    }

    bool isSubstr(string s, string t)
    {
        if(s.size() < t.size()) return false;
        int left_s = 0;
        int left_t = 0;
        while (left_s < s.size())
        {
            if (s[left_s] != t[left_t])
            {
                left_s++;
            }
            else  
            {
                left_s++;
                left_t++;
            }
        }

        return left_t == t.size() ? true:false;
    }

    // bool compareStrng(string s, string t)
    // {
    //     for (int i = 0, int j = 0; i < min(s.size(),t.size()), j < min(s.size(),t.size()); i++,j++)
    //     {
    //         if(s[i] < t[j])

    //     }
    // }
};