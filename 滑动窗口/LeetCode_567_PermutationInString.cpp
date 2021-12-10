#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int k = s1.size();
        //Fristly
        vector<int> temp(128,0);
        vector<int> count(128,0);
        int cont = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            temp[s1[i]]++;
            cont++;
        }

        //build window
        for (int i = 0; i < k; i++)
        {
            count[s2[i]]++;
            if(count[s2[i]] <= temp[s2[i]])
            {
                cont--;
            }
        }

        if(cont == 0) return true;

        //slide window
        for (int i = k; i < s2.size(); i++)
        {
            count[s2[i - k]]--;
            if(count[s2[i - k]] < temp[s2[i - k]])
            {
                cont++;
            }
            count[s2[i]]++;
            if(count[s2[i]] <= temp[s2[i]])
            {
                cont--;
            }

            if (cont == 0) return true;
        }

        return false;

    }
};