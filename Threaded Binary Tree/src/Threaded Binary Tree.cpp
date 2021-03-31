//============================================================================
// Name        : Threaded.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Threaded Binary Tree
//============================================================================

#include "TBT.h"
#include <iostream>
using namespace std;

int main() {
	TBT tree;
	int item;
	int choice=0;

	while(choice<4) {
		cout<<"\n-------------------------"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. PreOrderTraversal"<<endl;
		cout<<"3. InorderTraversal"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"-------------------------"<<endl;
		cout<<"Enter Choice: "<<endl;
		cin>>choice;
		cout<<"-------------------------"<<endl;

		switch(choice) {
		case 1: {
			cout<<"Enter the Element you want to Insert: ";
			cin>>item;
			tree.insert(item);
			break;
		}
		case 2: {
			tree.preOrderTraversal();
			break;
		}
		case 3: {
			tree.inOrderTraversal();
			break;
		}
		}
	}
return 0;
}
