/*
 * bst.h
 *
 *  Created on: 27-Oct-2020
 *      Author: Vedant
 */

#ifndef BST_H_
#define BST_H_

struct node{
	int data;
	node* Lnode;
	node* Rnode;
};
class BST {
	node* root;
public:
	BST();
	node* getRoot();
	node* createNode(int);
	void insert(int);
	node* search(node*,int);
	void postTraverseRecur(node*);
	void LeafNodes(node*);
	node* maxOf(node*);
	node* deleteNode(node*,int);
	node* mirrorTree(node* temp);
	virtual ~BST();
};

#endif /* BST_H_ */
