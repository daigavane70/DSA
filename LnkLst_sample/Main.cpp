/*
 * Main.cpp
 *
 *  Created on: 16-Sep-2020
 *      Author: Vedant
 */

#include<iostream>
#include"LL.h"
using namespace std;

int main()
{
	int choice=0;
	LL obj;

	while(choice<5)
	{
		cout<<"\n\n<------Menu------>"<<endl;
		cout<<"1. Insert Front"<<endl;
		cout<<"2. Insert Last"<<endl;
		cout<<"3. Insert at n'th Position"<<endl;
		cout<<"4. Delete n'th"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"---------------------"<<endl;
		cout<<"Choice: ";
		cin>>choice;

		if(choice==1)
		{
			int n;
			cout<<"Enter Number: ";
			cin>>n;
			obj.addFront(n);
		}
		else if(choice==2)
		{
			int n;
			cout<<"Enter Number: ";
			cin>>n;
			obj.addLast(n);
		}
		else if(choice==3)
		{
			int n;
			int pos;
			cout<<"Enter Number: ";
			cin>>n;
			cout<<"Enter Position: ";
			cin>>pos;
			obj.insert(pos,n);
		}
		else if(choice==4)
		{
			int pos;
			cout<<"Enter Position to Delete the element: ";
			cin>>pos;
			obj.del(pos);
		}

		cout<<endl;
		obj.display();
		cout<<endl<<endl<<"------Reverse Order------\n";
		obj.reverseDisp(obj.returnHead());
	}
}
