//============================================================================
// Name        : Sorting.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void bubble(int arr[])
{
	int n=10;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
		if(arr[j]>arr[j+1])	//swapping "In case of descending just replace '>' by '<'"
		{
			arr[j]=arr[j]+arr[j+1];
			arr[j+1]=arr[j]-arr[j+1];
			arr[j]=arr[j]-arr[j+1];
		}
		}
	}
}

int main() {
	int a[10]={1,1,23,4,3,2,55,6,7,5};

	bubble(a);

	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<" ";
	}
}
