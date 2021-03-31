/*
 * LL.h
 *
 *  Created on: 16-Sep-2020
 *      Author: Vedant
 */

#ifndef LL_H_
#define LL_H_

struct node{
	int val;
	node* nxt;
};

class LL {
	node* head;
public:
	LL();
	node* returnHead();
	node* newNode();
	void addFront(int);
	void addLast(int);
	void del(int);
	void insert(int,int);
	void reverseDisp(node*);
	void display();
	virtual ~LL();
};

#endif /* LL_H_ */
