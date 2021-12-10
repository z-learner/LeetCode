#include <bits/stdc++.h>

using namespace std;


int res = 0;
void MergeSortHelp(vector<int>&data, vector<int>&copy, int start, int end) {
	if (start == end) 
		return;
	int mid = (start + end) / 2;
	MergeSortHelp(copy, data, start, mid);
	MergeSortHelp(copy, data, mid + 1, end);
	int i = mid, j = end;
	int index = end;
	while (i >= start && j >= mid + 1) {
		if (data[i] > data[j])
        {
            copy[index--] = data[i--];
        } 
		else
        {
            copy[index--] = data[j--];
            res += (j - mid);
        }
    }
	for (; i >= start;)
    {
        copy[index--] = data[i--];
    }
	for (; j >= mid + 1; j--)
		copy[index--] = data[j--];
}
vector<int> MergeSort(vector<int>&v) {
	bool Invalid_Input = false;
	vector<int>copy;
	int len = v.size();
	if (len <= 0) {
		Invalid_Input = false;
		return copy;
	}
	for (int i = 0; i < len; i++)
		copy.push_back(v[i]);
	MergeSortHelp(v, copy, 0, len - 1);
	return copy;
}



int n;
int k;
int main(int argc, char const *argv[])
{
    cin >> n >> k;
    vector<int> nums;
    for (int i = 0; i < n; i++)
        nums.push_back(i + 1);

    for (int i = 0; i < k; i++)
    {
        int left, right;
        cin >> left >> right;
        reverse(nums.begin() + left - 1, nums.begin() + right);
    }

    MergeSort(nums);

    cout << res << endl;
    return 0;
}
