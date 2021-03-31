//============================================================================
// Name        : Heap.cpp
// Author      : Vedant Daigavane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "hsort.h"
using namespace std;

int main() {
	int choice=0;
	hsort Heap;

	while(choice<4){
		cout<<"\n\n-----------------------------"<<endl;
		cout<<"1. Create Heap"<<endl;
		cout<<"2. Insert"<<endl;
		cout<<"3. Delete"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<"Enter Choice: ";
		cin>>choice;
		cout<<"-----------------------------"<<endl;
		switch(choice) {

		case 1: {
			Heap.create();
			break;
		}
		case 2:{
			Heap.insert();
			break;
		}
		case 3:{
			Heap.del();
			break;
		}
		default:
			return 0;
		}
	}
}
