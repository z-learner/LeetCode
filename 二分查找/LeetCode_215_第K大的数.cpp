#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        //return quick_sort(a, 0, a.size() - 1, K);
        int right = n - 1;
        int left = 0;
        int target = right - K + 1;
        if (target < 0) return -1;
        while (true)
        {
            int index = patition(a, left, right);
            if (index == target)
                return a[index];
            else if(index < target)
                left = index + 1;
            else if (index > target)
                right = index - 1;
        }

        return -1;
    }
    
    int patition(vector<int>& arr, int left, int right)
    {
        int i = left;
        int j = left;
        for ( ;j < right; j++)
        {
            if (arr[j] < arr[right])
            {
                if (i != j)
                {
                    swap(arr[i], arr[j]);
                }
                i++;
            }
        }
        swap(arr[i], arr[right]);
        return i;
    }
    

};