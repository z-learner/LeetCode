#include <iostream>
#include <vector>

using namespace std;

int patition(vector<int>& nums, int left, int right)
{
    int i, j;
    i = j = left;
    for (;j < right;j++)
        if (nums[j] < nums[right])
        {
            if (i != j)  swap(nums[i], nums[j]);
            i++;
        }
    
    swap(nums[i], nums[right]);
    return i; //返回排好序的索引
}

void quick_sort(vector<int>& nums, int left, int right)
{
    if (left >= right) return;
    int pat = patition(nums, left, right);
    quick_sort(nums, left, pat - 1);
    quick_sort(nums, pat + 1, right);
}

void quick_sort(vector<int>& nums)
{
    quick_sort(nums, 0, nums.size() - 1);
}


int main(int argc, char const *argv[])
{
    vector<int> nums{1,2,3,4,3,4,2,5,6,3,7,4,6,7,4,7,4,8,4,3,3,2,6,3,7,74,74,4326,63457,57345,537,3573,37,3};
    quick_sort(nums);
    auto Add = [](int x, int y){
        return x + y;
    };
    for (auto num : nums)
        cout << num << ",";
    cout << endl;    

    return 0;
}





class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    vector<int> MySort(vector<int>& arr) {
        // write code here
        quick_sort(arr, 0, arr.size() - 1);
        return arr;
    }
    
    int patition(vector<int>& arr, int left, int right)
    {
        int i = left;
        for (int j = left; j < right; j++)
        {
            if (arr[j] < arr[right])
            {
                if (i != j)  swap(arr[i], arr[j]);              
                i++;
            }
        }
        swap(arr[i], arr[right]);
        return i;
    }
    
    void quick_sort(vector<int>& arr, int left, int right)
    {
        if (left >= right) return;
        int mid = patition(arr, left, right);
        
        quick_sort(arr, left, mid - 1);
        quick_sort(arr, mid + 1, right);
    }
    
};