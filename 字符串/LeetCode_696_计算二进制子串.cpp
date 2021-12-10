#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {

        vector<int> counts;
        int ptr = 0;
        int n = s.size();

        while (ptr < n)
        {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c)
            {
                ptr = ptr + 1;
                ++count;
            }

            counts.push_back(count);

        }

        int res = 0;
        for (int i = 1; i < counts.size(); i++)
        {
            res += min(counts[i], counts[i - 1]);
        }

        return res;

    }
};




class Solution {
public:
    int countBinarySubstrings(string s) {
        int ptr = 0, n = s.size(), last = 0, ans = 0;
        while (ptr < n) {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c) {
                ++ptr;
                ++count;
            }
            ans += min(count, last);
            last = count;
        }
        return ans;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/count-binary-substrings/solution/ji-shu-er-jin-zhi-zi-chuan-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。