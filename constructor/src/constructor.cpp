//============================================================================
// Name        : constructor.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class classA
{
	int a=12;

public:

	classA(int n)
	{
		a=n;
	}

	void display()
	{
		cout<<"\nThe Number You have Entered is "<<a;
	}
};

int main() {
	int n;
	cout<<"Enter a Number: ";
	cin>>n;
	classA obj(n);
	obj.display();
}
