//============================================================================
// Name        : Sort-Quick.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int part(int array[],int pivot,int n)
{
	int i=pivot+1;
	int j=n;

	do
	{
		while(array[i]<=array[pivot]) i++;
		while(array[j]>array[pivot]) j--;

		if(i<j)
		{
			array[i]=array[i]+array[j];
			array[j]=array[i]-array[j];
			array[i]=array[i]-array[j];
		}
	}while(i<j);

	int t=array[pivot];
	array[pivot]=array[j];
	array[j]=t;

	return j;
}

void qsort(int array[],int m,int n)
{
	if(m<n)
	{
		int j=part(array,m,n);
		cout<<"\npart1";
		for(int i=0;i<j;i++) cout<<array[i]<<" ";
		cout<<"\npart2";
		for(int i=j;i<9;i++) cout<<array[i]<<" ";

		qsort(array,m,j);
		qsort(array,j+1,n);
	}
}


int main() {
	int a[]={26,25,45,78,89,90,22,11,24};

	qsort(a,0,8);

	for(int i=0;i<9;i++)	cout<<a[i]<<" ";
}
