//============================================================================
// Name        : Stack.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Stack.h"
#include <iostream>
#include "Conversion.h"
using namespace std;

#include<bits/stdc++.h>
#define f(i,s,n) for(int i=s;i<=n;i++)
#define ul unsigned long long int
#define ll long long int
#define vi vector<int>
#define daigavane int main()
using namespace std;

int main(){
/*
	STACK
	1. to push an element - push(int element)
	2. to get the last added element - topback()
	3. to pop the last added element - popback()
*/

	Stack<char> obj;


	int choice=0;
	while(choice<5)
	{
		Conversion obj;

		cout<<endl<<"1. Infix to PostFix"<<endl;
		cout<<"2. Infix to Prefix"<<endl;
		cout<<"3. Postfix Evaluation"<<endl;
		cout<<"4. Prefix Evaluation"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"choice: ";
		cin>>choice;
		if(choice==1)
		{
			Conversion obj2;

			string s;
			cout<<"Enter Infix Expression: " ;
			getline(cin,s);
			getline(cin,s);

			obj.Infix_to_Postfix(s);
		}
		else if(choice==2)
		{
			string s;
			cout<<"Enter Infix Expression: " ;
			getline(cin,s);
			getline(cin,s);

			obj.Infix_to_prefix(s);
		}
		else if(choice==3)
		{
			string s;
			cout<<"Enter Postfix Expression: " ;
			getline(cin,s);
			getline(cin,s);

			cout<<"Expression Value: "<<obj.postfixEvaluation(s);
		}
		else if(choice==4)
		{
			string s;
			cout<<"Enter Prefix Expression: " ;
			getline(cin,s);
			getline(cin,s);

			cout<<"Expression Value: "<<obj.prefixEvaluation(s);
		}
	}

}
