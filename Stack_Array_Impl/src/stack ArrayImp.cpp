//============================================================================
// Name        : stack_array.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h> 
  
using namespace std; 
  
class arrayAsStack {
    int top;	//top element of stack
    int size;	//size of stack
    string Stack[];	//array for implenting stack

public:
    arrayAsStack(int);				//constructor to assign the values of private variable
    void push(string x);	//pushing an element at the top
    string pop(); 			//removing the top element
    string peek(); 			//getting the top element
    bool isEmpty(); 		//checking stack empty condition
}; 
  
arrayAsStack::arrayAsStack(int length)
{
	size=length;			//assigning the length to size
	Stack=new string[size];	//creating the string array of lenght 'size'
	top=-1;					//emtpy stack condition
}

string arrayAsStack::peek()
{
    if (top < 0)					//checking if stack is empty
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
    	return Stack[top]; 			//returning the top element
    }
}

void arrayAsStack::push(string x)
{ 
    if (top >= (size - 1))			//checking if the stack is full
        cout << "Stack Is Full";
    else { 
        Stack[++top] = x; 			//increment the top and adding the new element at the new top index
    } 
} 
  
string arrayAsStack::pop()
{ 
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0; 
    } 
    else
    {
        string x = Stack[top--]; //takes the elemt in a different variable and decrements top index
        cout<<x<<"Popped Successfully"<<endl;
        return x; 
    } 
} 
  
bool arrayAsStack::isEmpty()
{ 
    return (top < 0); 
} 
  
// Driver program to test above functions 
int main() 
{ 
    class arrayAsStack s;
    string paranthesis;						//paranthesis string
    string ans;
    cout<<"Enter string"<<endl;

    cin>>paranthesis;//takes the given expression
    for(int i=0;i<paranthesis.length();i++)
    {
        if(paranthesis[i]=='(')//checks if char is (
        {
            s.push("(");
        }
        else if(paranthesis[i]==')')//pops if closing bracket is found
        {
            s.pop();
        }
        else{//the the char is not a paranthesis then add it to another string
            ans[i]=paranthesis[i];
        }
    }
    if(s.isEmpty())	//paranthesis matched successfully
    {
        cout<<"String is Correct, with proper Paranthesis"<<endl;
    }
    else{
        cout<<"Incorrect Parathesis sequence in the String"<<endl;
    }
  
    return 0; 
} 
