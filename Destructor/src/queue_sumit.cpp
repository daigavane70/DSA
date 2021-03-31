//============================================================================
// Name        : CircularQueue.cpp
// Author      : Sumit
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

struct Student
{
	int roll_no;
    string name;
    string classes;
};

class CircularQueue
{
	private:
		int front;
		int rear;
		int itemcount;
	    struct Student s[5];

	public:
		//default constructor
		CircularQueue()
		{
			itemcount=0;
			front=-1;//assigning value of front and rear as -1
			rear=-1;
			for(int i=0;i<5;i++)
			{
				s[i].roll_no = 0;
				s[i].name = "";
				s[i].classes = "";
			}
		}
	//operation for checking queue is empty or not. Return type as boolean beacuse it return true or false
	bool isEmpty()
	{
		if(front==-1 && rear==-1)
			return true;
		else
			return false;
	}
	//operation for checking queue is full or not. Return type as boolean because it return true or false
	bool isFull()
	{
		if((rear+1)%5==front)//5==size of array
			return true;
		else
			return false;
	}

	void enqueue(string name1,int roll, string standard)
	{
		if(isFull())
		{
			cout<<"Queue is full"<<endl;
			return;
		}
		else if(isEmpty())
		{
			rear=0;
			front=0;
			s[rear].name = name1;
			s[rear].roll_no = roll;
			s[rear].classes = standard;
		}
		else
		{
			rear=(rear+1)%5;
			s[rear].name = name1;
			s[rear].roll_no = roll;
			s[rear].classes = standard;
		}
		itemcount++;
	}
	int dequeue()
	{
		int x;
		if(isEmpty())
		{
			cout<<"Queue is Empty"<<endl;
			return 0;
		}
		else if(front == rear)
		{
			cout<<"Dequeued Student"<<endl;
			cout<<"Student Name: "<<s[front].name<<endl;
			cout<<"Roll Number: "<<s[front].roll_no<<endl;
			cout<<"Standard: "<<s[front].classes<<endl;
			s[front].name ="";
			s[front].roll_no=0;
			s[front].classes = "";
			front = -1;
			rear = -1;
			return x;
		}
		else
		{
			 cout<<"Dequeued Student"<<endl;
			 cout<<"Student Name: "<<s[front].name<<endl;
			 cout<<"Roll Number: "<<s[front].roll_no<<endl;
			 cout<<"Standard: "<<s[front].classes<<endl;
			 s[front].name ="";
			 s[front].roll_no=0;
			 s[front].classes = "";
			 front++;
			 return x;
		}
	}
	//for returning how many elements inside queue
	int count()
	{
		return (itemcount);
	}
	void display()
	{
		cout<<"Students in the queue are: "<<endl;
		        cout<<"Roll No."<<"\t"<<"    Name    "<<"\t"<<" Class "<<endl;
		        for(int i=0;i<5;i++)
		        {
		        	cout<<(s[i].roll_no)<<"\t";
		        	cout<<'\t'<<(s[i].name)<<"\t"<<"  ";
		        	cout<<s[i].classes<<endl;
		        }
	}
};

int main()
{
	CircularQueue q1;
	string name;
	string standard;
	int roll_number;
	int option;
	do
	{
        cout<<"What Operation do you want to perform? Select an option number! Press 0 to exit!!"<<endl;
        cout<<"Press 1 To Enqueue a student"<<endl;//to add students
        cout<<"Press 2 To Dequeue a student"<<endl;//to delete student
        cout<<"3. isEmpty"<<endl;
        cout<<"4. isFull"<<endl;
        cout<<"5. count"<<endl;
        cout<<"6. Display the list of students in a queue:"<<endl;
        cout<<"7. Clear the screen"<<endl<<endl;

        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Enqueue Function called!!"<<endl;
            cout<<"Enter student's name: "<<endl;
            cin.ignore();//if we dont use this it skip input of string
            getline(cin,name);//it is a function to use read a string
            cout<<"Enter roll number: "<<endl;
            cin>>roll_number;
            cout<<"Enter the class of the student: "<<endl;
            cin.ignore();
            getline(cin,standard);
            q1.enqueue(name,roll_number,standard);
            break;
        case 2:
            cout<<"Dequeue function called!!"<<endl;
            q1.dequeue();
            break;
        case 3:
            if(q1.isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
            }
            else
            {
                cout<<"Queue is not empty"<<endl;
            }
            break;
        case 4:
            if(q1.isFull())
                cout<<"Queue is full"<<endl;
            else
                cout<<"Queue is not full"<<endl;
            break;
        case 5:
            cout<<"Number of students in a queue are: "<<q1.count()<<endl;
            break;
        case 6:
            q1.display();
            break;
        case 7:
            system("cls");
            break;
        case 0:
            cout<<"Thank you for using the queue application"<<endl;
            break;
        default:
            cout<<"Please enter a valid option: "<<endl;
            break;

        }


	}while(option!=0);
}
