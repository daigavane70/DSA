//============================================================================
// Name        : Student Data
// Author      : Vedant Daigavane
// Roll No.    : 23116
// Subject	   : DSA
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
#include <iostream>
#include<string.h>
using namespace std;

struct student	//defining a struct 'student' to store data
{
	string name;
	int roll_no;
	int marks[5]; //int array to store data of 5 marks
	float total;
	float percentage;
};

class data
{
	student a[5];
public:
	void input();
	void sort();
	void search();
	void display();
};

void data::input()
{
	for(int i=0;i<5;i++)
	{
		int sum=0;
		cout<<"\nEnter Details of student "<<i+1;
		cout<<"\nName: ";
		cin>>data::a[i].name;
		cout<<"Roll Number: ";
		cin>>data::a[i].roll_no;
		cout<<"Marks of five subject(Max=50): ";

		for(int j=0;j<5;j++)
			{
				cin>>data::a[i].marks[j];
				sum+=float(data::a[i].marks[i]);
			}

		data::a[i].total=sum;
		data::a[i].percentage=sum/250.0;
	}
}

void data::sort()
{
	for(int i=0;i<4;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			double m=data::a[i].percentage;
			double n=data::a[j].percentage;

			data::a[j].percentage=max(m,n);
			data::a[i].percentage=min(m,n);
		}
	}

	cout<<"\nSorted the list of student according to their Percentage";
}

void data::search()
{
	int k;
	cout<<"\nEnter the name of student to search: ";
	cin>>k;
	for(int i=0;i<5;i++)
	{
		if(data::a[i].roll_no==k)
		{
			cout<<"\nFound ";
			cout<<data::a[i].name;
			return;
		}
	}
	cout<<"\nNotFound";
}

void data::display()
{
	cout<<"\nName\t\tRollNumber\t\tTotal\t\tPercentage";
	for(int i=0;i<5;i++)
	{
		cout<<"\n"<<data::a[i].name;
		cout<<"\t\t"<<data::a[i].roll_no;
		cout<<"\t"<<data::a[i].total;
		cout<<"\t\t"<<data::a[i].percentage;
	}
}

int main()
{
	int choice=1;

	while(choice<=4)
	{

	data obj;	//declaring class object

	cout<<"\n------Menu------"<<endl;
	cout<<"1. Input Data"<<endl;
	cout<<"2. Sort"<<endl;
	cout<<"3. Search"<<endl;
	cout<<"4. Display"<<endl;
	cout<<"5. Exit"<<endl;
	cin>>choice;

	if(choice==1)
	{
		obj.input();
	}
	else if(choice==2)
	{
		obj.sort();
	}
	else if(choice==3)
	{
		obj.search();
	}
	else if(choice==4)
	{
		obj.display();
	}
	else	return 0;
	}
}
