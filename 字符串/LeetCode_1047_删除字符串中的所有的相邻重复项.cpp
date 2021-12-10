#include <iostream>
#include <deque>
#include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {

        deque<char> deq;
        for (auto s : S)
        {
            if (deq.empty()) deq.push_back(s);
            else  
            {
                if (s == deq.back())
                    deq.pop_back();
                else   
                    deq.push_back(s);
            }
        }

        string res;
        while (!deq.empty())
        {
            res.push_back(deq.front());
            deq.pop_front();
        }

        return res;
            

    }
};