//============================================================================
// Name        : Linked_List.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Singly Linked List
//============================================================================

#include<bits/stdc++.h>
#define f(i,s,n) for(int i=s;i<=n;i++)
#define ul unsigned long long int
#define ll long long int
#define vi vector<int>
using namespace std;

struct node
{
	int val;
	node* nxt;
};

node* head1=NULL;		//list 1
node* head2=NULL;		//list 2
node* head3=NULL;		//list 3

void addFront(node* head,int num)					//adding the element at the end
{
	node* temp=new node();				//getting new node

	temp->nxt=head;						//setting the nxt of new node to head
	head=temp;							//adding the new node at the first
	head->val=num;						//setting the value of first element to head
}

void addLast(node* head,int num)							//add element at the end
{
	node* temp=head;							//setting the iterative pointer to Head

	if(head==NULL)								//checking if the list is empty
	{
		temp=new node();						//adding new node at the front
		head=temp;
		temp->val=num;							//setting the value of the first element
		return;
	}

	while(temp->nxt!=NULL)	temp=temp->nxt;		//going to the last node

	temp->nxt=new node();						//adding new node at the end of list
	temp->nxt->val=num;
}

void insert(node* head,int pos,int value)
{
	cout<<"Hello";
	node* newTemp=new node();
	if(pos==1)							//checking if we have add at front
	{
		node* temp=new node();
		temp->val=value;
		temp->nxt=head;
		head=temp;
	}

	else
	{
		node* Traverser;						//node to traverse through the list
		Traverser=head;							//setting the traverser to Head
		for(int i=1;i<=(pos-2);i++)				//going to the (pos-1)th node
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

void delFirst(node* head){
	node* temp=head;		//storing the address of current head
	head=head->nxt;			//assigning the new value of head
	delete temp;			//deleting the previous
}

void delLast(node* head){
	if(head==NULL) return;

	node* temp=head;		//setting the value to head

	while(temp->nxt!=NULL)	//traversing to the (n-1)th node
		temp=temp->nxt;

	delete temp;			//deleting the nth node
}

void del(node* head,int n)
{
	node* position;						//pointer to go to nth node
	node* previous;						//pointer to store the n-1th node
	int i=1;
	position=head;

	if(n==1)							//if asked to delete first element
	{
		position=head;
		head=head->nxt;
		delete position;
	}

	while(i<(n-1))						//traversing to n-1th node
	{
		position=position->nxt;
		i+=1;
		if(position==NULL and i<(n-1))	//index entered is out of bound
		{
			cout<<"Index Error"<<endl;
			return;
		}
	}

	previous=position->nxt;				//deleting the node and setting n-1th next to n+1
	position->nxt=previous->nxt;
	delete previous;
}

void revert(node* head){					//reverting the linked list, parameter passed is head
	node* newHead=NULL;				//new Head of new Linked list created

	while(head!=NULL){			//traversing through the old head

		node* temp=new node();
		temp->val=head->val;

		if(newHead==NULL)
			newHead=temp;

		else{
			node* temp1=newHead;	//adding at the front of new LL
			newHead=temp;
			newHead->nxt=temp1;
		}

		temp=head;				//storing the value of old
		head=head->nxt;
		delete temp;
	}

	head=newHead;
}

void sort(node* head)
{
	if(head==NULL)	return;

	node* temp1;								//for passes
	node* temp2;								//for comparing elements
	temp1=head;

	while(temp1!=NULL) {						//loop for pass
		temp2=temp1->nxt;

		while(temp2!=NULL){
			if(temp1->val>temp2->val) {			//comparing the values

				int t=temp1->val;				//swapping the both values
				temp1->val=temp2->val;
				temp2->val=t;
			}
			temp2=temp2->nxt;					//moving to next node to compare
		}

		temp1=temp1->nxt;						//moving to next pass
	}
}

node* merge(node* head1,node* head2){
	node* combined=NULL;								//new list to store the combination of both
	node* temp=head1;

	while(temp!=NULL)							//inserting the elements of first LL
		addLast(combined,temp->val);

	temp=head2;

	while(temp!=NULL)							//inserting the elements of second LL
		addLast(combined,temp->val);

	return combined;							//returning the combination of two strings
}

void print(node* head)
{
	node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->val<<"|";
		temp=temp->nxt;
	}
	cout<<endl;
}

void reverseDisplay(node* temp)
{
	if(temp!=NULL)							//checking if last node reached
	{
		reverseDisplay(temp->nxt);			//making recursive call
		cout<<"|"<<temp->val;				//printing the value
	}
}

int main()
{
	// insert an element - insert( position(1,2,3....) , value )
	// delete an element - del( position(1,2,3.....) )
	// print the list - print()

	//inserting 1-10 inside list 1 and i th position

	for(int i=0;i<=9;i++) {
		insert(head1,i+1,i);
	}

	addFront(head1,100);		//adding to front
	addLast(head1,-99);			//adding to last
	insert(head1,3,66);			//adding 66 and 3rd position

	print(head1);				//printing list 1
	reverseDisplay(head1);		//printing reverse order of list 1
	cout<<endl;
	revert(head1);				//reverting the list 1
	print(head1);				//printing after reverting

	delFirst(head1);			//deleting the first element
	delLast(head1);				//deleting last element
	del(head1,5);				//deleting 5th element

	//creating second list of 3 elements
	addFront(head2,20);			//adding at front
	addLast(head2,-16);			//adding at last
	insert(head2,2,57);			//adding at 2nd position

	print(head2);				//printing list 2

	head3=merge(head1,head2);	//merging three LL in head3
	print(head3);
}
