#include <iostream>
#include <string>

using namespace std;


/*递归解法*/
class Solution {
public:
    bool isMatch(string s, string p) {

        //如果字符串长度为0 需要检测下正则串
        if (s.size() == 0)
        {
            // 如果正则串长度为奇数， 必定不满足， 同时需要正则串的每个 奇数位皆为 ‘*’
            if (p.size() % 2 == 1) return false;
            int index = 1;
            while (index < p.size())
            {
                /* code */
                if (p[index] != '*') return false;
                index += 2;
            }
            //满足上述条件 返回 true
            return true;
        }
        //如果 正则串为空， 那么 字符串 一定为空
        if (p.size() == 0)
        {
            if (s.size() != 0) return false;
            return true;
        }

        // 若两者 都不为空 ， 分两种情况， 有 ‘*’ 和 无 ‘*’
        char sc = s[0];
        char pc = p[0];
        char next = NULL;
        if (p.size() > 1) next = p[1];

        if (next != '*')
        {
            if (sc == pc || pc == '.')
                return isMatch(s.substr(1), p.substr(1));
            else
                return false;
        }

        else
        {
            if (sc == pc || pc == '.')
                return isMatch(s.substr(1), p)
                    //|| isMatch(s.substr(1), p.substr(2))
                    || isMatch(s, p.substr(2));
            else
            {
                return isMatch(s, p.substr(2));
            }
        }
    }

    
};