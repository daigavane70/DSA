//============================================================================
// Name        : Sorting.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int counter=0;

void sel_sort(int arr[],int n)	//function to sort array
{
	for(int i=0;i<n-1;i++)		//loop to select the end of sorted array at the begining
	{
		for(int j=i+1;j<n;j++)	//loop to traverse through the unsorted array
		{
			if(arr[j]<arr[i])	//swapping ascending - '<' and descending - '>'
			{
				arr[i]=arr[i]+arr[j];
				arr[j]=arr[i]-arr[j];
				arr[i]=arr[i]-arr[j];

				counter++;
			}
		}
	}
	cout<<counter;
}

int main()
{
	int a[10]={1, 2, 4, 3, 7, 5, 6};

	sel_sort(a,7);

	for(int i=0;i<7;i++)
	{
		cout<<a[i]<<" ";
	}
}
