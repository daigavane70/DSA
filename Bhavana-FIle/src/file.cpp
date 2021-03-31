/*
 * file.cpp
 *
 *  Created on: 11-Dec-2020
 *      Author: lenovo
 */

#include <iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;

#include "file.h"

void file::input()
{
	cout<<"Enter the name: ";			//input name
	cin.ignore();
	gets(name);
	cout<<"Enter the roll no.: ";		//input roll
	cin>>roll;
	cout<<"Enter the division: ";		//input division
	cin.ignore();
	gets(div);
	cout<<"Enter the marks out of 50: ";//input marks
	cin>>marks;
	if(marks>50){
		cout<<"Please enter marks appropriately!"<<endl;
		cout<<"Enter the marks out of 50: ";
		cin>>marks;
	 }
	cout<<"Enter the address: ";		//input address
	cin.ignore();
	gets(addr);

}

//shows the inputed values by student
void file::show()
{
	cout<<"Roll:\t\t"<<roll<<endl;
	cout<<"Name:\t\t"<<name<<endl;
	cout<<"Division:\t"<<div<<endl;
	cout<<"Marks:\t\t"<<marks<<endl;
	cout<<"Address:\t"<<addr<<endl;
}





void file:: Create() //Function to Create Data File
{
	char ch='y';
	fil.open("binary.dat",ios::out| ios::binary);
	while(ch=='y' || ch =='Y')
	{
		fileobj.input();
		fil.write((char*)&fileobj, sizeof(fileobj));
		cout<<"Want to Continue (Y/N): ";
		cin>>ch;
	}
	fil.close();
}

void file:: Add() //Function to Add New Record in Data File
{
	char ch='y';
	fil.open("binary.dat",ios::app| ios::binary);
	while(ch=='y' || ch =='Y')
	{
		fileobj.input();
		fil.write((char*)&fileobj, sizeof(fileobj));
		cout<<"Want to Continue (Y/N): ";
		cin>>ch;
	}
	fil.close();
}

void file:: Display() //Function to Display All record from the data file
{
	fil.open("binary.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{

			fileobj.show();
			cout<<endl;
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	fil.close();
}

void file:: Search() //Function to Display particular record from the data file
{
	bool flag=false;
	int rollnu;
	cout<<"Enter Roll No that should be searched:";
	cin>>rollnu;
	fil.open("binary.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
		}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
			{
				if(rollnu==fileobj.getroll()){
					flag=true;
					fileobj.show();
					break;
				}
				else
					 fil.read((char*)&fileobj, sizeof(fileobj));
			}
			if(!flag){
				cout<<"Data for this roll number is not available :(\n";
			}
	}
	fil.close();
}
void file:: Modify() //Function to Modify Particular record from the data file
	{
	int rollnu;
	cout<<"Enter Roll No. that should be modified:";
	cin>>rollnu;
	ofstream m;
	fil.open("binary.dat",ios::in| ios::out|ios::binary);
	m.open("new.dat",ios::out|ios::binary);
	if(!fil)
		{
		cout<<"File not Found";
		exit(0);
		}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(rollnu==fileobj.getroll())
			{
				cout<<"Enter New Record.."<<endl;
				modified.input();
				m.write((char*)&modified, sizeof(modified));
			}
			else
				m.write((char*)&fileobj, sizeof(fileobj));

			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	m.close();
	fil.close();
	remove("binary.dat");
	rename("new.dat", "binary.dat");
}

void file:: Delete() //Function to Delete Particular record from the data file
{
	int rollnu;
	cout<<"Enter Roll No. that to be deleted:";
	cin>>rollnu;
	ofstream o;
	o.open("new.dat",ios::out|ios::binary);
	fil.open("binary.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
		if(rollnu!=fileobj.getroll())
			o.write((char*)&fileobj, sizeof(fileobj));

			 fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	o.close();
	fil.close();
	remove("binary.dat");
	rename("new.dat", "binary.dat");
}

