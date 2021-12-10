#include <map>
#include <vector>
#include <string>

using namespace std;

//Sunday 解法
class Solution {
public:
    int strStr(string haystack, string needle) {
        //构造偏移
        if (needle.size() == 0) return 0;
        map<char, int> bias;
        for (int i = needle.size() - 1; i >= 0; i--)
        {
            if (bias.find(needle[i]) == bias.end())
                bias[needle[i]] = needle.size() - i; //该字符距 尾部的距离 正好为尾部 设为 1， 以此类推
                                                     //不存在 needle 中的字符 默认偏移 needle.size() + 1
        }

        int index = 0;
        int len = needle.size();
        while (index + len <= haystack.size())
        {
            /* code */
            if (needle == haystack.substr(index, len))
                return index;
            
            if (index + len == haystack.size())
                return -1;
            
            if (bias.find(haystack[index + len]) == bias.end())
                index += (len + 1);
            else 
                index += bias[haystack[index + len]];
        }

        return -1;
        
    }

};



//KMP
class KMP {
    public:
        string pat;
        KMP(string pa) : pat(pa){}
        ~KMP(){}
        int searchPat(string txt);
    private:
        vector<vector<int>> createDfs();
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        KMP kmp(needle);
        return kmp.searchPat(haystack);
    }
};



vector<vector<int>> KMP::createDfs()
{
    int M = pat.size();
    if (M == 0) return {};
    vector<vector<int>> dfs(M, vector<int>(256, 0));
    
    int x = 0;
    dfs[0][pat[0]] = 1;
    for (int j = 1; j < M; j++)
    {
        for (int c = 0; c < 256; c++)
        {
            if (c == pat[j])
                dfs[j][c] = j + 1;
            else  
                dfs[j][c] = dfs[x][c];
        }
        x = dfs[x][pat[j]];
    }

    return dfs;
}


int KMP::searchPat(string txt)
{
    vector<vector<int>> dfs = createDfs();
    if (dfs.size() == 0) return 0;
    int state = 0;
    int M = pat.size();
    for (int i = 0; i < txt.size(); i++)
    {
        state = dfs[state][txt[i]];
        if (state == M)
            return i - M + 1;
    }
    return -1;
}


//不定义类的版本 KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() == 0) return -1;

        int M = needle.size();
        if (M == 0) return {};
        vector<vector<int>> dfs(M, vector<int>(256, 0));
    
        int x = 0;
        dfs[0][needle[0]] = 1;
        for (int j = 1; j < M; j++)
        {
            for (int c = 0; c < 256; c++)
            {
                if (c == needle[j])
                    dfs[j][c] = j + 1;
                else  
                    dfs[j][c] = dfs[x][c];
            }
            x = dfs[x][needle[j]];
        }

        //if (dfs.size() == 0) return 0;
        int state = 0;
        
        for (int i = 0; i < haystack.size(); i++)
        {
            state = dfs[state][haystack[i]];
            if (state == M)
            return i - M + 1;
        }
        return -1;


    }
};


