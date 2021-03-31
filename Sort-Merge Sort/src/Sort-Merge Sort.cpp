//============================================================================
// Name        : Sort-Merge.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//--------Iterative Merge Sort of Two Arrays--------------
void imrg_sort_double(int list1[],int list2[],int result[],int size1,int size2)
{
	int i=0;		//list1 iterator
	int j=0;		//list2 iterator
	int t=0;		//resultant list iterator

	while(i<size1 and j<size2)		//loop to add one smaller element at a time, either from list1 or list2, while both of them have at least 1 element
	{
		if(list1[i]<list2[j])		//if current element of list1 is smaller than current element of list2
		{
			result[t]=list1[i];		//inserting the i'th element of list1 in result
			i++;					//incrementing the iterator of list 1, i.e i
		}

		else						//element of list2 at j'th position is smaller than the i'th element of list1
		{
			result[t]=list2[j];		//inserting the j'th element of list2 in result[]
			j++;					//incrementing interator
		}

		t++;						//after insertion incrementing the result[]'s counter
	}

	while(i<size1)					//adding the remaining element of list1 to result[]
	{
		result[t]=list1[i];
		i++;
		t++;
	}

	while(j<size2)					//adding the remaining element of list2 to result[]
	{
		result[t]=list2[j];
		j++;
		t++;
	}
}

//-------------Iterative Merge Sort of a Single Array----------------
void imrg_sort(int array[],int low,int mid,int high)
{
	int i=low;		//to traverse sorted part
	int j=mid+1;	//to traverse unsorted part
	int t=0;

	int* result_array=new int[high-low+1];

	while(i<=mid and j<=high)
	{
		if(array[i]<array[j])
		{
			result_array[t]=array[i];
			i++;
		}
		else
		{
			result_array[t]=array[j];
			j++;
		}
		t++;
	}
	while(i<=mid)
	{
		result_array[t]=array[i];
		i++;
		t++;
	}
	while(j<=high)
	{
		result_array[t]=array[j];
		j++;
		t++;
	}

	for(int k=low;k<=high;k++)	array[k]=result_array[k];

	delete result_array;
}
int main() {

	int list1[5]={3,5,6,9,1};		//sorted list 1
	int list2[6]={5,7,9,10,16,77};	//sorted list 2
	int final_list[5+6];			//resultant sorted list after merging the list1[] and list2[]

	imrg_sort(list1,0,2,4);

	for(int i=0;i<5;i++)	cout<<list1[i]<<" ";	//printing the sorted list

	return 0;
}
