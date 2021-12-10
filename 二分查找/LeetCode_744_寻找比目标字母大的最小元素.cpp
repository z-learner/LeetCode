#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0;
        int right = letters.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) /2;
            if(letters[mid] <= target) //左侧向右侧逼近， 寻右值
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        if (left == letters.size() - 1)
        {
            return letters[left] <= target ? letters[0] : letters[left];
        }
        return letters[left];
    }
};