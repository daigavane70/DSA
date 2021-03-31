/*
 * hsort.h
 *
 *  Created on: 24-Nov-2020
 *      Author: lenovo
 */

#ifndef HSORT_H_
#define HSORT_H_

class hsort
{
public:
	hsort();
	~hsort();
	void input(int arr[], int n);//for user input
	void heapify(int arr[], int n, int root);//while the array isn’t empty remove and replace the root reheap the new root node;
	void heapSort(int arr[], int n);//sorting the elements
	void buildHS(int*,int);//heap building
	void display(int arr[], int n);//for display
};

#endif /* HSORT_H_ */
