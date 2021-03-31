/*
 * Stack.h
 *
 *  Created on: 23-Sep-2020
 *      Author: Vedant
 */

#ifndef STACK_H_
#define STACK_H_

template <class T>
struct node
{
	T val;
	node<T>* nxt;
};

template <class T>
class Stack{
	node<T>* head;
public:
	node<T>* getHead();
	void push(T);
	T peep();
	T pop();
	void print();
	bool isEmpty();
	Stack();
	virtual ~Stack();
};

#endif /* STACK_H_ */
