/*
 * bst.cpp
 *
 *  Created on: 27-Oct-2020
 *      Author: Vedant
 */
#include<iostream>
#include "BST.h"
using namespace std;

BST::BST() {
	// TODO Auto-generated constructor stub
	root=NULL;
}

node* BST::getRoot(){
	return root;
}

node* BST::createNode(int val){			//function to create a node
	node* temp=new node();				//new node created
	temp->data=val;						//assigning the value
	temp->Lnode=NULL;					//making the pointers null
	temp->Rnode=NULL;
	return temp;						//returning the node created
}

void BST::insert(int val){
	if(root==NULL)
		root=createNode(val);
	else{
		node* newNode;
		node* prevous;

		newNode=root;									//assigning the root value to traversing node

		while(newNode!=NULL){							//continue loop till leaf node if reached

			prevous=newNode;
			if(newNode->data==val) {					//checking if current node has data same as val
				cout<<"\nValue Already Exist";
				return;
			}
			else if(newNode->data>val)					//moving to left node for smaller val
				newNode=newNode->Lnode;
			else if(newNode->data<val)					//moving to right node for greater val
				newNode=newNode->Rnode;
		}

		newNode=createNode(val);						//now creating new node

		if(prevous->data>val)							//assigning the new node as a child to previous node
			prevous->Lnode=newNode;
		else
			prevous->Rnode=newNode;
	}
}

node* BST::search(node* tempNode,int key){

	if(tempNode!=NULL) {												//checking if leaf node
		if(tempNode->data==key) return tempNode;						//element found
		else if(tempNode->data>key)	return search(tempNode->Lnode,key);	//traversing left side
		else return search(tempNode->Rnode,key);						//traversing right part
	}

	return tempNode;
}

void BST::postTraverseRecur(node* temp) {
	if(temp->Lnode!=NULL)	postTraverseRecur(temp->Lnode);		//traversing the left child
	if(temp->Rnode!=NULL)	postTraverseRecur(temp->Rnode);		//traversing the right child
	cout<<'|'<<temp->data;											//traversing the node
}

void BST::LeafNodes(node* temp) {
	if(temp->Lnode!=NULL)	LeafNodes(temp->Lnode);		//traversing the left child
	if(temp->Rnode!=NULL)	LeafNodes(temp->Rnode);		//traversing the right child

	if(temp->Lnode==NULL and temp->Rnode==NULL)			//checking for leaf node
		cout<<temp->data<<" ";
}

node* BST::mirrorTree(node* temp) {
	if(temp!=NULL) {
		temp->Lnode=mirrorTree(temp->Lnode);
		temp->Rnode=mirrorTree(temp->Rnode);

		node* swapNode;
		swapNode=temp->Lnode;
		temp->Lnode=temp->Rnode;
		temp->Rnode=swapNode;
	}
	return temp;
}

node* BST::maxOf(node* temp) {
	while(temp->Rnode!=NULL)
		temp=temp->Rnode;
	return temp;
}

node* BST::deleteNode(node* temp,int key) {

	if(temp==NULL)	return NULL;

	if(key<temp->data)									//traversing the left child
		temp->Lnode=deleteNode(temp->Lnode,key);
	else if(key>temp->data)								//traversing the right child
		temp->Rnode=deleteNode(temp->Rnode,key);
	else{												//element found

		node* reference=temp;

		if(temp->Lnode==NULL and temp->Rnode==NULL){		//no children
			temp=NULL;
			delete reference;
			cout<<"\nDeleted Successfully"<<endl;
		}
		else if(temp->Lnode==NULL) {						//only right child
			temp=temp->Rnode;
			delete reference;
			cout<<"\nDeleted Successfully"<<endl;
		}
		else if(temp->Rnode==NULL) {						//only left child
			temp=temp->Lnode;
			delete reference;
			cout<<"\nDeleted Successfully"<<endl;
		}
		else {											//both child are present
			node* max=maxOf(temp->Lnode);				//getting the max value left subTree of target tree
			int maxVal=max->data;						//storing the max Val
			temp=deleteNode(temp,max->data);			//deleting the node with max value
			temp->data=maxVal;							//assigning the max value to the current node
			delete max;									//deleting the copy of max node
		}
	}
	return temp;										//returning the updated node
}
BST::~BST() {
	// TODO Auto-generated destructor stub
}

