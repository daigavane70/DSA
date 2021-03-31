
#include "pQueue.h"

int main() {
	pQueue queue;			//created new Priority Queue

	int choice=0;			//variable to store the choice of integer

	while(choice<7){
		cout<<"\n---------Menu--------"<<endl;
		cout<<"1. Add Patient"<<endl;
		cout<<"2. Remove Patient"<<endl;
		cout<<"3. Urgent Patient Name"<<endl;
		cout<<"4. Front Priority"<<endl;
		cout<<"5. Empty"<<endl;
		cout<<"6. Display"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"-----------------------"<<endl;
		cout<<"Enter Your Choice: ";
		cin>>choice;
		cout<<"-----------------------"<<endl;

		switch(choice){

		case 1:{

			Patient* newPatient=new Patient();				//store the patient details
			int priority;									//to store the priority of the patient

			cout<<endl<<"<---Enter Patient Details--->"<<endl;
			cout<<"Name: ";
			getline(cin,newPatient->name);			//ignoring the bugger created
			getline(cin,newPatient->name);			//readint the patients name
			cout<<"Priority: ";
			cin>>priority;							//readign the priority

			queue.addPatient(newPatient,priority);

			cout<<"<----Inserted---->"<<endl;
			queue.display();

			break;
		}

		case 2:{

			if( !queue.isEmpty() ){							//if queue not empty
				cout<<queue.removePatient()<<" removed";	//calling the remove patient
			}
			else cout<<"List is already Empty"<<endl;

			break;
		}

		case 3:{
			string name=queue.name();								//storing its name

			if(name != "\0")	cout<<"Front Patient "<<name<<endl;	//print the name
			else	cout<<"Queue is Empty"<<endl;					//queue is empty

			break;
		}

		case 4:{

			if(queue.frontPriority() != -1)	cout<<"Urgent Patient Priority: "<<queue.frontPriority()<<endl;	//print the priority
			else	cout<<"Queue is Empty"<<endl;				//queue is empty

			break;

		}

		case 5:{
			if(queue.isEmpty())	cout<<"YES"<<endl;				//queue is empty
			else cout<<"NO"<<endl;								//not Empty
			break;
		}

		case 6:{
			queue.display();									//calling the display function
			break;
		}

		}
	}

}

/*
 *
---------Menu--------
1. Add Patient
2. Remove Patient
3. Urgent Patient Name
4. Front Priority
5. Empty
6. Display
7. Exit
-----------------------
Enter Your Choice: 1
-----------------------

<---Enter Patient Details--->
Name: Vedant Daigavane
Priority: 2
<----Inserted---->
 |Vedant Daigavane
---------Menu--------
1. Add Patient
2. Remove Patient
3. Urgent Patient Name
4. Front Priority
5. Empty
6. Display
7. Exit
-----------------------
Enter Your Choice: 1
-----------------------

<---Enter Patient Details--->
Name: Harshil Shah
Priority: 2
<----Inserted---->
 |Vedant Daigavane |Harshil Shah
---------Menu--------
1. Add Patient
2. Remove Patient
3. Urgent Patient Name
4. Front Priority
5. Empty
6. Display
7. Exit
-----------------------
Enter Your Choice: 1
-----------------------

<---Enter Patient Details--->
Name: Pushkar Lonekar
Priority: 3
<----Inserted---->
 |Pushkar Lonekar |Vedant Daigavane |Harshil Shah
---------Menu--------
1. Add Patient
2. Remove Patient
3. Urgent Patient Name
4. Front Priority
5. Empty
6. Display
7. Exit
-----------------------
Enter Your Choice: 1
-----------------------

<---Enter Patient Details--->
Name: Rohit James
Priority: 10
<----Inserted---->
 |Rohit James |Pushkar Lonekar |Vedant Daigavane |Harshil Shah
---------Menu--------
1. Add Patient
2. Remove Patient
3. Urgent Patient Name
4. Front Priority
5. Empty
6. Display
7. Exit
-----------------------
Enter Your Choice: 2
-----------------------
Rohit James removed
---------Menu--------
1. Add Patient
2. Remove Patient
3. Urgent Patient Name
4. Front Priority
5. Empty
6. Display
7. Exit
-----------------------
Enter Your Choice: 6
-----------------------
 |Pushkar Lonekar |Vedant Daigavane |Harshil Shah
---------Menu--------
1. Add Patient
2. Remove Patient
3. Urgent Patient Name
4. Front Priority
5. Empty
6. Display
7. Exit
-----------------------
Enter Your Choice: 3
-----------------------
Front Patient Pushkar Lonekar

---------Menu--------
1. Add Patient
2. Remove Patient
3. Urgent Patient Name
4. Front Priority
5. Empty
6. Display
7. Exit
-----------------------
Enter Your Choice: 4
-----------------------
Urgent Patient Priority: 3

---------Menu--------
1. Add Patient
2. Remove Patient
3. Urgent Patient Name
4. Front Priority
5. Empty
6. Display
7. Exit
-----------------------
Enter Your Choice: 5
-----------------------
NO

---------Menu--------
1. Add Patient
2. Remove Patient
3. Urgent Patient Name
4. Front Priority
5. Empty
6. Display
7. Exit
-----------------------
Enter Your Choice: 7
-----------------------
 *
 */
