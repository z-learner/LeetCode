#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> map(128, 0);

        if (s.size() != t.size())  return false;

        for (char cs : s)
            map[cs]++;

        for (char ct : t)
        {
            if (map[ct] <= 0)
            {
                return false;
            }
            map[ct]--;
        }

        return true; 
    }
};