#include <iostream>
#include <bits/stdc++.h>
//if we follow 0 indexing for all then we have to just make -1 while assigning in ans
int range_limit ;
int size;
using namespace std;
void show(int arr[], int size) {
	for (int i = 0;i<size;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void count_sort(int arr[], int size) {
	int temp[range_limit] = {0};

	for (int i = 0; i <size; ++i)
		temp[arr[i]]++;
	for (int j = 1; j <range_limit; ++j) {
		temp[j] = temp[j - 1] + temp[j];
	}
	int ans[size];
	for (int i = size-1 ;i >=0;i--) {
		ans[temp[arr[i]]-1] = arr[i];//yaha -1 kar do
		temp[arr[i]] = temp[arr[i]] - 1;
	}
	for(int i=0;i<size;i++)
        arr[i]=ans[i];

}
int main()
{
    cout<<"enter size"<<endl;
    cin>>size;
    cout<<"enter the limit of value (0 to that value)"<<endl;
    cin>>range_limit;
    int arr[size];
    cout<<"enter elements\n";
    for (int i=0;i<size ;i++ )
    {
        cin>>arr[i];
    }
   	cout<<"initially"<<endl;
	show(arr,size);
	count_sort(arr, size);
	cout << "after sorting\n";
	show(arr, size);
	return 0;
}
