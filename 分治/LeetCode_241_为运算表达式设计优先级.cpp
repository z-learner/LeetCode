#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        //首先 先设定 返回值 为 input 的 可计算成功的所有值
        vector<int> res;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*')
            {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (auto l : left)
                {
                    for (auto r : right)
                    {
                        switch(input[i])
                        {
                            case '+':
                                res.push_back(l + r);
                                break;
                            case '-':
                                res.push_back(l - r);
                                break;
                            case '*':
                                res.push_back(l * r);
                                break;
                        }
                    }
                }
            }
        }

        if (res.size() == 0)
        {
            res.push_back(stoi(input));
        }

        return res;
    }
};