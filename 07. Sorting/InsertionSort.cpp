#include<iostream>
void insertionSort(int arr[],int n)
{
	int k;
	for(int i=1;i<n;i++)
	{
		k=arr[i];
		int j=i-1;
		while(arr[j]>k && j>=0)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=k;
	}
}
using namespace std;
int main()
{
	int size;
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++)
		cin>>arr[i];
	insertionSort(arr,size);
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	return 0;
}
