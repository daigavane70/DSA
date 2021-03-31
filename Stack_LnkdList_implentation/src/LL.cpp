/*
 * LL.cpp
 *
 *  Created on: 16-Sep-2020
 *      Author: Vedant
 */

#include "LL.h"
#include<iostream>
#include<iomanip>
using namespace std;

LL::LL()
{
	head=NULL;							//initializing head to NULL
}

node* LL::returnHead()
{
	return head;
}

node* LL::newNode()						//creating new node
{
	node* newNode=new node();	//creating new node
	newNode->nxt=NULL;			//setting the nxt of newNode to NULL
	return newNode;				//returning the node created
}

void LL::addFront(int num)				//adding the element at the end
{
	node* temp=newNode();				//getting new node

	temp->nxt=head;						//setting the nxt of new node to head
	head=temp;						//adding the new node at the first
	head->val=num;						//setting the value of first element to head
}

void LL::insert(int pos,int value)
{
	node* newTemp=newNode();
	if(pos==1)							//checking if we have add at front
	{
		addFront(value);
	}

	else
	{
		node* Traverser;				//node to traverse through the list
		Traverser=head;					//setting the traverser to Head
		for(int i=1;i<=(pos-2);i++)		//going to the (pos-1)th node
		{
			Traverser=Traverser->nxt;			//moving the traverser to next node

			if(Traverser==NULL and i<(pos-2))	//checking of the pos is greater than size of list
			{
			cout<<"Invalid Index"<<endl;
			return;
			}
		}
		//now the traverser is pointing to the (pos-1)th node

		newTemp->nxt=Traverser->nxt;	//storing the address of (pos/newNode+1)th node in next of (pos/newNode) node
		Traverser->nxt=newTemp;			//storing the address of (pos/newNode)th node in next (pos/newNode)th node
		newTemp->val=value;				//assigning the value of (pos/newNode)th node
	}
}

void LL::addLast(int num)				//add element at the end
{
	node* temp=head;					//setting the iterative pointer to Head

	if(head==NULL)						//checking if the list is empty
	{
		temp=newNode();					//adding new node at the front
		head=temp;
		temp->val=num;					//setting the value of the first element
		return;
	}

	while(temp->nxt!=NULL)	temp=temp->nxt;		//going to the last node

	temp->nxt=newNode();						//adding new node at the end of list
	temp->nxt->val=num;
}

void LL::del(int n)						//to delete the nth position element
{
	node* travNode;						//node to traverse thorugh the list
	int i=1;							//iterator
	travNode=head;						//setting the traversing node to head

	if(n==1)							//checking if n==1
	{
		travNode=head;					//storing the address of first node
		head=head->nxt;					//updating the head node to second node
		delete travNode;				//deleting the first node by using the address we stored first
		return;
	}

	while(i<(n-1))						//traversing to the (n-1)th node
	{
		travNode=travNode->nxt;			//moving to the next node
		i+=1;							//incrementing the iterator
		if(travNode==NULL and i<(n-1))	//checking if the index is greater than the elements in the linked list
		{
			cout<<"Index Error"<<endl;
			return;
		}
	}

	node* k;							//pointer to store the address of (n)th node
	k=travNode->nxt;					//storing the address of (n)th node in k
	travNode->nxt=k->nxt;				//setting the next of (n-1)th node to (n+1)th node
	delete k;							//deleting the (n)th node
}

void LL::display()
{
	node* temp;
	temp=head;

	if(head==NULL)	cout<<"LIST IS EMPTY";				//list if empty

	else												//list if not empty
	{
		while(temp!=NULL)									//going to the end of LinkedList
		{
			cout<<'|'<<temp->val;
			temp=temp->nxt;
		}
	}
}

void LL::reverseDisp(node* temp)
{
	if(temp!=NULL)
	{
		reverseDisp(temp->nxt);
		cout<<"|"<<temp->val;
	}
}
LL::~LL() {
	// TODO Auto-generated destructor stub
}

