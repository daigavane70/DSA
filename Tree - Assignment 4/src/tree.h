/*
 * tree.h
 *
 *  Created on: 20-Oct-2020
 *      Author: Vedant
 */

#ifndef TREE_H_
#define TREE_H_
#include<iostream>
using namespace std;

struct Tree_node
{
	char data;
	Tree_node* LNode;
	Tree_node* RNode;
};

class tree {
	Tree_node* root;
public:
	Tree_node* createTreePost(string);
	Tree_node* createTreePre(string);
	void postTraverseRecur(Tree_node*);
	void preTraverseRecur(Tree_node*);
	Tree_node* makeTree(char);
	void preTraverseNonRecur(Tree_node* temp);
	Tree_node* getRoot();
	tree();
	virtual ~tree();
};

#endif /* TREE_H_ */
