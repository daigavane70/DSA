/*
 * TBT.h
 *
 *  Created on: 05-Nov-2020
 *      Author: Vedant
 */

#ifndef TBT_H_
#define TBT_H_

struct node{
	int data;					//value at that particular node
	node* Lnode;				//Left child
	node* Rnode;				//Right child
	bool Lthread,Rthread;		//thread information
};

class TBT {
	node* root;
	node* head;

	int b=12;

public:
	TBT();
	node* getHead();
	void createRoot(int);
	void InorderRec(node*);
	node* getNode(int);				//to get a new Node
	void insert(int);				//insertion of a new Node
	void preOrderTraversal();	//traversing nodes with
	void postOrderTraversal();
	void inOrderTraversal();
	virtual ~TBT();
};

#endif /* TBT_H_ */
