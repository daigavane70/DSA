//============================================================================
// Name        : Duplicate.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	int a[5];	//declaring an int array of size 5
	for(int i=0;i<5;i++)	cin>>a[i];	//loop to read all the elements of array
	for(int i=2;i<5;i++)	//comparing each element of the array with the previous elements
	{
		for(int j=0;j<i;j++)
		{
			if(a[i]==a[j])	//Duplicate is found
			{
				cout<<a[i]<<" has a Duplicate"<<endl;
			}
		}
	}
}
