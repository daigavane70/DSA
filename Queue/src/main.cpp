//============================================================================
// Name        : Queue.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Queue.h"
#include<bits/stdc++.h>

using namespace std;

string validName(string name)					//name validations
{
	unsigned int index;
	while(true)
	{
		for(index=0;index<name.length();index++)
		{
			if(!isalpha(name[index]) and name[index]!=' ')					//checking if the character in alphabet
			{
				break;
			}
		}

		if(index==name.length())	return name;				//all are alphabet

		else{												//some of them are not alphabet
			cout<<"Invalid Name, Enter again: ";
			getline(cin,name);
		}
	}

	return name;
}


int main()
{
	Queue obj(3);
	int choice=0;

	while(choice<6)
	{
		cout<<"\n<----Menu---->"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Remove"<<endl;
		cout<<"3. Full"<<endl;
		cout<<"4. Empty"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter Your Choice: ";
		cin>>choice;

		if(choice==1)
		{
			string name;
			Patient newPatient;
									//reading the patient name and validating
			cout<<"Name: ";
			getline(cin,name);
			getline(cin,name);
			name=validName(name);
			while(obj.duplicate(name)){		//checking for duplicate
				cout<<"name Already Present, Enter again: ";
				getline(cin,name);
			}
			newPatient.name=name;
									//getting the age and validating it
			cout<<"Age: ";
			cin>>newPatient.age;
			while(newPatient.age<=0 or newPatient.age>=102) {
				cout<<"Invalid Patient age, Enter Again: ";
				cin>>newPatient.age;
			}
									//adding the patient to the queue
			obj.addPatient(newPatient);
		}
		else if(choice==2)
			obj.removePatient();
		else if(choice==3)
			if(obj.isFull())
				cout<<endl<<"Queue is Full";
			else
				cout<<endl<<"Not Full";
		else if(choice==4)
			if(obj.isEmpty())
				cout<<endl<<"Queue is Empty";
			else
				cout<<endl<<"Not Empty";
		else
			break;

		obj.display();

	}
}
