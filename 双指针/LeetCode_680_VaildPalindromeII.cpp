#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            if(s[left] != s[right])
            {
                return deleteOnePalindrome(s,left,right-1) || deleteOnePalindrome(s,left+1,right);
            }
            left++;
            right--;
        }

        return true;
    }

    bool deleteOnePalindrome(string s, int left, int right)
    {
        while (left < right)
        {
            if(s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }
};