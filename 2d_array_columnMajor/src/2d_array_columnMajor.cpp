//============================================================================
// Name        : 2d_array_columnMajor.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int a[12]={1,2,3,4,5,6,7,8,9,10,11,12};

	int b[6][2];
	int c[2][6];

	for(int i=0;i<6;i++)
	{
		for(int j=0;j<2;j++)
		{
			b[i][j]=a[i*2+j];
			cout<<b[i][j]<<"-("<<b+(i*6*4)+(j*4)<<")"<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<6;j++)
		{
			c[i][j]=a[i*6+j];
			cout<<c[i][j]<<"-("<<c+(i*2*4)+(j*4)<<")"<<" ";
		}
		cout<<endl;
	}
}
