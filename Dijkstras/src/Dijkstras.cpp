//============================================================================
// Name        : Dijkstras.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#include<queue>
using namespace std;

void dijkstras(int nodes,int** costAdjMatrix)
{
	queue<int> Q;

	int sptCost[nodes];									//array to store the shortest path of the
	for(int i=0;i<nodes;i++)	sptCost[i]=INT_MAX;		//assigning all the cost of shortest path to be Maximum

	int source;
	cout<<"Enter the Source Node ("<<1<<'-'<<nodes<<"): ";
	cin>>source;

	sptCost[source-1]=0;								//setting the cost of shortest path of Source 0
	Q.push(source-1);									//psuhing the source into the queue

	while(!Q.empty()) {
		int temp=Q.front();								//vertex to be traversed next
		Q.pop();
		for(int i=0;i<nodes;i++){

			if(costAdjMatrix[temp][i] != 0 and ((sptCost[temp] + costAdjMatrix[temp][i]) < sptCost[i])){		//relaxation of the each vertex
				sptCost[i]=(sptCost[temp] + costAdjMatrix[temp][i]);												//connected to current vertex
				Q.push(i);																						//pushing the vertex to be queue to visit next
			}
		}
	}

	cout<<"------------Shortest Path Created------------"<<endl;
	for(int i=0;i<nodes;i++)
		cout<<'\t'<<i+1<<'-'<<sptCost[i]<<endl;
	cout<<"---------------------------------------------"<<endl;
}

int main() {
	int nodes=0;												//to sotre the number of nodes
	int**  costAdjMatrix=new int*[nodes];							//cost Adjacency Matrix to store the Graph

	int choice=0;

	while(choice<4){
		cout<<"\n1. Input Graph"<<endl;
		cout<<"2. Dijkstras Shortest Path"<<endl;
		cout<<"3. Display"<<endl;
		cin>>choice;

		switch(choice){

		case 1:	{
			cout<<"Enter How Many Nodes: ";
			cin>>nodes;

			for(int i=0;i<nodes;i++)	{
				costAdjMatrix[i]=new int[nodes]{0};
				*costAdjMatrix[i]={0};
			}

			cout<<"Enter the Graph Details: "<<endl;

			for(int i=0;i<nodes;i++){									//reading the Graph nodes and the adjacent nodes to store in adjMatrix
				int adj=0;												//no of adjacent nodes to current node
				cout<<"\nNo of Adjacent Nodes to "<<i+1<<": ";
				cin>>adj;

				for(int j=0;j<adj;j++) {									//reading the adjacent nodes
					int temp;	//to store the adj node
					int cost;	//to store the cost
					cout<<"Adjacent Node "<<j+1<<": ";
					cin>>temp;

					while(temp<1 or temp>nodes or (temp-1)==i){				//validation for rneterd node
						cout<<"Invalid Node Entered, Enter Again: ";
						cin>>temp;
					}

					if(temp-1>i){
						cout<<"Cost: ";				//reading the cost
						cin>>cost;

						while(cost<1) {				//validation for cost
							cout<<"Invalid Cost Entered, Enter Again: ";
							cin>>cost;
						}

						costAdjMatrix[i][temp-1]=cost;		//assignning the cost
						costAdjMatrix[temp-1][i]=cost;
					}
				}
			}

			cout<<"-----Cost Adjacency Matrix Created-----"<<endl;
			break;
		}

		case 2:{
			if(nodes!=0)																//proceed if Graph Details Has been Entered
				dijkstras(nodes,costAdjMatrix);
			else																		//dont Proceed If the no input Provided
				cout<<"\n-----------Please Enter the Graph Details First-----------\n";
			break;
		}

		case 3:{								//printing the Cost Adjacency Matrix
			for(int i=0;i<nodes;i++){
				for(int j=0;j<nodes;j++){
					cout<<costAdjMatrix[i][j]<<' ';
				}
				cout<<endl;
			}

			break;
		}
		}
	}
}


/*
 *
1. Input Graph
2. Dijkstras Shortest Path
3. Display
1
Enter How Many Nodes: 5
Enter the Graph Details:

No of Adjacent Nodes to 1: 2
Adjacent Node 1: 2
Cost: 1
Adjacent Node 2: 4
Cost: 7

No of Adjacent Nodes to 2: 2
Adjacent Node 1: 1
Adjacent Node 2: 3
Cost: 6

No of Adjacent Nodes to 3: 3
Adjacent Node 1: 2
Adjacent Node 2: 4
Cost: 3
Adjacent Node 3: 5
Cost: 7

No of Adjacent Nodes to 4: 3
Adjacent Node 1: 1
Adjacent Node 2: 3
Adjacent Node 3: 5
Cost: 1

No of Adjacent Nodes to 5: 2
Adjacent Node 1: 3
Adjacent Node 2: 4
-----Cost Adjacency Matrix Created-----

1. Input Graph
2. Dijkstras Shortest Path
3. Display
3
17734152 1 0 7 0
1 0 6 0 0
0 6 0 3 7
7 0 3 0 1
0 0 7 1 0

1. Input Graph
2. Dijkstras Shortest Path
3. Display
2
Enter the Source Node (1-5): 2
------------Shortest Path Created------------
	1-1
	2-0
	3-6
	4-8
	5-9
---------------------------------------------

1. Input Graph
2. Dijkstras Shortest Path
3. Display
4
 *
 */
