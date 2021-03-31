//============================================================================
// Name        : Complex_Numbers.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class complex
{
	//A=a+bi
	//B=c+di
	float a,c;	//Real parts of two complex numbers
	float b,d;	//Imaginary parts of two complex numbers

	//Result = x+yi
	float x,y;	//resultant after performing any operation

public:

	complex(float m,float n,float o,float p)	//constructor to assign values of the complex number
	{
		a=m;
		b=n;
		c=o;
		d=p;
	};
	void add();	//method to add
	void sub();	//method to subtract
	void mult(); //method to multiply
	void div(); //method to divide
	void display();	//method to display
};

void complex::add()
{
	//calculating the resultant real and imaginary part of addition
	x=a+c;	//real part
	y=b+d;	//imaginary part

	cout<<"Addition: "<<endl;
	printf("(%0.2f+%0.2fi) + (%0.2f+%0.2fi) = ",a,b,c,d);
}

void complex::sub()
{
	//Resultant of subtraction
	x=a-c;	//real part
	y=b-d;	//imaginary part

	cout<<"Subtraction: "<<endl;
	printf("(%0.2f+%0.2fi) - (%0.2f+%0.2fi) = ",a,b,c,d);
}

void complex::mult()
{
	//resultant of multiplication
	x=a*c-b*d;	//real part
	y=a*d+b*c;	//imaginary part

	cout<<"Multiplication: "<<endl;
	printf("(%0.2f+%0.2fi) * (%0.2f+%0.2fi) = ",a,b,c,d);
}

void complex::div()
{
	//resultant of division
	x=a*c+b*d/(c*c+d*d);	//real part
	y=b*c-a*d/(c*c+d*d);	//imaginary part

	cout<<"Division: "<<endl;
	printf("(%0.2f+%0.2fi) / (%0.2f+%0.2fi) = ",a,b,c,d);
}

void complex::display()
{
	printf("%0.2f+%0.2fi",x,y);	//printing the result
}

int main()
{

	float a,b,c,d;	//variables to store input from user

	cout<<"A=a+bi"<<endl;	//displaying the actual complex numbers
	cout<<"B=c+di"<<endl;

	//reading real and imaginary part of A and B
	cout<<"Enter the Values of:"<<endl;
	cout<<"a=";
	cin>>a;
	cout<<"b=";
	cin>>b;
	cout<<"c=";
	cin>>c;
	cout<<"d=";
	cin>>d;

	//displaying the Complex Numbers that user has entered
	cout<<"\nA="<<a<<"+"<<b<<"i"<<endl;
	cout<<"b="<<c<<"+"<<d<<"i"<<endl;

	complex obj(a,b,c,d);	//creating an object 'obj' and passing the complex number value

	int choice=0;	//variable to store the choice of operation

	while(choice<5)	// loop to run the menu driven program
	{

	cout<<"\n\n___Menu___"<<endl;
	cout<<"1. Add"<<endl;
	cout<<"2. Subtract"<<endl;
	cout<<"3. Multiply"<<endl;
	cout<<"4. Divide"<<endl;
	cout<<"5. Exit"<<endl;
	cin>>choice;

	if(choice==1)
		{
			obj.add();	//adding two complex Numbers
			obj.display();	//printing result
		}
	else if(choice==2)
		{
			obj.sub();	//Subtracting two complex numbers
			obj.display();	//printing result
		}
	else if(choice==3)
		{
			obj.mult();	//multiplying two complex numbers
			obj.display();	//printing result
		}
	else if(choice==4)
		{
			obj.div();	//dividing two complex numbers
			obj.display();	//printing result
		}
	else return 1;	//exit statement

	}

}

/*
 ---OUTPUT---


A=a+bi
B=c+di
Enter the Values of:
a=1
b=2
c=3
d=4

A=1+2i
b=3+4i


___Menu___
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
1
Addition:
(1.00+2.00i) + (3.00+4.00i) = 4.00+6.00i

___Menu___
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
2
Subtraction:
(1.00+2.00i) - (3.00+4.00i) = -2.00+-2.00i

___Menu___
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
3
Multiplication:
(1.00+2.00i) * (3.00+4.00i) = -5.00+10.00i

___Menu___
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
4
Division:
(1.00+2.00i) / (3.00+4.00i) = 3.32+5.84i

___Menu___
1. Add
2. Subtract
3. Multiply
4. Divide
5. Exit
5
 */
