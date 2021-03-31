//============================================================================
// Name        : BST-Assignment.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "BST.h"
#include <iostream>
using namespace std;

int main() {
	BST tree;
	int item;
	int choice=0;

	while(choice<7) {
		cout<<"\n-------------------------"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Remove"<<endl;
		cout<<"3. Search"<<endl;
		cout<<"4. Mirror"<<endl;
		cout<<"5. Leaf Nodes"<<endl;
		cout<<"6. Post-Ord Traversal"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"-------------------------"<<endl;
		cout<<"Enter Choice: "<<endl;
		cin>>choice;
		cout<<"-------------------------"<<endl;

		switch(choice) {
		case 1:{
			cout<<"\nEnter the Element you want to enter: ";
			cin>>item;
			tree.insert(item);
			break;
		}
		case 2:{
			if(tree.getRoot()!=NULL)								//checking if the tree is empty
			{
				cout<<"\nEnter the ELement you want to Delete: ";
				cin>>item;
				tree.deleteNode(tree.getRoot(),item);
			}
			else cout<<"\nThe tree is Empty"<<endl;

			break;
		}
		case 3:{
			if(tree.getRoot()!=NULL){							//checking for empty tree
			cout<<"\nEnter the element you want to search: ";
			cin>>item;
			node* result=tree.search(tree.getRoot(),item);
			if(result!=NULL)
				cout<<"\n Element Found"<<endl;
			else
				cout<<"\n Not Found";
			}

			else cout<<"\n Tree is Empty"<<endl;

			break;
		}
		case 4:{
			if(tree.getRoot()!=NULL)							//checking for empty tree
			{
			tree.mirrorTree(tree.getRoot());
			cout<<"\nThe tree has been mirrored";
			}
			else cout<<"\nThe tree is Empty"<<endl;
			break;
		}
		case 5:{
			if(tree.getRoot()!=NULL)							//checking for empty tree
			{
			cout<<"\nLeaf Nodes: ";
			tree.LeafNodes(tree.getRoot());
			}
			else	cout<<"\nEmpty Tree"<<endl;
			break;
		}
		case 6:{
			tree.postTraverseRecur(tree.getRoot());
			break;
		}
		}
	}
return 0;
}
