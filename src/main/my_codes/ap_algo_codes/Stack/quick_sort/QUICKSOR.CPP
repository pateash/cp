#include<stdio.h>
#include<conio.h>
#include<iostream.h>
int partition(int[],int,int);
void quick(int arr[],int low,int up)
{
int p;
if(low>=up)
return ;
p=partition(arr,low,up);
quick(arr,low,p-1);
quick(arr,p+1,up);
}
int partition(int arr[],int low,int up)
{
	int t,povot;
	int i=low+1;
	int j=up;
	int pivot=arr[low];
while(i<=j)
{
	while(arr[j]>pivot)
	j--;
	while(arr[i]<pivot&&i<up)
	i++;
if(i<j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	i++;
	j--;
}
else i++;
}
arr[low]=arr[j];
arr[j]=pivot;
return j;
}

void main()
{
clrscr();
int arr[10];
cout<<"enter the elements of array\n";
for(int i=0;i<10;i++)
cin>>arr[i];
quick(arr,0,9);
cout<<"sorted array\n";
for(i=0;i<10;i++)
cout<<arr[i]<<"  ";
getch();
}