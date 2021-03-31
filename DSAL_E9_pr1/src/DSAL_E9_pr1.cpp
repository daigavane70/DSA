//============================================================================
// Name        : DSAL_E9_pr1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//sorting in ascending order and finding a roll number

#include <iostream>
using namespace std;

//sort function
void sort(int a[])
{
	for(int i=0;i<9;i++)
	{
		for(int j=i+1;j<10;j++)
		{
			if(a[i]>a[j])
			{
				a[i]=a[i]+a[j];
				a[j]=a[i]-a[j];
				a[i]=a[i]-a[j];
			}
		}
	}
	for(int i=0;i<10;i++)	cout<<a[i]<<" ";
	cout<<endl;
}

//Search Function
int search(int m,int a[])
{
	for(int i=0;i<10;i++)
	{
		if(m==a[i])
		{
			return 1;
		}
	}

	return 0;
}

//display Function
void display(int a[])
{
	for(int i=0;i<10;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int a[10];
	int n=1;
	while(n>0)
	{
	cout<<"___MENU___"<<endl;
	cout<<"1. Input"<<endl;
	cout<<"2. Sort"<<endl;
	cout<<"3. Search"<<endl;
	cout<<"4. Display"<<endl;
	cout<<"5. Exit"<<endl;
	cin>>n;

//n=1
	if(n==1)
	{
		cout<<"Enter Roll Numbers of 10 student: "<<endl;
		for(int i=0;i<10;i++)	cin>>a[i];
	}

//n=2
	else if(n==2)
	{
		cout<<"Array Sorted: ";
		sort(a);
	}

//n=3
	else if(n==3)
	{
		int m;
		cout<<"Enter the element you want to search: ";
		cin>>m;
		if(search(m,a))	cout<<"Found"<<endl;
		else	cout<<"Not Found"<<endl;
	}

//n=4
	else if(n==4)
	{
		display(a);
	}
//n=5
	else	break;
	}
	return 0;
}
