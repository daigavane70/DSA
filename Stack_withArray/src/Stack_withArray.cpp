//============================================================================
// Name        : Stack_withArray.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

/*
___            ___
 |  |\   | |\   |     /\
 |  | \  | | \  |    /__\
 |  |  \ | | /  |   /    \
_|_ |   \| |/  _|_ /      \

Author - Vedant Daigavane
*/

#include<bits/stdc++.h>
#define f(i,s,n) for(int i=s;i<=n;i++)
#define ul unsigned long long int
#define ll long long int
#define vi vector<int>
#define daigavane int main()
#define pb push_back
using namespace std;

struct bst
{
  int val;
  bst* l=NULL;
  bst* r=NULL;
};


bst* root=NULL;

void insert(int a)
{
  bst* t=new bst();
  if(root==NULL)
  {
    root=t;
    t->val=a;
  }
  else
  {
    bst* j;
    bst* k;
    j=root;
    while(j!=NULL)
    {
      k=j;
      if(j->val==a) return;
      else if(a>j->val)
      {
        j=j->r;
      }
      else
      {
        j=j->l;
      }
    }
    bst* t=new bst();
    t->val=a;
    if(k->l==j) k->l=t;
    else  k->r=t;
  }
}

bst* maxof(bst* j)
{
  j=j->l;
  while(j->r!=NULL)
  {
    j=j->r;
  }
  return j;
}

int find(int k)
{
  bst* j;
  j=root;
  while(j!=NULL)
  {
    if(k==j->val) return 1;
    else if(k>j->val) j=j->r;
    else  j=j->l;
  }

  return 0;
}

bst* del(bst* node,int a)
{
  if(find(a))
  {
  bst* j;
  j=node;

  if(j->val<a)  j->r=del(j->r,a);

  else if(j->val>a)  j->l=del(j->l,a);

  else
  {
  if(j->l==NULL and j->r==NULL)
  {
    bst* t;
    t=j;
    j=NULL;
    delete t;
  }
  else if(j->l!=NULL and j->r==NULL)
  {
    if(j==root)
    {
      root=j->l;
      delete j;
      return root;
    }
    bst* t=j;
    j=j->l;
    delete t;
  }
  else if(j->l==NULL and j->r!=NULL)
  {
    if(j==root)
    {
      root=j->r;
      delete j;
      return root;
    }
    bst* t=j;
    j=j->r;
    delete t;
  }
  else
  {
    bst* t=maxof(j);
    int b=t->val;
    del(j,b);
    j->val=b;
    delete t;
  }
    return j;
  }
  }
  else
  {
    return root;
  }
}

daigavane
{
    // BINARY SEARCH TREE
    // insert an element 'a' in bst - insert(a)
    // search an element 'a' in bst - find(a)
    // delete an element 'a' in bst - del(root,a)
}
