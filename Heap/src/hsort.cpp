/*
 * hsort.cpp
 *
 *  Created on: 19-Dec-2020
 *      Author: Vedant
 */

#include "hsort.h"

hsort::hsort() {
	// TODO Auto-generated constructor stub
	size=0;										//assigning the 0 to the number of elements
}



int hsort::insertMinHeap(int n){				//function to insert in minimum Heap
	size+=1;									//incrementing the size of Array
	arr[size]=n;								//adding the new element at the last
	int comp=0,swap=0;							//local variable to store the comparisons and Swaps

	int temp=size;								//to store the index of current element

	while(temp>0){
		comp+=1;
		if(temp>1 and arr[temp]<arr[temp/2]) {

			swap+=1;							//incrementing the number of swaps performed

			int t=arr[temp];					//swapping the numbers
			arr[temp]=arr[temp/2];
			arr[temp/2]=t;
		}
		else{
			break;
		}
	}

	return comp;
}



int hsort::insertMaxHeap(int n){
	size+=1;									//incrementing the size of Array
	arr[size]=n;								//adding the new element at the last

	int comp=0,swap=0;							//local variable to store the comparisons and Swaps

	int temp=size;								//to store the index of current element

	while(temp>0){
		comp+=1;
		if(temp>1 and arr[temp]>arr[temp/2]) {

			swap+=1;							//incrementing the number of swaps performed

			int t=arr[temp];					//swapping the numbers
			arr[temp]=arr[temp/2];
			arr[temp/2]=t;
			temp=temp/2;
		}
		else{
			break;
		}
	}

	return comp;
}



void hsort::create() {
	int temp=0;
	cout<<"No of Elements: ";
	cin>>temp;									//reading the max no. of elements

	while(temp<=0 and temp>100){
		cout<<"Invalid Size! Enter Again: ";
		cin>>temp;								//getting the size input
	}

	int tempList[temp];

	cout<<"Enter Elements: "<<endl;
	for(int i=0;i<temp;i++) cin>>tempList[i];	//reading all the elements

	size=0;										//initializing the size to zero as we just used it to store the size of temp List

	cout<<"1. MinHeap"<<endl;
	cout<<"2. MaxHeap"<<endl;
	cout<<"Select: ";
	cin>>choice;								//reading the input to select the choice

	while(choice<1 and choice>2){				//if user enters an invalid choice
		cout<<"Invalid Choice! Enter Again: ";
		cin>>choice;
	}

	if(choice==1){
		cout<<"\n\n---------Creating Min-Heap Now---------"<<endl;
		cout<<"Old Heap --- Current Element --- New Heap --- Analysis"<<endl;
		for(int i=0;i<temp;i++){
			cout<<endl;

			if(size>0) for(int i=1;i<=size;i++)	cout<<arr[i]<<'|';		//printing the old heap if present
			else cout<<"Empty| ";

			cout<<"---";

			cout<<tempList[i];									//printing the current element

			int comp=this->insertMinHeap(tempList[i]);			//inserting in Min Heap	and Getting the Comparions done
			cout<<" --- ";

			for(int i=1;i<=size;i++)	cout<<arr[i]<<'|';		//printing the new heap

			cout<<"---";										//printing the number of Comaoarisons
			if(comp==size-1)	cout<<"O(n)"<<endl;
			else cout<<"log(n)"<<endl;
		}
	}

	else {
		cout<<"\n\n---------Creating Max-Heap Now---------";
		cout<<"Old Heap --- Current Element --- New Heap --- Analysis"<<endl;
		for(int i=0;i<temp;i++){
			cout<<endl;

			if(size>0) for(int i=1;i<=size;i++)	cout<<arr[i]<<'|';		//printing the old heap if present
			else cout<<"Empty| ";

			cout<<"---";

			cout<<tempList[i];									//printing the current element

			int comp=this->insertMaxHeap(tempList[i]);			//inserting in Min Heap	and Getting the Comparions done
			cout<<" --- ";

			for(int i=1;i<=size;i++)	cout<<arr[i]<<'|';		//printing the new heap

			cout<<"---";										//printing the number of Comaoarisons
			if(comp==size-1)	cout<<"O(n)"<<endl;
			else cout<<"log(n)"<<endl;
		}
	}

	cout<<"\n-------Heap Created-------\n";				//printing the final heap created
	for(int i=1;i<=size;i++)	cout<<arr[i]<<'|';
}



void hsort::insert(){
	int temp;
	cout<<"Enter the element you want to enter: ";		//getting the element we want to enter
	cin>>temp;

	int comp=0;

	if(choice==1){										///if min Heap
		comp=this->insertMinHeap(temp);
	}
	else{												//if max Heap
		comp=this->insertMaxHeap(temp);
	}

	cout<<"\nInsertion Completed| Time Complexity: ";
	if(comp<=log2(size)) cout<<"Log(n)"<<endl;
	else 	cout<<"O(n)"<<endl;

	cout<<"New Heap: ";
	for(int i=1;i<=size;i++)	cout<<arr[i]<<'|';

}



void hsort::del(){
	int temp;
	cout<<"Enter the element you want to enter: ";
	cin>>temp;

	int comp=0;

	for(int i=1;i<=size;i++){

		if(arr[i]==temp){

			cout<<"\n----Element Found----"<<endl;
			if(i<size){									//checking if the lowest element is getting deleted
				arr[i]=arr[size];						//shifting the smallest element to ith position
			}
			size--;

			temp=i;												//storing the current index
			if(choice==1){		//for minHeap
				while(temp>0){									//rearranging the heap elements
					comp++;
					if(temp>1 and arr[temp]<arr[temp/2]) {
												//swapping the element
						int t=arr[temp/2];
						arr[temp/2]=arr[temp];
						arr[temp]=t;

						temp/=2;
					}
					else{
						break;
					}
				}
			}
			else{		//for maxHeap
				while(temp>0){									//rearranging the heap elements
					comp++;
					if(temp>1 and arr[temp]>arr[temp/2]) {
												//swapping the element
						int t=arr[temp/2];
						arr[temp/2]=arr[temp];
						arr[temp]=t;

						temp/=2;
					}
					else{
						break;
					}
				}
			}

			cout<<"\nDelete Successfully| Time Complexity: ";
			if(comp<=log2(size))	cout<<"log(n)";
			else	cout<<"O(n)";
			cout<<"\nResultant Heap: ";
			for(int i=1;i<=size;i++)	cout<<arr[i]<<' ';		//printing the new Heap;

			return;
		}
	}

	cout<<"\n-------Element Not Found--------";
}

hsort::~hsort() {
	// TODO Auto-generated destructor stub
}

