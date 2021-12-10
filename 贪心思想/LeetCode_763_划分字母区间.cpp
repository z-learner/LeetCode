#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

/*
效率较低
*/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int left = 0;
        int right = 0;
        set<char> temp;
        while (right < S.size())
        {
            if (temp.empty()) temp.insert(S[right]);
            if (!judgeLables(temp, S, right + 1))
            {
                temp.insert(S[right]);
                right++;
            }
            else
            {
                temp.clear();
                res.push_back(right - left + 1);
                left = right + 1;
                right++;
            }
        }
        return res;
    }

    bool judgeLables(set<char> se, string s, int index)
    {
        for (; index < s.size(); index++)
        {
            if (se.find(s[index]) != se.end())
            {
                return false;
            }
        }

        return true;
    }
};



/*
由于同一个字母只能出现在同一个片段，显然同一个字母的第一次出现的下标位置和最后一次出现的下标位置必须出现在同一个片段。因此需要遍历字符串，得到每个字母最后一次出现的下标位置。
在得到每个字母最后一次出现的下标位置之后，可以使用贪心算法和双指针的方法将字符串划分为尽可能多的片段，具体做法如下。
从左到右遍历字符串，遍历的同时维护当前片段的开始下标 \textit{start}start 和结束下标 \textit{end}end，初始时 \textit{start}=\textit{end}=0start=end=0。
对于每个访问到的字母 cc，得到当前字母的最后一次出现的下标位置 \textit{end}_cend ，则当前片段的结束下标一定不会小于 \textit{end}_cend 
因此令 \textit{end}=\max(\textit{end},\textit{end}_c)end=max(end,end 
当访问到下标 \textit{end}end 时，当前片段访问结束，当前片段的下标范围是 [\textit{start},\textit{end}][start,end]，长度为 \textit{end}-\textit{start}+1end−start+1，将当前片段的长度添加到返回值，然后令 \textit{start}=\textit{end}+1start=end+1，继续寻找下一个片段。
重复上述过程，直到遍历完字符串。
上述做法使用贪心的思想寻找每个片段可能的最小结束下标，因此可以保证每个片段的长度一定是符合要求的最短长度，如果取更短的片段，则一定会出现同一个字母出现在多个片段中的情况。由于每次取的片段都是符合要求的最短的片段，因此得到的片段数也是最多的。
由于每个片段访问结束的标志是访问到下标 \textit{end}end，因此对于每个片段，可以保证当前片段中的每个字母都一定在当前片段中，不可能出现在其他片段，可以保证同一个字母只会出现在同一个片段。
链接：https://leetcode-cn.com/problems/partition-labels/solution/hua-fen-zi-mu-qu-jian-by-leetcode-solution/
*/
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        int length = S.size();
        for (int i = 0; i < length; i++) {
            last[S[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last[S[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};

