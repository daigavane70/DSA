/*
 * Queue.cpp
 *
 *  Created on: 08-Sep-2020
 *      Author: Vedant
 */

#include<bits/stdc++.h>
#include<iostream>

#include "Queue.h"

using namespace std;

Queue::Queue(int length) {
	// TODO Auto-generated constructor stub
	front=-1;							//first patient
	rear=-1;							//end patient
	size=length;						//max size of queue
	queue=new Patient[size];			//creating an array of length 'size'
}

void Queue::addPatient(Patient newPatient)			//method to add to queue
{
	//checking if the queue is empty
	if(this->isEmpty())
	{
		front++;								//incrementing the front
		rear++;									//incrementing the rear
		queue[rear]=newPatient;					//adding the new patient at rear side
	}

	//Not Full
	else if(!this->isFull())
	{
		//no. of patients should be betn 0 to (size-1)
		rear=(rear+1)%size;						//incrementing rear

		queue[rear]=newPatient;			//adding the new patient at the end
	}

	//queue full Condition
	else
		cout<<"\nQueue is Full";

	//making sure that counter does not exceed the max value
}

void Queue::removePatient()						//method to remove patient
{
	if(this->isEmpty())							//already empty list
		return;

	else if(!this->isEmpty()){

		if(front==rear)							//checking if only element present in the list
		{
			front=-1;							//empty list condition
			rear=-1;
		}

		else									//more than one element present in the list
			front=(front+1)%size;				//incrementing front value
	}

	else										//zero elements in the list
		cout<<"Queue is Empty";
}

bool Queue::isEmpty()
{
//	if(front==rear and rear==-1)
	if(front==-1)					//checking if the list is empty
		return true;
	else											//not empty
		return false;
}

bool Queue::isFull()
{
//	if(front==0 and rear==size-1)
	if((rear+1)%size==front)		//queue full condition
		return true;
	else
		return false;
}

bool Queue::duplicate(string name)
{
	if(front!=-1)
	{
	for(int i=0;(front+i)%size!=rear;i++)					//checking with the patients
	{
		if(queue[(front+i)%size].name==name)
			return true;
	}

	if(queue[rear].name==name)
		return true;										//checking with the rear position

	}

	return false;
}

void Queue::display()
{
	if(front!=-1)
	{
	cout<<endl;

	for(int i=0;(front+i)%size!=rear;i++)					//printing all the elements till rear(rear not included)
	{
		cout<<queue[(front+i)%size].name<<"|";
	}

	cout<<queue[rear].name<<"|";							//printing the rear Value
	cout<<endl<<endl;
	cout<<"front: "<<front<<"| rear: "<<rear<<endl;
	}
}

Queue::~Queue() {
}
