//============================================================================
// Name        : Expression.cpp
// Author      : Bhavana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Expressioncon.h"
#include "Stackass2.h"
#include <iostream>
using namespace std;

int main()
{
    int choice;
    Expression_con exp; // object of  expressions class created

    do
    {

        cout << "-----------------------------------MENU----------------------------------------" << endl;
        cout << "1. Input" << endl;
        cout << "2. Infix to Postfix conversion" << endl;
        cout << "3. Infix to Prefix conversion " << endl;
        cout << "4. Evaluation of postfix expression" << endl;
        cout << "5. Evaluation of prefix expression " << endl;
        cout << "6. Exit " << endl;
        cout << "-------------------------------------------------------------------------------" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            exp.input();
            break;
        case 2:
            cout << "POSTFIX   ::" << exp.post_conversion() << endl; // infix to postfix
            break;
        case 3:
            cout << "PREFIX    ::" << exp.pre_conversion() << endl; // infix to prefix
            break;
        case 4:
            cout << "EVALUATION of expression for postfix  ::\n"
                 << exp.post_evaluation() << endl; // evaluated postfix expression
            break;
        case 5:
            cout << "EVALUATION expression for prefix   ::\n"
                 << exp.pre_evaluation() << endl; // evaluated for prefix expression
            break;
        case 6:
            break;
        default:
            cout << "Invalid entry" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
