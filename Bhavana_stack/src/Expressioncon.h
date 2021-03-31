#ifndef EXPRESSIONCON_H_
#define EXPRESSIONCON_H_
#include <iostream>
#include <cstring>
#include <cmath>
#include "Stackass2.cpp"

using namespace std;
class Expression_con
{
    string infix, postfix, prefix_result;

public:
    int precedence(char);
    int associativity(char);
    double evaluation(int, int, char);
    string pre_conversion();
    double pre_evaluation();
    double post_evaluation();
    string post_conversion();
    string input();
    void display(char, string, char);
    void post(int);
    Expression_con() // default constructor
    {
    }
};

#endif /* EXPRESSIONCON_H_ */
