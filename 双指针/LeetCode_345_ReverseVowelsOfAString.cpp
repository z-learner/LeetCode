#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {

        unordered_set<char> temp{'a','e','i','o','u','A','E','I','O','U'};

        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {

            while (left < right && temp.find(s[left]) == temp.end())
            {
                left++;
            }

            while (left < right && temp.find(s[right]) == temp.end())
            {
                right--;
            }
            
            swap(s[left++], s[right--]);
        }
        return s;

    }
};