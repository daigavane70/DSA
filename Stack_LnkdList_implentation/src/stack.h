/*
 * stack.h
 *
 *  Created on: 29-Sep-2020
 *      Author: Vedant
 */

#ifndef STACK_H_
#define STACK_H_

class stack {
public:
	stack();
	int peep();
	void push();
	int pop();
	bool isEmpty();
	virtual ~stack();
};

#endif /* STACK_H_ */
