/*
 * tree.cpp
 *
 *  Created on: 20-Oct-2020
 *      Author: Vedant
 */

#include<iostream>
#include "tree.h"
#include "stack.h"
#include "stack.cpp"
using namespace std;

tree::tree() {
	// TODO Auto-generated constructor stub
	root=NULL;
}

Tree_node* tree::getRoot()
{
	return root;
}

Tree_node* tree::makeTree(char val){
	Tree_node* temp=new Tree_node();
	temp->data=val;
	temp->LNode=NULL;
	temp->RNode=NULL;
	return temp;
}

Tree_node* tree::createTreePost(string postfixExpTree)
{
	int index;

	Stack<Tree_node*> stack;						//creating Stack for string our nodes

	for(index=0;index<int(postfixExpTree.length());index++)			//traversing through the string
	{
		Tree_node* temp=makeTree(postfixExpTree[index]);			//creating the new tree

		if(isalpha(postfixExpTree[index])) {		//if operand
			stack.push(temp);
		}
		else {										//if operator
			temp->RNode=stack.pop();
			temp->LNode=stack.pop();
			root=temp;								//updating the root node
			stack.push(temp);
		}
	}

	return stack.pop();
}

Tree_node* tree::createTreePre(string prefixExpTree)
{
	int index;

	Stack<Tree_node*> stack;						//creating Stack for string our nodes

	for(index=int(prefixExpTree.length())-1;index>=0;index--)	//traversing through the string
	{
		Tree_node* temp=makeTree(prefixExpTree[index]);			//creating the new tree

		if(isalpha(prefixExpTree[index])) {			//if operand
			stack.push(temp);
		}
		else {										//if operator
			temp->RNode=stack.pop();
			temp->LNode=stack.pop();
			root=temp;								//updating the root node
			stack.push(temp);
		}
	}

	return stack.pop();
}

void tree::postTraverseRecur(Tree_node* temp) {
	if(temp->LNode!=NULL)	postTraverseRecur(temp->LNode);		//traversing the left child
	if(temp->RNode!=NULL)	postTraverseRecur(temp->RNode);		//traversing the right child
	cout<<temp->data;											//traversing the node
}

void tree::preTraverseRecur(Tree_node* temp) {
	if(temp!=NULL) cout<<temp->data;							//traversing the node
	if(temp->LNode!=NULL)	preTraverseRecur(temp->LNode);		//traversing the left child
	if(temp->RNode!=NULL)	preTraverseRecur(temp->RNode);		//traversing the right child
}

void tree::preTraverseNonRecur(Tree_node* root){

	if(root==NULL)	return;										//tree is empty

	Stack<Tree_node*>* stack=new Stack<Tree_node*>();
	Tree_node* temp=root;
	stack->push(temp);

	while(!stack->isEmpty()) {
		temp=stack->pop();

		while(temp!=NULL){
			cout<<temp->data;
			if(temp->RNode!=NULL)
				stack->push(temp->RNode);
			temp=temp->LNode;
		}
	}
}



tree::~tree() {
	// TODO Auto-generated destructor stub
}

