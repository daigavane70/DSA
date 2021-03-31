/*
 * File.cpp
 *
 *  Created on: 13-Dec-2020
 *      Author: Vedant
 */

#include "File.h"
#include<iomanip>
using namespace std;

File::File(int k) {
	// TODO Auto-generated constructor stub
	fileObj.open("file.txt",ios::out|ios::in|ios::app);
	size=k;
	list=new student[size];
}

void validName(student stud)					//name validations
{
	unsigned int index;

	while(true)
	{
		for(index=0;index<stud.name.length();index++)
		{
			if(!isalpha(stud.name[index]) and stud.name[index]!=' ')					//checking if the character in alphabet
			{
				break;
			}
		}

		if(index==stud.name.length())	return;				//all are alphabet

		else{												//some of them are not alphabet
			cout<<"Invalid Name, Enter again: ";
			cin>>stud.name;
		}
	}
}

void Roll_valid(student a[],int i,int n)
{
	//check Roll_No==Int and Roll_No>0
	while(a[i].roll!=int(a[i].roll) or a[i].roll<=0 or a[i].roll>n)
	{
		cout<<"Invalid Roll Number, Enter Again ("<<1<<"-"<<n<<"): ";
		cin>>a[i].roll;														//reading roll_no again
	}

	//checking Duplicate
	for(int j=0;j<i;j++)													//loop to traverse through the list
	{
		if(a[j].roll==a[i].roll)											//comparing
		{
			cout<<a[i].roll<<" Already Exists, Enter Again: ";
			cin>>a[i].roll;													//reading new roll Number
		}
	}
}

void File::createDataBase(){
	cout<<"Enter the Number of Students: ";
	cin>>size;
	list=new student[size];

	fileObj.open("file.txt",ios::out);

	cout<<"\n-------Enter the Details-------"<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"\nStudent "<<i+1<<endl;					//display Student Number
		cout<<"Name: ";
		while((getchar())!='\n');
		getline(cin,list[i].name);						//reading name
		validName(list[i]);								//name validation

		while(list[i].name.size()>20 or list[i].name.size()<6)
		{
			cout<<"Invalid Name, Enter Again: ";
			getline(cin,list[i].name);					//reading name
		}

		cout<<"RollNo: ";
		cin>>list[i].roll;							//reading Roll Number
		Roll_valid(list,i,size);								//validation of roll Number

		cout<<"Div: ";
		cin>>list[i].Div;

		cout<<"Address: ";							//reading the Adress from user
		getline(cin,list[i].address);
		getline(cin,list[i].address);

		fileObj.write((char*)&list[i],sizeof(list[i]));		//writing to the file
	}

	fileObj.close();
}

void File::readData(){
	fileObj.open("file.txt",ios::in);
	for(int i=0;i<size;i++)
		fileObj.read((char*)&list[i],sizeof(list[i]));
	fileObj.close();
}

void File::writeData(){
	fileObj.open("file.txt",ios::trunc);
	if(size<=0)
		cout<<"----------The DataBase has not been Created Yet----------"<<endl;
	else
		for(int i=0;i<size;i++)
			fileObj.write((char*)&list[i],sizeof(list[i]));
	fileObj.close();
}

void File::add(){
	cout<<"-------------Enter New Student Details-------------"<<endl;

	student temp;

	fileObj.open("file.txt",ios::ate);

	cout<<"Name: ";
	while((getchar())!='\n');
	getline(cin,temp.name);						//reading name
	validName(temp);								//name validation

	while(temp.name.size()>20 or temp.name.size()<6)
	{
		cout<<"Invalid Name, Enter Again: ";
		getline(cin,temp.name);					//reading name
	}

	cout<<"RollNo: ";
	cin>>temp.roll;							//reading Roll Number

	cout<<"Div: ";
	cin>>temp.Div;

	cout<<"Address: ";							//reading the Adress from user
	getline(cin,temp.address);
	while(temp.address=="\n")				//ignorring the blank line creted due to buffer
		getline(cin,temp.address);

	fileObj.write((char*)&temp,sizeof(temp));		//writing to the file

	size+=1;
	list=new student[size];
	this->readData();

	fileObj.close();
}

void File::display(){

	cout<<"\n--------------------------------------------------------------------"<<endl;
	cout<<setfill(' ')<<setw(20)<<"Name|"<<setw(8)<<"RollNo|"<<setw(5)<<"Div|"<<setw(10)<<"Addr|";
	cout<<"\n--------------------------------------------------------------------"<<endl;
	student temp;

	fileObj.open("file.txt",ios::in);

	for(int i=0;i<size;i++){
		fileObj.read((char*)&temp,sizeof(temp));
		cout<<setw(19)<<temp.name<<'|'<<setw(7)<<temp.roll<<'|'<<setw(4)<<temp.Div<<'|'<<setw(9)<<temp.address<<'|'<<endl;
	}

	cout<<"--------------------------------------------------------------------"<<endl;

	fileObj.close();
}

File::~File() {
	// TODO Auto-generated destructor stub
}
