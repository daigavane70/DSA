//============================================================================
// Name        : File.cpp
// Author      : Bhavana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "file.h"

#include <iostream>
#include<fstream>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int main()
{
	int opt;
	file r;
	while(1)
	{
		cout<<"\n***MENU***\n";
		cout<<"================================================\n";
		cout<<"1. Create a new Data File"<<endl;
		cout<<"2. Add New record in the Data File"<<endl;
		cout<<"3. Display record from the data file"<<endl;
		cout<<"4. Search particular record from the data file"<<endl;
		cout<<"5. Modify particular record from the data file"<<endl;
		cout<<"6. Delete particular record from the data file"<<endl;
		cout<<"7. Exit From the Program"<<endl;
		cout<<"================================================";
		cout<<"\nEnter your option : ";
		cin>>opt;
		switch(opt)
		{
			case 1:
				r.Create();		//calling create
				 break;
			case 2:
				r.Add();		//calling add
				 break;
			case 3:
				r.Display();	//calling display
				 break;
			case 4:
				r.Search();		//calling search
				 break;
			case 5:
				r.Modify();		//calling modify
				 break;
			case 6:
				r.Delete();		//calling delete
				break;
			case 7:
				exit(0);
			default:
				cout<<"Enter a valid index please!"<<endl;
				break;
			}
	}
}
