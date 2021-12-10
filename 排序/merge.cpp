#include <iostream>
#include <vector>

using namespace std;
 
// void merge(vector<int> &arr,int L,int mid,int R)
// {
// 	int *help = new int[R-L+1];
// 	int p1=L,p2=mid+1,i=0;
// 	while(p1<=mid && p2<=R)
// 	{
// 		help[i++] = arr[p1]>arr[p2] ? arr[p2++] : arr[p1++];
// 	}
// 	while(p1<=mid)
// 		help[i++] = arr[p1++];
// 	while(p2<=R)
// 		help[i++] = arr[p2++];
 
    
// 	for (int i=0;i<R-L+1;i++)
// 	{
// 		arr[L+i] = help[i];
// 	}
//     delete[] help;
// }
// void sortprocess(vector<int> &arr,int L,int R)
// {
// 	if (L < R)
// 	{
// 		int mid = L + ((R-L)>>2);  //  (L+R)/2
// 		sortprocess(arr,L,mid);
// 		sortprocess(arr,mid+1,R);
// 		merge(arr,L,mid,R);
// 	}
// }
 
// void MergeSort(vector<int> &arr,int L,int R)
// {
// 	if (arr.size()<2)
// 		return;
// 	sortprocess(arr,L,R);
// }
 


void MergeSort(vector<int>& arr, int left, int mid, int right)
{
	vector<int> temp(right - left + 1);
	int l = left, r = mid + 1, i = 0;
	while (l <= mid && r <= right)
	{
		temp[i++] = arr[l] <= arr[r] ? arr[l++] : arr[r++]; 
	}
	while (l <= mid) temp[i++] = arr[l++];
	while (r <= right) temp[i++] = arr[r++];

	for (int i = 0; i < right - left + 1; i++)
	{
		arr[i + left] = temp[i];
	}
}


void Merge(vector<int>& arr, int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;

	Merge(arr, left, mid);
	Merge(arr, mid + 1, right);

	MergeSort(arr, left, mid, right);

}


// int main()
// {
// 	vector<int> arr;
// 	int n,temp;
// 	cin>>n;  //输入n个数
// 	for (int i=0;i<n;i++)
// 	{
// 		cin>>temp;  //输入数据
// 		arr.push_back(temp);
// 	}
 
// 	Merge(arr,0,arr.size()-1);
 
// 	for(int i=0;i<arr.size();i++)
// 		cout<<arr[i]<<",";
 
// 	system("pause");
// 	return 0;
 
// }
// ————————————————
// 版权声明：本文为CSDN博主「code的魅力」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/wx1458451310/article/details/88032871