#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charNumber(128,0);

        int left = 0;
        int right = 0;

        //build Windows
        for (right = 0; right < s.size(); right++)
        {
            if (charNumber[s[right]] != 0)
            {
                break;
            }
            charNumber[s[right]]++;
        }

        int res = right - left;

        //slide Windows
        for(;right < s.size(); right++)
        {
            charNumber[s[right]]++;
            while(charNumber[s[right]] > 1)
            {
                charNumber[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }

        return res;
    }
};