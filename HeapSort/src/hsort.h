#ifndef HSORT_H_
#define HSORT_H_

#include<iostream>

class hsort {
	int arr[100];
	int size;
public:
	hsort();
	virtual ~hsort();
	int input();
	void display();
	void max_heapify(int arr[], int n, int i);
	void heapSort(int n);
	void min_heapify(int arr[], int n, int i);
	void heapSortMin(int n);
};

#endif /* HSORT_H_ */
