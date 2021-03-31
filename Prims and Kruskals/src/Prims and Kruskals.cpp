//============================================================================
// Name        : Prims.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void kruskals(int nodes,int** costAdjMatrix){

	bool known[nodes]={false};				//to store the visited nodes

	int visited=nodes-1;

	int cost=0;

	int currentMinimum=0;					//cost
	int prev=0;								//previous node
	int final=0;							//destination node

	for(int i=0;i<nodes;i++){				//finding the minimum edge
		for(int j=0;j<nodes;j++){
			if(costAdjMatrix[i][j]!=0 and (currentMinimum==0 or currentMinimum>costAdjMatrix[i][j])){
				currentMinimum=costAdjMatrix[i][j];
				prev=i;
				final=j;
			}
		}
	}

	int i,j;

	cost+=currentMinimum;

	cout<<endl;
	cout<<prev<<'-'<<final<<':'<<costAdjMatrix[prev][final]<<endl;						//printing the path

	visited--;							//one edge visited
	known[prev]=true;
	known[final]=true;

	while(visited>0) {					//now finding the minimum cost adj edges

		currentMinimum=0;

		for(i=0;i<nodes;i++){			//for previous

			for(j=i+1;j<nodes;j++){		//for min prev-final

				if(known[i] and known[j])			//preventing to form the cycle by not connecting known edges
					continue;

				if(costAdjMatrix[i][j]!=0 and  (currentMinimum==0 or currentMinimum>=costAdjMatrix[i][j])){
					currentMinimum=costAdjMatrix[i][j];
					prev=i;							//destination node
					final=j;						//storing the previous node
				}
			}
		}

		if(currentMinimum!=0) {
			cout<<prev+1<<'-'<<final+1<<':'<<costAdjMatrix[prev][final]<<endl;					//printing the path
			known[final]=true;																	//making the newly visited Node true
			known[prev]=true;																	//marking visited prev node
			cost+=costAdjMatrix[prev][final];													//adding the total cost
			visited--;																			//decreasing the nodes to be visited
		}
	}

	cout<<"Total Cost: "<<cost<<endl;

}


void prims(int nodes,int** costAdjMatrix){
	bool known[nodes]={false};
	int visited=nodes-1;																		//counter to count the number of nodes Visited
	int start;
	int cost=0;

	cout<<"Enter the Node to Start With "<<1<<'-'<<nodes<<": ";
	cin>>start;
	if(start<=nodes and start>=1)
		known[start-1]=true;
	else{
		cout<<"Invalid Node Input";																//getting the starting node
		return;
	}

	int i,j;

	cout<<endl;

	while(visited!=0){
		int currentMinimum=0;
		int prev=0;
		int final=0;

		for(i=0;i<nodes;i++){									//loop to check for next min edge

			if(!known[i])										//prev should be visited already
				continue;

			else{

				for(j=0;j<nodes;j++){															//looking for next min weight
					if(costAdjMatrix[i][j]!=0 and !known[j] and (currentMinimum==0 or currentMinimum>costAdjMatrix[i][j])){
						currentMinimum=costAdjMatrix[i][j];
						prev=i;
						final=j;
					}
				}
			}
		}

		if(currentMinimum!=0){
			cout<<prev+1<<'-'<<final+1<<':'<<costAdjMatrix[prev][final]<<endl;						//printing the path
			known[final]=true;																	//making the newly visited Node true
			cost+=costAdjMatrix[prev][final];													//adding the total cost
			visited--;
		}
	}

	cout<<"Total Cost "<<cost<<endl;																	//printing the total cost

}

int main() {

	int nodes=0;												//to sotre the number of nodes
	int**  costAdjMatrix=new int*[nodes];							//cost Adjacency Matrix to store the Graph

	int choice=0;

	while(choice<5){
		cout<<"\n1. Input Graph"<<endl;
		cout<<"2. Prims-Minimum Spanning Tree"<<endl;
		cout<<"3. Kruskals-Minimum Spanning Tree"<<endl;
		cout<<"4. Display"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter Choice: ";
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
					prims(nodes,costAdjMatrix);
				else																		//dont Proceed If the no input Provided
					cout<<"\n-----------Please Enter the Graph Details First-----------\n";
				break;
			}

			case 3:{
				if(nodes!=0)
					kruskals(nodes,costAdjMatrix);
				else																		//dont Proceed If the no input Provided
					cout<<"\n-----------Please Enter the Graph Details First-----------\n";
				break;
			}

			case 4:{
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

1. Input Graph
2. Prims-Minimum Spanning Tree
3. Kruskals-Minimum Spanning Tree
4. Display
5. Exit
Enter Choice: 1
Enter How Many Nodes: 5
Enter the Graph Details:

No of Adjacent Nodes to 1: 3
Adjacent Node 1: 2
Cost: 3
Adjacent Node 2: 4
Cost: 7
Adjacent Node 3: 5
Cost: 8

No of Adjacent Nodes to 2: 3
Adjacent Node 1: 1
Adjacent Node 2: 4
Cost: 4
Adjacent Node 3: 3
Cost: 1

No of Adjacent Nodes to 3: 2
Adjacent Node 1: 2
Adjacent Node 2: 4
Cost: 2

No of Adjacent Nodes to 4: 4
Adjacent Node 1: 3
Adjacent Node 2: 2
Adjacent Node 3: 1
Adjacent Node 4: 5
Cost: 3

No of Adjacent Nodes to 5: 2
Adjacent Node 1: 1
Adjacent Node 2: 4
-----Cost Adjacency Matrix Created-----

1. Input Graph
2. Prims-Minimum Spanning Tree
3. Kruskals-Minimum Spanning Tree
4. Display
5. Exit
Enter Choice: 4
8296856 3 0 7 8
3 0 1 4 0
0 1 0 2 0
7 4 2 0 3
8 0 0 3 0

1. Input Graph
2. Prims-Minimum Spanning Tree
3. Kruskals-Minimum Spanning Tree
4. Display
5. Exit
Enter Choice: 2
Enter the Node to Start With 1-5: 2

2-3:1
3-4:2
2-1:3
4-5:3
Total Cost 9

1. Input Graph
2. Prims-Minimum Spanning Tree
3. Kruskals-Minimum Spanning Tree
4. Display
5. Exit
Enter Choice: 3

1-2:1
3-4:2
4-5:3
1-2:3
Total Cost: 9

1. Input Graph
2. Prims-Minimum Spanning Tree
3. Kruskals-Minimum Spanning Tree
4. Display
5. Exit
Enter Choice: 5

 */

