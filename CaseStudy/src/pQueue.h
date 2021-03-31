
#ifndef PQUEUE_H_
#define PQUEUE_H_
#include<iostream>
using namespace std;


struct Patient{
	int ID;						//special identity of patient on the
	string name;				//full name of patient
	int age;					//age of patient
	string disease;				//disesase the patient is suffering
};

struct node{
	Patient* patient;			//this will store the address of the patient details
	node* next;					//pointer to point to the next element in the list
	int priority;				//setting the priority of the current patient
};

class pQueue {
	node*  queue;
public:
	void addPatient(Patient*,int);	//adding new patient to the list
	string removePatient();			//dequeue operation to remove the rgent patient
	string name();					//to get the name of the urgent patient
	int frontPriority();			//get the priority of the front/urgent patient
	bool isEmpty();					//check if the queue is empty/not
	void display();					//display the names of the patient in the queue according to priority
	pQueue();						//constructor to initialize the empty queue
	virtual ~pQueue();				//destructor to delete the patients
};

#endif /* PQUEUE_H_ */
