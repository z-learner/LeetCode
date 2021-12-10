#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int right = 0;
        int res = 0;
        int maxCountRepeat = 0; //The number of repeate char in Slide Window
        vector<int> windows(26,0);

        while (right < s.size())
        {
            windows[s[right] - 'A']++;
            maxCountRepeat = max(maxCountRepeat, windows[s[right] - 'A']);

            if (maxCountRepeat + k >= right - left + 1) //the window can expand
            {
                res = max(res, right - left + 1);
                right++;
            }
            else //the window can't expand , bunt you can pan the window  
            {
                windows[s[left] - 'A']--;
                left++;
                right++;
            }

        }

        return res;

    }
};


class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int left = 0;
        int right = 0;
        int maxCount = 0;
        int res = 0;
        while (right < s.size())
        {
            count[s[right]-'A']++;
            maxCount = max(maxCount,count[s[right]-'A']);

            if (right - left + 1 <= maxCount + k)
            {
                //扩充窗口
                res = max(right - left + 1,res);
                right++;
            }
            else
            {
                //平移窗口
                count[s[left]-'A']--;
                left++;
                right++;
            }
            
            
        }

        return res;
        
    }
};