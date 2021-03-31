
#include "pQueue.h"

pQueue::pQueue() {
	// TODO Auto-generated constructor stub
	queue = NULL;
}

void pQueue::addPatient(Patient* newPatient,int currPriority){

	//queue is empty
	if(queue == NULL){
		queue=new node();						//creating a new Node
		queue->patient = newPatient;			//adding the new patient at the front
		queue->priority = currPriority;			//storing the priority
		queue->next = NULL;						//only one patient, no other
		return;
	}

	//if queue is not empty
	else{

		node* temp;								//creating a temporary node to traverse

		//for inserting in front
		if(queue->priority < currPriority){
			temp = new node();					//creating new node

			temp->patient = newPatient;			//assigning the patient
			temp->priority = currPriority;		//setting the priority
			temp->next = queue;					//making the current front element as the 2nd

			queue=temp;							//setting the queue to the current first node
		}

		//for inserting at nth place
		else{
			temp=queue;
			while(temp->next != NULL){						//traversing the priority queue

				if(temp->next->priority < currPriority){	//checking for the prioties that are less

					node* newNode = new node();				//creating a new Node

					newNode->patient = newPatient;			//assigning the patient
					newNode->priority = currPriority;		//setting priority
					newNode->next = temp->next;				//arranging the pateints accordign to their priorities

					temp->next=newNode;						//new node inserted

					return;
				}
			}

			//insertion at the end of the queue
			node* newNode = new node();				//creating a new Node

			newNode->patient = newPatient;			//assigning the patient
			newNode->priority = currPriority;		//setting priority
			newNode->next = temp->next;				//arranging the pateints accordign to their priorities

			temp->next=newNode;						//new node inserted
		}
	}
}

string pQueue::removePatient(){
	if( !isEmpty() ){
		Patient* temp = (queue->patient);				//storing the urgent patient into the temp variable

		string name=temp->name;							//storing the name of urgent patient

		queue=queue->next;								//moving the queue to its next node

		delete temp;									//deleting the urgent patient from the queue

		return name;									//returning the name of the first patient
	}

	else
		return "\0";
}
string pQueue::name(){
	if( !isEmpty() )					//checking if empty queue
		return queue->patient->name;	//returning the name
	else
		return "\0";					//returning the empty queue
}

int pQueue::frontPriority(){

	if( !isEmpty() )					//checking for empty queue
		return queue->priority;			//returning the priority of urgent patient

	else								//queue is empty
		return -1;
}

bool pQueue::isEmpty(){
	if(queue == NULL)	return true;	//queue is empty
	else return false;					//not empty
}

void pQueue::display(){
	node* temp=queue;						//creating a temporary node for traversal

	while(temp != NULL)	{					//traversing the queue
		cout<<" |"<<temp->patient->name;	//displaying the name
		temp=temp->next;					//moving to the next node
	}
}

pQueue::~pQueue() {
	// TODO Auto-generated destructor stub
}

