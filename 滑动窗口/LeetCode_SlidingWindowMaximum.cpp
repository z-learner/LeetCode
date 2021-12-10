#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<pair<int,int>> maxValues;
        vector<int> res;
        //build Windows
        for(int i = 0; i < k; i++)
        {
            while (!maxValues.empty() && maxValues.back().first <= nums[i])
            {
                maxValues.pop_back();
            }
            maxValues.push_back({nums[i], i});
        }

        //Get The First Value
        res.push_back(maxValues.front().first);

        //Slide Windows
        for (int i = k; i < nums.size(); i++)
        {
            //Firstly check the first value in maxValues
            if (maxValues.front().second <= i - k)
            {
                maxValues.pop_front();
            }

            //increase maxValues
            while (!maxValues.empty() && maxValues.back().first <= nums[i])
            {
                maxValues.pop_back();
            }
            maxValues.push_back({nums[i], i});

            res.push_back(maxValues.front().first);
        }

        return res;


    }
};