//============================================================================
// Name        : FileHandling.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "File.h"
using namespace std;



int main() {
	File obj(0);
	int choice=0;

	while(choice<5){
		cout<<"\n1. Create DataBase"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Write"<<endl;
		cout<<"4. Add"<<endl;
		cout<<"Enter the Choice: ";
		cin>>choice;

		switch(choice){					//take new inputs and store it in the list
		case 1:{
			obj.createDataBase();
			break;
		}
		case 2:{						//display the constents of file
			obj.display();
			break;
		}
		case 3:{						//writing the data read to the file
			obj.writeData();
			break;
		}
		case 4:{
			obj.add();					//adding new Record
			break;
		}
		}

	}
}
