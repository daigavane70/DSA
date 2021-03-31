//============================================================================
// Name        : Stack_Array_Impl.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int* stack;								//array to implement array
	int size;								//size of stack

	cout<<"Enter the Size of Stack: ";
	cin>>size;								//reading size of stack


	stack=new int[size];					//creating an array of size entered

	int choice=0;							//choice of operation

	while(choice<5)
	{
		cout<<"\n<---Menu--->"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Remove"<<endl;
		cout<<"3. Is Empty"<<endl;
		cout<<"4. Is Full"<<endl;
		cout<<"5. Exit"<<endl;
	}
}
