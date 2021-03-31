/*
 * hsort.h
 *
 *  Created on: 19-Dec-2020
 *      Author: Vedant
 */

#ifndef HSORT_H_
#define HSORT_H_

#include<iostream>
#include<math.h>
using namespace std;

class hsort {
	int size;
	int arr[100];
public:
	int choice=0;				//to store wether the user has selected the Max Heap(2) or Min Heap(1);
	hsort();
	void del();					//delete any element from the node
	int insertMinHeap(int n);	//perform insertion in minHeap
	int insertMaxHeap(int n);  //perform insertion in maxHeap
	void insert();				//perform insertion in the Heap;
	void create();				//take input of numbers and creat heap
	virtual ~hsort();
};

#endif /* HSORT_H_ */
