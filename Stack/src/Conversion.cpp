/*
 * Conversion.cpp
 *
 *  Created on: 01-Oct-2020
 *      Author: Vedant
 */

#include "Conversion.h"
#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include "Stack.h"
#include "Stack.cpp"

using namespace std;

void Conversion::Infix_to_Postfix(string Infix)
{
	Stack<char> stack;

	cout<<"\nPass|"<<setw(15)<<"Infix|"<<setw(10)<<"Current|"<<setw(15)<<"Stack|"<<setw(15)<<"Output|";
	cout<<endl<<"------------------------------------------------------------------------------------------------------------";

	int i=0,k=0;						//iterator to traverse through the string
	int pass=0;							//to store the number of passes

	while(Infix[i]!='\0')
	{
		pass++;

		//opening Bracket (
		if(Infix[i]=='(')
			stack.push(Infix[i]);					//pushing the opening Bracket in Stack

		//closing Bracket )
		else if(Infix[i]==')')
		{
			while(stack.peep()!='(')				//pushing all the elements of stack in the output, entered after '('
				output[k++]=stack.pop();

			stack.pop();							//popping '('
		}

		//checking for letters a-z
		else if((Infix[i]>='a' and Infix[i]<='z') || (Infix[i]>='A' and Infix[i]<='Z'))
			output[k++]=Infix[i];

		//operator +,-....
		else if(Infix[i]=='+' or Infix[i]=='-' or Infix[i]=='*' or Infix[i]=='/' or Infix[i]=='%' or Infix[i]=='^')
		{
													//checking the precedence of operator
			if(stack.isEmpty() or (associativity(Infix[i])==1 and precedence(Infix[i])==precedence(stack.peep())))
				stack.push(Infix[i]);				//pushing the operator in stack as it has higher precedence

			else if(stack.isEmpty() || stack.peep()=='(' || precedence(Infix[i])<precedence(stack.peep()))
				stack.push(Infix[i]);				//pushing the operator in stack as it has higher precedence

			else if(!stack.isEmpty())				//operator has less precedence
			{
				output[k++]=stack.pop();			//pushing higher precedence operator in output string
				stack.push(Infix[i]);				//pushing lower precedence operator in stack
			}
		}

		//passwise output
		cout<<endl<<setw(4)<<pass<<'|'<<setw(14)<<Infix<<"| "<<setw(9)<<Infix[i]<<"|  ";
		node<char>* temp=stack.getHead();					//temporary node to traverse through the stack

		while(temp!=NULL)							//printing the stack elements
		{
			cout<<temp->val;
			temp=temp->nxt;							//moving to next element
		}

		cout<<"|  ";
		for(int j=0;j<k;j++)	cout<<output[j];
		//passwise output

		i++;										//moving to next character
	}

	while(!stack.isEmpty())							//pushing the elements left in stack to output
	{
		pass++;
		output[k++]=stack.pop();

		//passwise output
		cout<<endl<<setw(4)<<pass<<'|'<<setw(14)<<Infix<<"| "<<setw(9)<<Infix[i]<<"|  ";
		node<char>* temp=stack.getHead();					//temporary node to traverse through the stack

		while(temp!=NULL)							//printing the stack elements
		{
			cout<<temp->val;
			temp=temp->nxt;							//moving to next element
		}

		cout<<"|  ";
		for(int j=0;j<k;j++)	cout<<output[j];
	}

	cout<<endl<<"------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Converted String: ";
	for(i=0;i<k;i++)	cout<<output[i];
	cout<<endl<<"------------------------------------------------------------------------------------------------------------";
}

