/*
 * TBT.cpp
 *
 *  Created on: 05-Nov-2020
 *      Author: Vedant
 */

#include "TBT.h"
#include<iostream>
using namespace std;

TBT::TBT() {
	// TODO Auto-generated constructor stub
	root=NULL;
	head=NULL;
}

node* TBT::getHead() {
	return head;
}

void TBT::createRoot(int val) {
	head=getNode('$');
	head->Lthread=head->Rthread=true;
	head->Lnode=head;
	head->Rnode=head;

	root=getNode(val);
	root->Lthread=root->Rthread=true;
	head->Lnode=root;
	head->Lthread=false;
}

node* TBT::getNode(int val) {
	node* temp=new node();			//creating the new node
	temp->data=val;					//assigning the value
	temp->Lthread=true;
	temp->Rthread=true;
	temp->Lnode=NULL;
	temp->Rnode=NULL;
	return temp;					//returning the new node created
}

void TBT::insert(int val) {
	if(head==NULL) {
		cout<<"Tree was empty, Created the Root Node with value "<<val;
		createRoot(val);
		return;
	}

	node* parent;
	parent=head->Lnode;

	int choice=0;

	while(true) {
		cout<<"\nCurrent Node Value: "<<parent->data<<"\n1. Insert Left\n2. Insert Right\n3. Cancel";
		cout<<"\n Select: ";
		cin>>choice;

		node* temp;

		if(choice==1){						//inserting on left side
			if(parent->Lthread)
			{
				temp=getNode(val);				//getting the new node
				temp->Lnode=parent->Lnode;		//threading the new node
				parent->Lnode=temp;				//setting the left node to new node
				temp->Rnode=parent;				//setting the left thread to false
				parent->Lthread=false;
				break;
			}
			else	parent=parent->Lnode;		//cannot be inserted at this end not a leaf node
		}
		if(choice==2){
			if(parent->Rthread)
			{
				temp=getNode(val);				//inserting on left side
				temp->Lnode=parent;			//getting the new node
				temp->Rnode=parent->Rnode;		//threading the new node
				parent->Rnode=temp;				//setting the left node to new node
				parent->Rthread=false;			//setting the right thread to false
				break;
			}
			else parent=parent->Rnode;			//cannot be inserted at this end, not a leaf node
		}
		}

	this->InorderRec(getHead()->Lnode);
}

void TBT::preOrderTraversal() {
	node *traversar=head->Lnode;//take a pointer and point it to head
	if(traversar==head){
					//if head is null print empty tree
		cout<<"Empty tree"<<endl;
		return;
	}
	while(traversar!=head){
					//if head is not null
		cout<<" "<<traversar->data;//print the data
		if(!(traversar->Lthread)){
			//if left child is present
			traversar=traversar->Lnode;//point temp to left child and iterate the loop again
			continue;
		}
		else{
			//if no left child go to right subtree
			while(traversar->Rthread && traversar!=head){//if no sub-child
				traversar=traversar->Rnode;//point to successor
			}
		}
		if(!(traversar->Rthread)&&(traversar!=head)){
						//if right child is present
			traversar=traversar->Rnode;//point to the next node
		}
	}

	cout<<"Ended Successfully";
}

void TBT::inOrderTraversal() {
	node* traversar;
	traversar=head->Lnode;

	if(traversar==head)	{								//checking if the tree is empty or not
		cout<<"Tree is Empty";
		return;
	}

	while(!traversar->Lthread)	traversar=traversar->Lnode;	//going to the leftmost child

	while(traversar!=head) {
		cout<<traversar->data<<' ';							//print the element

		traversar=traversar->Rnode;							//traverse to the right successor or right child
		if(traversar->Rthread)	continue;
		else {
			while(!traversar->Lthread and traversar!=head)	//if its not a successor then traverse the left sub tree of child
				traversar=traversar->Lnode;
		}
	}
}

void TBT::InorderRec(node* temp){
	if(!temp->Lthread)	InorderRec(temp->Lnode);
	cout<<temp->data<<' ';
	if(!temp->Rthread)	InorderRec(temp->Rnode);
}

TBT::~TBT() {
	// TODO Auto-generated destructor stub
}


