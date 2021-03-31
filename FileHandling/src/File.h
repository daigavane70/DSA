/*
 * File.h
 *
 *  Created on: 13-Dec-2020
 *      Author: Vedant
 */

#ifndef FILE_H_
#define FILE_H_

#include<iostream>
#include<fstream>
using namespace std;

struct student
{
	string name;
	int roll;
	string Div;
	string address;
};

class File {
	int size;
	student* list;
	fstream fileObj;

public:
	File(int);
	void search();
	void createDataBase();
	void readData();
	void writeData();
	void add();
	void display();
	virtual ~File();
};

#endif /* FILE_H_ */
