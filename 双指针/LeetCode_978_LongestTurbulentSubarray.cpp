#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        //first case 
        if (arr.size() == 0) return 0;
        int res = 1;
        int left = 0;
        int right = 1;
        while (right < arr.size())
        {
            if (right % 2 == 0)
            {
                if (arr[right] < arr[right - 1])
                {
                    res = max(res, right - left + 1);
                }
                else  
                {
                    left = right;
                }
                right = right + 1;
            }
            else
            {
                if (arr[right] > arr[right - 1])
                {
                    res = max(res, right - left + 1);
                }
                else  
                {
                    left = right;
                }
                right = right + 1;
            }
            
        }

        left = 0;
        right = 1;

        while (right < arr.size())
        {
            if (right % 2 == 1)
            {
                if (arr[right] < arr[right - 1])
                {
                    res = max(res, right - left + 1);
                }
                else  
                {
                    left = right;
                }
                right = right + 1;
            }
            else
            {
                if (arr[right] > arr[right - 1])
                {
                    res = max(res, right - left + 1);
                }
                else  
                {
                    left = right;
                }
                right = right + 1;
            }
            
        }

        return res;

    }
};