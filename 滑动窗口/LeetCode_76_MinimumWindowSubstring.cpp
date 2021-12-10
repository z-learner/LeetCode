#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        vector<int> map_t(128,0);
        vector<int> map_s(128,0);
        int cont = 0;

        //先遍历t
        for (int i = 0; i < t.size(); i++)
        {
            map_t[t[i]]++;
            cont++;
        }
        int left = 0;
        int right = 0;

        string res = "";
        int max_length = s.size() + 1;

        //slide Window
        for (;right < s.size(); right++)
        {
            map_s[s[right]]++;
            if (map_s[s[right]] <= map_t[s[right]])
            {
                cont--;
            }

            while (cont == 0)
            {
                if (max_length > right - left + 1)
                {
                    max_length = right - left + 1;
                    res = s.substr(left, right - left + 1);
                }
                map_s[s[left]]--;
                if (map_s[s[left]] < map_t[s[left]])
                {
                    cont++;
                }
                left++;
                
            }
        }

        return res;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chars(128,0);
        vector<bool> flags(128,false);
        for (int i = 0; i < t.size(); i++)
        {
            /* code */
            flags[t[i]] = true;
            chars[t[i]]++;
        }

        int min_index = 0;
        int min_size = s.size() + 1;
        int count = 0;
        int l = 0;
        for (int r = 0; r < s.size(); r++)
        {
            /* code */
            if (flags[s[r]])
            {
                /* code */
                if (--chars[s[r]] >= 0)
                {
                    /* code */
                    count++;
                }
                
            }

            while (count == t.size())
            {
                /* code */
                if (r-l+1 < min_size)
                {
                    /* code */
                    min_index = l;
                    min_size = r-l+1;
                }
                if (flags[s[l]] && ++chars[s[l]] > 0)
                {
                    /* code */
                    --count;
                }
                
                l++;
            }
            
            
        }
        
        return min_size > s.size()? "":s.substr(min_index,min_size);
    }
};