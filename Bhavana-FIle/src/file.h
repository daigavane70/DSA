/*
 * file.h
 *
 *  Created on: 11-Dec-2020
 *      Author: lenovo
 */

#ifndef FILE_H_
#define FILE_H_

#include<fstream>
#include<iostream>

class file
{
	private:
		int roll;			//roll no of student
		char div[100];		//division of student
		char addr[100];		//address of student
		char name[100];		//name of student
		int marks;			//marks of student
	public:
		void input();		//input from the user
		void show();		//display the content on console
		int getroll()
		{
			return roll;
		}
		fstream fil;
		file fileobj;
		file modified;	// Creating Object for modified file
	    void Create();	// Create Function Declaration
		void Add();		// Add Function Declaration
		void Display();	// Display Function Declaration
		void Search();	// Search Function Declaration
		void Modify();	// Modify Function Declaration
		void Delete();	// Delete Function Declaration
};

#endif /* FILE_H_ */
