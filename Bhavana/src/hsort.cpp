/*
 * hsort.cpp
 *
 *  Created on: 24-Nov-2020
 *      Author: lenovo
 */

#include "hsort.h"
#include <iostream>
using namespace std;

hsort::hsort()
{

}

void hsort::input(int arr[], int n)
{
	for(int i=0; i<n; i++)
	{ //take user input
		cout<<"Enter element number "<<i+1<<" ";
		cin>>arr[i];
	}//for end
}

static int comp=0;

void hsort::heapify(int arr[], int n, int root)
{
		int largest = root;// Initialize largest as root
		int l = 2*root + 1;
		int r = 2*root + 2;

		if (l < n && arr[l] > arr[largest])
			largest = l;//if left child is larger than root

		if (r < n && arr[r] > arr[largest])// If right child is larger than largest so far
			largest = r;

	   if (largest != root)// If largest is not root
	      {
		  int x = arr[root];
		  arr[root] = arr[largest];
		  arr[largest] = x;// Recursively heapify the affected

	      heapify(arr, n, largest);
	     }

	   comp+=1;
}

void hsort::heapSort(int arr[], int n)
{// Build heap (rearrange array)
	comp=0;					//making the number of comparisions zero
	 for (int i = n / 2 - 1; i >= 0; i--)
	   heapify(arr, n, i);

	 for (int i=n-1; i>=0; i--)// One by one extract an element from heap
	   {
		 int y = arr[0];// Move current root to end
		 arr[0] = arr[i];
		 arr[i] = y;

	      heapify(arr, i, 0);// call max heapify on the reduced heap
	   }

	 cout<<"\nComparisons Done: "<<comp<<endl;
}

void hsort::buildHS(int* arr,int n) {

	comp=0;

	// Build heap (rearrange array)
	cout<<"Heap building in progress!"<<endl;
	for(int i=n/2-1;i>=0;i--)
		heapify(arr, n, i);

	 cout<<"\nComparisons Done: "<<comp<<endl;
	display(arr, n);
}//after sorting display

void hsort::display(int arr[], int n)
{//display sorted elements

	for(int i =0;i<n;i++)
	{
		cout<<arr[i]<<" ";//display array of elements
	}//for end

}

hsort::~hsort()
{

}
//end
