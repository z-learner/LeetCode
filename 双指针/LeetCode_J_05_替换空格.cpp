#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int add = 0;
        for (auto ch : s)
        {
            if (ch == ' ')
                add += 2;
        }

        int p1 = s.size() - 1;
        for (int i = 0; i < add; i++)
        {
            s.push_back(' ');
        }
        int p2 = s.size() - 1;

        while (p1 < p2)
        {
            if (s[p1] != ' ')
            {
                s[p2--] = s[p1--];
            }
            else
            {
                s[p2--] = '0';
                s[p2--] = '2';
                s[p2--] = '%';
                p1--;
            }
            
        }

        return s;

        
    }
};