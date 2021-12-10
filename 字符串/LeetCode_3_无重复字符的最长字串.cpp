#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> memo;

        //int right = s.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        while (right < s.size())
        {
            while (memo.find(s[right]) != memo.end())
                memo.erase(s[left++]);
            memo.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;


    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> memo(128,0);

        //int right = s.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        while (right < s.size())
        {
            while (memo[s[right]] != 0)
                memo[s[left++]]--;
            memo[s[right]]++;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;


    }
};




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