/*
 * q1.h
 *
 *  Created on: 08-Sep-2020
 *      Author: Vedant
 */

#include<iostream>
#ifndef QUEUE_H_
#define QUEUE_H_

struct Patient{
	int ID;						//special identity of patient on the
	std::string name;			//full name of patient
	int age;					//age of patient
	std::string disease;		//disesase the patient is suffering
};



class Queue {
	Patient* queue;
	int size;			//size of queues
	int front;			//first patient
	int rear;			//last patient
public:
	void addPatient(Patient);
	bool isEmpty();
	bool isFull();
	void removePatient();
	bool duplicate(std::string);
	void display();
	Queue(int);
	virtual ~Queue();
};

#endif /* QUEUE_H_ */
