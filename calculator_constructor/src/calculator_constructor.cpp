//============================================================================
// Name        : calculator_constructor.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class calc	//declaring a calculator class
{
	float a,b;	//private variables to store two input numbers

public:
	calc(float n1,float n2)	//constructor to assign the values of 'a' and 'b'
	{
		a=n1;
		b=n2;
	}

	int add();	//method to add
	int sub();	//method to subtract
	int mult(); //method to multiply
	float div(); //method to divide
};

int calc::add(){
	return int(a+b);	//returning addition of two no.
}

int	calc::sub(){
	return int(a-b);	//returning Subtraction of two no.
}

int calc::mult(){
	return int(a*b);	//returning Multiplication of two no.
}

float calc::div(){
	return a/b;			//returning Division of two no.
}

int main()
{

	float n1,n2;	//varaibles to store two numbers
	int choice=0;	//choice of operatiion

	//reading values of a and b
	cout<<"Enter Two Numbers: \na=";
	cin>>n1;
	cout<<"b=";
	cin>>n2;

	//creating object 'obj' and passing n1 and n2 to store them in a and b
	calc obj(n1,n2);

	while(choice<5)	//loop to dirve the menu
	{
		cout<<"\n---Menu---"<<endl;
		cout<<"1. Add"<<endl;
		cout<<"2. Subtract"<<endl;
		cout<<"3. Multiply"<<endl;
		cout<<"4. Divide"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"enter your choice: ";
		cin>>choice;	//reading Users choice of operation

		if(choice==1)
		{
			cout<<endl<<n1<<"+"<<n2<<"="<<obj.add();	//calling add() and printing result

		}
		else if(choice==2)
		{
			cout<<n1<<"-"<<n2<<"="<<obj.sub();		//calling sub() and printing result
		}
		else if(choice==3)
		{
			cout<<n1<<"*"<<n2<<"="<<obj.mult();		//calling mult() and printing result
		}
		else if(choice==4)
		{
			cout<<n1<<"/"<<n2<<"="<<obj.div();		//calling div() and printing result
		}
		else
		{
			break;
		}
		cout<<endl;
	}
	return 0;
}

/*
 * Enter Two Numbers:
a=1
b=2

---Menu---
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
enter your choice: 1

1+2=3

---Menu---
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
enter your choice: 4
1/2=0.5

---Menu---
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
enter your choice: 1

1+2=3

---Menu---
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
enter your choice: 3
1*2=2

---Menu---
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
enter your choice: 5
 *
 */
