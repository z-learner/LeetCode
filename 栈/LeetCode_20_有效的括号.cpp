#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                res.push(c);
            else
            {
                if (res.size() == 0) return false;
                else if (c == ')' && res.top() == '(') res.pop();
                else if (c == ']' && res.top() == '[') res.pop();
                else if (c == '}' && res.top() == '{') res.pop();
                else return false;
            }
        }
        return res.size() == 0 ? true : false;
    }
};



class Solution {
public:
    bool isValid(string s) {
        stack<char> memo;
        unordered_map<char, char> map{
            {')' , '('}, 
            {'}', '{'},
            {']', '['}
            };
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[') memo.push(c);
            else  
            {
                if (memo.empty()) return false;
                else if(memo.top() != map[c]) return false;
                memo.pop();
            }
        }

        return memo.empty();
    }
};