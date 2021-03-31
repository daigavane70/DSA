//============================================================================
// Name        : DFS.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <queue>
using namespace std;

int main() {

	int adjMatrix[5][5]={
			{0,1,1,1,0},
			{1,0,1,0,0},
			{1,1,0,1,1},
			{1,0,1,0,1},
			{0,0,1,1,0}
	};

	int visited[5]={0};

	queue<int> q;

	int i=0,j;
	q.push(i+1);
	visited[i]=1;

	for(int i=1;i<5;i++)
	{
		j=q.front();
		while(j<5)
		{
			if(adjMatrix[i][j]==1 and visited[j-1]==0)
			{
				visited[j-1]=1;
				q.push(j+1);
				j++;
			}
		}

		cout<<q.front();
		q.pop();
	}

	return 0;
}
