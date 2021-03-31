//============================================================================
// Name        : Tree.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "tree.h"
using namespace std;

bool check(string exp) {							//validating the expression inserted
	int opr=0,oprn=0;

	for(unsigned int i=0;i<exp.length();i++){		//number of operator should be 1 less than operand
		if(exp[i]=='+' or exp[i]=='-' or exp[i]=='/' or exp[i]=='*' or exp[i]=='^' or exp[i]=='%') opr+=1;
		else if(isalpha(exp[i]))	oprn+=1;
		else
			return false;
	}

	if(opr==(oprn-1))
		return true;
	else
		return false;
}

int main() {

	int choice=0;

	tree newTree;

	Tree_node* root=new Tree_node();

	string exp;

	while(choice<6)
	{
		cout<<"\n=================================================================="<<endl;
		cout<<"1. PostFix Expression to tree."<<endl;
		cout<<"2. Prefix Expression to tree."<<endl;
		cout<<"3. Recursive Pre-order Traversal"<<endl;
		cout<<"4. Recursive Post-order Traversal"<<endl;
		cout<<"5. Non-Recursive Pre-order Traversal"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"------------------------------------------------------------------"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		cout<<"=================================================================="<<endl;

		switch(choice){
		case 1:
		{
			cout<<"Enter Post-fix Expression: ";
			getline(cin,exp);
			getline(cin,exp);

			while(!check(exp)) {								//validating exp
				cout<<"Invalid Expression, Enter again: ";
				getline(cin,exp);
			}

			root=newTree.createTreePost(exp);
			cout<<"Tree Created";
			break;
		}
		case 2:
		{
			cout<<"Enter Pre-fix Expression: ";
			getline(cin,exp);
			getline(cin,exp);

			while(!check(exp)){									//validating exp
				cout<<"Invalid Expression, Enter again: ";
				getline(cin,exp);
			}

			root=newTree.createTreePre(exp);
			cout<<"Tree Created";
			break;
		}
		case 3:
		{
			if(root!=NULL)
				newTree.preTraverseRecur(root);
			break;
		}
		case 4:
		{
			if(root!=NULL)
				newTree.postTraverseRecur(root);
			break;
		}
		case 5:
		{
			if(root!=NULL)
				newTree.preTraverseNonRecur(root);
			break;
		}
		cout<<"\n=================================================================="<<endl;
		}
	}
}

