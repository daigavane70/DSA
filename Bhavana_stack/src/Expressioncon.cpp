/*
 * Expressioncon.cpp
 *
 *  Created on: 25-Oct-2020
 *      Author: lenovo
 */

#include "Expressioncon.h"
#include <cctype>
int Expression_con::precedence(char c)
{ // function to check the precedence of the operators
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/') // * and / of same precedence
        return 2;
    else if (c == '+' || c == '-') // + and - of same precedence
        return 1;
    else
        return -1;
}
int Expression_con::associativity(char c)
{ // Method to check the associativity
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
    {
        return 1; //  for left to right
    }
    else if (c == '^')
    {
        return 2; // for right to left
    }
    else
    {
        return -1;
    }
}
string Expression_con::input()
{ // Method to take the input of  infix expression
    cout << "Enter an infix expression" << endl;
    cin >> infix;
    return "";
}

string Expression_con::post_conversion()
{ // method for conversion from infix to postfix
    int index = 0;
    postfix = "";
    Stack_ass2<char> stack; // stack object of stack created

    cout<<"\n--------------------------------";
    cout<<"\nInfix\t\tCurrent\t\tPostFix\t\tStack";
    cout<<"\n--------------------------------";

    while (infix[index] != '\0')
    {                          // run the loop until infix character is not null
        if (isalpha(infix[index])) // if expression contain any numeric  or any alphabet value
        {
            postfix += infix[index]; // alphanumeric value stored in postfix string
        }
        else if (infix[index] == '(') // if bracket found in the expression
        {
            stack.push(infix[index]); // push the open paranthesis in the stack
        }
        else if (infix[index] == ')')
        { // if close paranthesis found in the stack
            while (stack.peep() != '(')
            { // pop the elements from the stack unless (  not found
                postfix += stack.pop();
            }
            stack.pop(); // pop (
        }
        else
        {
            // if stack is empty or precedence of  top is less than the current operator in the expression
            if (stack.isEmpty() || (associativity(infix[index])==2 and precedence(stack.peep())==precedence(infix[index])))
            {
                stack.push(infix[index]); // push the operator in the stack
            }

			else if(stack.isEmpty() || stack.peep()=='(' || precedence(infix[index])<precedence(stack.peep()))
				stack.push(infix[index]);				//pushing the operator in stack as it has higher precedence

			else if(!stack.isEmpty()){
				postfix+=stack.pop();
				stack.push(infix[index]);
			}
        }

        cout<<endl<<infix<<'\t'<<infix[index]<<'\t'<<postfix<<"\t";			//passwise output
        Node<char>* temp=new Node<char>();
        temp=stack.getTop();
        while(temp!=NULL){
        	cout<<temp->data;
        	temp=temp->next;
        }


        index++;                                   // next element from the expression
    }
    if (!stack.isEmpty())
    { // if stack is not empty
        while (!stack.isEmpty())
        {
            postfix += stack.pop(); // pop all the elements from the postfix string

            cout<<endl<<infix<<'\t'<<infix[index]<<'\t'<<postfix<<"\t";			//passwise output
            Node<char>* temp=new Node<char>();
            temp=stack.getTop();
            while(temp!=NULL){
            	cout<<temp->data;
            	temp=temp->next;
            }
        }
        postfix += '\0';

    }

    cout<<"\n---------------------------------"<<endl;

    return postfix; // return postfix string
}
double Expression_con::post_evaluation()
{ // evaluation for postfix expression
    //int i=0;
    double value; // value of the input character in the expression for evaluation
    int n1, n2;
    Stack_ass2<double> ev; // ev object of the stack created
    string exp;       // input expression
    cin.ignore(1);
    cout << "Enter Post fix expression::" << endl;
    getline(cin, exp);

    unsigned int i=0;

    for (i = 0; i < exp.length(); i++)
    {
        if (isalpha(exp[i]))
        { // isalpha checks if there is any alphabet arguement
            cout << "Value for the variable : " << exp[i] << "::" << endl;
            cin >> value;
            ev.push(value); // push the value in the stack
        }
        else
        { // if no characters in the stack
            // pop the already present values from the stack to evaluate the result
            n2 = ev.pop();
            n1 = ev.pop();
            value = evaluation(n1, n2, exp[i]); // evaluation function called to store the value of the result
            ev.push(value);                     // push the value for futhur evaluation
        }
    }

    return ev.pop(); // pop the final value
}

