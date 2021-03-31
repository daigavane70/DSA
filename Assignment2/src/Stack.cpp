/*
 * Stack.cpp
 *
 *  Created on: 23-Sep-2020
 *      Author: Vedant
 */

#include "Stack.h"
#include<iostream>
using namespace std;

template <class T>
Stack<T>::Stack() {
	// TODO Auto-generated constructor stub
	head=NULL;
}

template <class T>
node<T>* Stack<T>::getHead()
{
	return head;
}

template <class T>
void Stack<T>::push(T a)				//insert top
{
	node<T>* temp=new node<T>();
	temp->val=a;
	temp->nxt=head;

	head=temp;
}
template <class T>
T Stack<T>::pop()					//remove top value
{
	T temp=head->val;
	node<T> *storeHead;
	storeHead=head;
	head=head->nxt;
	delete storeHead;
	return temp;
}

template <class T>
T Stack<T>::peep()					//return top element
{
	if(!this->isEmpty())
		return head->val;
	else return '\0';
}

template <class T>
bool Stack<T>::isEmpty()
{
	if(head==NULL) return true;
	else return false;
}

template <class T>
void Stack<T>::print()
{
	node<T> *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<"\n |"<<temp->val<<"\t|";
		temp=temp->nxt;
	}
}

template <class T>
Stack<T>::~Stack() {
	// TODO Auto-generated destructor stub
}

