#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    map<char, string> map{
        {'2' , "abc"},
        {'3' , "def"},
        {'4' , "ghi"},
        {'5' , "jkl"},
        {'6' , "mno"},
        {'7' , "pqrs"},
        {'8' , "tuv"},
        {'9' , "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        vector<string> res;
        string temp = "";
        letterCombinations(res, temp, digits, 0);
        return res;
    }

    void letterCombinations(vector<string>& res, string temp, string digits, int index)
    {
        if (index == digits.size())
            res.push_back(temp);
        
        string digMap = map[digits[index]];
        for (int i = 0; i < digMap.size(); i++)
        {
            temp.push_back(digMap[i]);
            letterCombinations(res, temp, digits, index + 1);
            temp.pop_back();
        }
    }
};