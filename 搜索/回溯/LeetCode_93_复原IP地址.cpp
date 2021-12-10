#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() > 12 || s.size() < 4) return {};
        vector<string> res;
        string temp = "";
        restoreIpAddresses(res, temp, s, 0, 0);
        return res;
    }

    void restoreIpAddresses(vector<string>& res, string temp, string s, int index, int state)
    {
        if (state == 4 && index == s.size())
        {
            temp.pop_back();
            res.push_back(temp);
        }
        else if (index >= s.size())
        {
            return;
        }

        if (s[index] == '0')
        {
            temp.push_back(s[index]);
            temp.push_back('.');
            restoreIpAddresses(res, temp, s, index + 1, state + 1);
            temp.pop_back();
            temp.pop_back();
            
        }
        else
        {
            for (int i = 0; i < 3 && index + i < s.size(); i++)
            {
                if (i == 2)
                    if (s.substr(index, i + 1) > "255")
                        break;
                
                temp += s.substr(index, i + 1);
                temp.push_back('.');
                restoreIpAddresses(res, temp, s, index + i + 1, state + 1);
                temp.pop_back();
                temp = temp.substr(0, temp.size() - (i + 1));
            }
        }
    }
};