//传统 KMP
class Solution {
public:
    void getNext(int *next,const string &s)
    {
        int j=-1;
        next[0]=j;
        for(int i=1;i<s.size();i++)//注意i从1开始
        {
            while(j>=0&&s[i]!=s[j+1])//处理前后缀不相同的情况
            {
                j=next[j];//向前回溯
            }
            if(s[i]==s[j+1])//找到相同的前后缀
            {
                j++;
            }
            next[i]=j;//将j（前缀的长度）赋给next[i]
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
        {
            return 0;
        }
        int next[needle.size()];
        getNext(next,needle);
        int j=-1;//因为next数组里记录的起始位置为-1
        for(int i=0;i<haystack.size();i++)//注意i从0开始
        {
            while(j>=0&&haystack[i]!=needle[j+1])//不匹配
            {
                j=next[j];//j寻找之前的位置
            }
            if(haystack[i]==needle[j+1])//匹配
            {
                j++;//j和i同时向后移动
            }
            if(j==(needle.size()-1))//文本串s里出现了模式串t
            {
                return (i-needle.size()+1);//返回其位置
            }
        }
        return -1;
    }
};

// 作者：feng-sheng-he-li
// 链接：https://leetcode-cn.com/problems/implement-strstr/solution/di-28ti-ti-jie-zi-fu-chuan-zhi-shi-kmpsu-k4e6/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


/* 初始化 Next数组 */
// char[] string = haystack.toCharArray(), pattern = needle.toCharArray();

// // 创建 next 数组，next[i] 表示当前已匹配串 [0, i] 中最大相同前后缀中的前缀结尾下标。
// int[] next = new int[pattern.length];
// // [0, 0] 长度的字符串，就一个字符，没有任何前后缀概念，因此为 -1。
// next[0] = -1;
// // 当前要初始化的元素，即我们要找 0 到 i 字符串（称作 si）的相同前后缀，因为第 0 个字符已经初始化了，从 1 开始。
// int i = 1;
// // 0 到 i - 1 字符串（称作 si_1)) 的相同前后缀中的前缀（称作 si_1_pre）的结尾下标，如果 si_1 没有相同前后缀，则等于 0。
// int k = -1;
// while (i < next.length) {
//     // si_1 存在相同前后缀
//     if (k != -1) {
//         /*
//           * 由于 si_1 存在相同前后缀 si_1_pre 和 si_1_suf，si_1_pre 固定在字符串首部，当前字符接在 si_1_suf 后面。
//           * 所以如果 si_1_pre 的下一个字符和 si_1_suf（即当前字符）相同的话，si 就具有相同前后缀了。
//           */
//         if (pattern[i] == pattern[k + 1]) {
//             next[i] = k + 1;
//             k++;
//             i++;
//         } else {
//             /*
//               * 回溯：
//               * 如果 si_1_pre 的下一个字符与当前字符不一致，那就 si_1_pre 就不能作为 s1 相同前后缀的一部分。
//               * 不过，如果 si_1_pre（现在称作 s2）也存在相同前后缀 s2_pre 和 s2_suf 的话，
//               * 由于相同， si_1_suf（现在称作 s3）也存在相同前后缀 s3_pre 和 s3_suf。
//               * 所以 s2_pre == s2_suf == s3_pre == s3_suf。
//               * s2_pre 在字符串首部，而 s3_suf 又在当前字符前面。因此 s2_pre 有可能可以作为 si 的相同前后缀的一部分的。
//               * 所以 k 不必直接变 -1，可以回溯到 si_1_pre 的相同前后缀去。
//               */
//             k = next[k];
//         }
//     } else {
//         // si_1 不存在相同前后缀，si 肯定没法利用 si_1 了，不过还是可以利用字符串第一个字符，因为有可能第一个字符和当前字符一致
//         k = next[i] = pattern[0] == pattern[i] ? 0 : -1;
//         i++;
//     }
// }

// 作者：zoharyips
// 链接：https://leetcode-cn.com/problems/implement-strstr/solution/guan-yu-wo-di-yi-ci-kan-kmp-suan-fa-jiu-sqs0d/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。





class Solution {
public: 
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = -1; // // 因为next数组里记录的起始位置为-1
        for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
            while(j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
                j = next[j]; // j 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动
                j++; // i的增加在for循环里
            }
            if (j == (needle.size() - 1) ) { // 文本串s里出现了模式串t
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }


    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++) { // 注意i从1开始
            while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
                j = next[j]; // 向前回溯
            }
            if (s[i] == s[j + 1]) { // 找到相同的前后缀
                j++;
            }
            next[i] = j; // 将j（前缀的长度）赋给next[i]
        }
    }
};

// 作者：carlsun-2
// 链接：https://leetcode-cn.com/problems/implement-strstr/solution/bang-ni-ba-kmpsuan-fa-xue-ge-tong-tou-ming-ming-ba/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
