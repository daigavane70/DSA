/*
 * Conversion.h
 *
 *  Created on: 01-Oct-2020
 *      Author: Vedant
 */

#ifndef CONVERSION_H_
#define CONVERSION_H_
#include <iostream>
#include <bits/stdc++.h>
#include "Stack.h"
using namespace std;

class Conversion {
public:
	string output;
public:
	void Infix_to_Postfix(string);
	void Infix_to_prefix(string);
	double postfixEvaluation(string);
	double prefixEvaluation(string);
	int precedence(char);
	int associativity(char);
//	Conversion();
	virtual ~Conversion();
};

#endif /* CONVERSION_H_ */