string Expression_con::pre_conversion()
{                               // conversion from infix to prefix
    int index = infix.length() - 1; // starting from the second last char of the string

    string prefix = "";
    prefix_result = "";
    Stack_ass2<char> stack;

    cout<<"\n--------------------------------";
    cout<<"\nInfix\t\tCurrent\t\tPostFix\t\tStack";
    cout<<"\n--------------------------------";


    while (infix[index] != '\0')
    { // until last char is null char
        //smbl=s[i];
        if (isalnum(infix[index])) // check for alphanumeric value
        {
            prefix += infix[index]; // store infix characters in prefix string
        }

        else if (infix[index] == '(')
        { // if ( is found
            while (stack.peep() != ')')
            { // pop elements unless ) found
                prefix += stack.pop();
            }
            stack.pop();
        }
        else if (infix[index] == ')') // if ) character found
        {
            stack.push(infix[index]); // push ) in the stack
        }
        else
        { // operator in the expression
            if (stack.isEmpty() || precedence(stack.peep()) < precedence(infix[index]))
            {                      // precedence of top is less than current operator
                stack.push(infix[index]); // push the current char in the stack
            }
            else
            {
                if (precedence(stack.peep()) > precedence(infix[index])) // if prec of top is greater than the current op
                {
                    while (precedence(stack.peep()) >= precedence(infix[index]))
                    { // pop unless char of lower prec found
                        prefix += stack.pop();
                    }
                    stack.push(infix[index]); // push the current op in the stack
                }
                else if (precedence(infix[index]) == precedence(stack.peep()))
                { // if precedences are equal
                    if (associativity(infix[index]) == 1)
                    { // left to right

                        stack.push(infix[index]); // push the current op
                    }
                    if (associativity(infix[index]) == 2)
                    {                       // right to left
                        prefix += stack.pop(); // pop ^ first
                        stack.push(infix[index]);  // push the current op
                    }
                }
            }
        }

        cout<<endl<<infix<<'\t'<<infix[index]<<'\t'<<prefix<<"\t";			//passwise output
        Node<char>* temp=new Node<char>();
        temp=stack.getTop();
        while(temp!=NULL){
        	cout<<temp->data;
        	temp=temp->next;
        }

        index--; // traversing backwards in the infix expression
    }
    if (!stack.isEmpty())
    { // if stack not empty
        while (!stack.isEmpty())
        {
            prefix += stack.pop(); // pop elements unless null char found

            cout<<endl<<infix<<'\t'<<infix[index]<<'\t'<<postfix<<"\t";			//passwise output
            Node<char>* temp=new Node<char>();
            temp=stack.getTop();
            while(temp!=NULL){
            	cout<<temp->data;
            	temp=temp->next;
            }
        }
        prefix += '\0';
    }
    for (int j = prefix.length() - 1; j >= 0; j--)
    { // to reverse the prefix string
        prefix_result += prefix[j];
    }

    cout<<"\n---------------------------------"<<endl;

    return prefix_result;
}

double Expression_con::pre_evaluation()
{ // evaluation for prefix expression

    double value; // value of the input character in the expression for evaluation
    int n1, n2;
    Stack_ass2<double> ev; // ev object of the stack created
    string exp;
    cout << "Enter Pre fix expression::" << endl;
    cin >> exp;               // input expression
    int i = exp.length() - 1; // i starting from the second last character of the expression
    while (exp[i] != '\0')
    {
        if (isalpha(exp[i]))
        { // isalpha checks if there is any alphabet arguement
            cout << "Value for the variable : " << exp[i] << "::" << endl;
            cin >> value;
            ev.push(value); // push the value in the stack
        }
        else
        { // if no characters in the stack
            // pop the already present values from the stack to evaluate the result
            n2 = ev.pop();
            n1 = ev.pop();
            value = evaluation(n1, n2, exp[i]); // evaluation function called to store the value of the result
            ev.push(value);                     // push the value for futhur evaluation
        }
        i--;
    }

    return ev.pop(); // pop the final value
}

double Expression_con::evaluation(int n1, int n2, char op)
{               // evaluation function
    switch (op) // switch case
    {
    case '+':
        return (n1 + n2);
    case '-':
        return (n1 - n2);
    case '*':
        return (n1 * n2);
    case '/':
        return (n1 / n2);
    case '%':
        return (remainder(n1, n2)); // returns the remainder
    case '^':
        return (pow(n1, n2));
    }
    return 0;
}

void Expression_con::display(char c, string ans, char input)
{ // display function
    cout << "--------------------------DISPLAY---------------------------------" << endl;
    cout << "Input expression :: " << input << endl;
    cout << "Expression        :: " << ans << endl;
    cout << "Character at the top :: " << c << endl;
    cout << "-------------------------------------------------------------------" << endl;
}