void Conversion::Infix_to_prefix(string Infix)
{
	Stack<char> stack;

	cout<<"\nPass|"<<setw(15)<<"Infix|"<<setw(10)<<"Current|"<<setw(15)<<"Stack|"<<setw(15)<<"Output|";
	cout<<endl<<"------------------------------------------------------------------------------------------------------------";

	int i=0,k=0;						//iterator to traverse through the string
	int pass=0;							//to store the number of passes

	while(Infix[i]!='\0')	i++;
	i-=1;

	while(i>=0)
	{
		pass++;

		//closing Bracket )
		if(Infix[i]==')')
		{
			stack.push(Infix[i]);					//pushing the opening Bracket in Stack
		}

		//opeining Bracket (
		else if(Infix[i]=='(')
		{
			while(stack.peep()!=')')				//pushing all the elements of stack in the output, entered after '('
			{
				output[k++]=stack.pop();
			}
			stack.pop();							//popping ')'
		}

		//checking for letters a-z
		else if((Infix[i]>='a' and Infix[i]<='z') || (Infix[i]>='A' and Infix[i]<='Z'))
		{
			output[k++]=Infix[i];
		}

		//operator +,-....
		else if(Infix[i]=='+' or Infix[i]=='-' or Infix[i]=='*' or Infix[i]=='/' or Infix[i]=='%' or Infix[i]=='^')
		{
			if(stack.isEmpty())				//operator has less precedence
			{
				stack.push(Infix[i]);				//pushing the operator in stack as it has higher precedence
			}

			else if(Infix[i]==stack.peep())				//checking for same precedence
			{
				if(associativity(Infix[i])==1)			//checking associativity
					output[k++]=stack.pop();			//pushing higher precedence operator in output string

				stack.push(Infix[i]);				//pushing lower precedence operator in stack
			}

			else if(stack.peep()==')' or precedence(Infix[i])<precedence(stack.peep()))
				stack.push(Infix[i]);				//pushing the operator in stack as it has higher precedence

			else
			{
				output[k++]=stack.pop();			//pushing higher precedence operator in output string
				stack.push(Infix[i]);				//pushing lower precedence operator in stack
			}
		}

		//passwise output
		cout<<endl<<setw(4)<<pass<<'|'<<setw(14)<<Infix<<"| "<<setw(9)<<Infix[i]<<"|  ";
		node<char>* temp=stack.getHead();					//temporary node to traverse through the stack

		while(temp!=NULL)							//printing the stack elements
		{
			cout<<temp->val;
			temp=temp->nxt;							//moving to next element
		}

		cout<<"|  ";

		for(int j=k-1;j>=0;j--)	cout<<output[j];
		i--;										//moving to next character
	}

	while(!stack.isEmpty())							//pushing the elements left in stack to output
	{
		pass++;
		output[k++]=stack.pop();

		//passwise output
		cout<<endl<<setw(4)<<pass<<'|'<<setw(14)<<Infix<<"| "<<setw(9)<<Infix[i]<<"|  ";

		node<char>* temp=stack.getHead();					//temporary node to traverse through the stack
		while(temp!=NULL)							//printing the stack elements
		{
			cout<<temp->val;
			temp=temp->nxt;							//moving to next element
		}
		cout<<"|  ";
		for(int j=k-1;j>=0;j--)	cout<<output[j];
	}

	cout<<endl<<"------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Converted String: ";
	for(i=k-1;i>=0;i--)	cout<<output[i];
	cout<<endl<<"------------------------------------------------------------------------------------------------------------";
}

double solve(double num1,double num2,char op)
{
	switch(op)
	{
		case '+':	return num1+num2;
		case '-':	return num1-num2;
		case '*':	return num1*num2;
		case '/':	return num1/num2;
		case '^':   return pow(num1,num2);
		default : return 0;
	}
}

double Conversion::postfixEvaluation(string postfix){
	Stack<double> stack;

	double val,num1,num2;

	int index=0;

	while(postfix[index]!='\0')
	{
		if(isalpha(postfix[index]))
		{
			cout<<"\nEnter the value of "<<postfix[index]<<" : ";
			cin>>val;
			stack.push(val);
		}
		else
		{
			if(!stack.isEmpty())
			num1=stack.pop();
			num2=stack.pop();
			stack.push(solve(num2,num1,postfix[index]));
		}

		index++;
	}
	
	return stack.pop();
}

double Conversion::prefixEvaluation(string prefix){
	Stack<double> stack;

	double val,num1,num2;

	int index=0;
	index=prefix.length()-1;

	while(index>=0)
	{
		if(isalpha(prefix[index]))
		{
			cout<<"\nEnter the value of "<<prefix[index]<<" : ";
			cin>>val;
			stack.push(val);
		}
		else
		{
			if(!stack.isEmpty())
			num1=stack.pop();
			num2=stack.pop();
			stack.push(solve(num1,num2,prefix[index]));
		}

		index--;
	}
	
	return stack.pop();
}



int Conversion::associativity(char ch)
{
	if(ch=='^') return 1;
	else return 0;
}

int Conversion::precedence(char ch)
{
	if(ch=='(' or ch==')')	return 0;
	if(ch=='^') return 1;
	else if(ch=='*' or ch=='/' or ch=='%')	return 2;
	else if(ch=='+' or ch=='-')	return 3;

	return -1;
}

Conversion::~Conversion() {
	// TODO Auto-generated destructor stub
}

