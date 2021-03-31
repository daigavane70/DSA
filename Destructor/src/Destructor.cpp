//============================================================================
// Name        : Destructor.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class sample
{
	int *ptr;	//	defining a pointer variable
public:

	sample(int n)	//Constructor
	{
		ptr=new int();	//dynamically allocating memory for ptr
		*ptr=n;
	}

	~sample()	//destructor
	{
		cout<<"deleted pointer "<<*ptr<<endl;
		delete ptr;	//deleting ptr pointer
	}
};

int main() {

	//block 1
	{
	cout<<"Block 1"<<endl;
	sample obj(1);
	cout<<"Block 1 closed"<<endl;
	}

	//block 2
	{
	cout<<"Block 2"<<endl;
	sample obj(2);
	cout<<"Block 2 closed"<<endl;
	}
}
