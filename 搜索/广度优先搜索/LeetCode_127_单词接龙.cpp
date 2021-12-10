#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> map;
        queue<string> que;
        que.push(beginWord);
        vector<bool> memo(wordList.size(), false);
        //map.insert(beginWord);
        int level = 0;
        while (!que.empty())
        {
            int size = que.size();
            level++;
            for (int i = 0; i < size; i++)
            {
                string temp = que.front();
                que.pop();
                //cout << temp << endl;
                if (temp == endWord) return level;
                for (int j = 0; j < wordList.size(); j++)
                {
                    if (memo[j] == true) continue;
                    //if (map.find(str) != map.end()) continue;
                    //cout << wordList[j] << " : " << temp << " , " << judgeWord(wordList[j], temp) << endl;
                    if (judgeWord(wordList[j], temp)) 
                    {
                        que.push(wordList[j]);
                        memo[j] = true;
                        //map.insert(str);
                        
                    }
                    
                }
            }
        }

        return 0;

    }



    bool judgeWord(string s, string t)
    {
        if (s.size() != t.size()) return false;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i]) cnt++;
            if (cnt > 1) return false;
        }

        return cnt == 1;
    }
};






class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.size() == 0 || (wordSet.find(endWord) == wordSet.end())) return 0;
        wordSet.erase(beginWord);

        queue<string> que;
        que.push(beginWord);
        
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        int wordLen = beginWord.size();

        int step = 0;

        while (!que.empty())
        {
            int size = que.size();
            step++;

            for (int t = 0; t < size; t++)
            {
                string curWord = que.front();
                if (curWord == endWord) return step;
                que.pop();
                for (int i = 0; i < wordLen; i++)
                {
                    char curChar = curWord[i];
                    for (char j = 'a'; j <= 'z'; j++)
                    {
                        if (curChar == j) continue;
                        //curWord[i] = j;
                        string nextWord = curWord;
                        nextWord[i] = j;
                        //cout << nextWord << endl;
                        if ((wordSet.find(nextWord) != wordSet.end()) && (visited.find(nextWord) == visited.end()))
                        {
                            //cout << nextWord << " , " << "匹配成功" << endl;
                            que.push(nextWord);
                            visited.insert(nextWord);
                        }
                    } 
                }
            }
        }

        return 0;


    }
};