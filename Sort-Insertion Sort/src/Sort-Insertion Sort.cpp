//============================================================================
// Name        : Sort-Insertion.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void ins_sort(int a[],int n)
{
	for(int i=1;i<n;i++)	//loop for PASS
	{
		for(int j=0;j<i;j++)	//loop for Comparison
		{
			if(a[j]>a[i])	//Ascending '>' and for Descending '<'
			{
				int l=a[i];
				for(int k=i;k>j;k--)	//loop to shifting the elements
				{
					a[k]=a[k-1];
				}
				a[j]=l;
			}
		}
	}
}

int* ins_sort_ins(int a[],int n,int x)
{
	int k=0;

	int* b=new int[n+1];

	while(a[k]<x)
	{
		b[k]=a[k];
		k++;
	}

	for(int i=n;i>k;i++)
	{
		a[i]=a[i-1];
	}

	a[k]=x;

	return a;
}

int main()	{
	int a[11]={6,4,3,8,5,2,1,16,13,12};

	ins_sort(a,10);

	for(int i=0;i<10;i++)	cout<<a[i]<<" ";

	cout<<endl;

	ins_sort_ins(a,10,7);

	for(int i=0;i<10;i++)	cout<<a[i]<<" ";

}
