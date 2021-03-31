//============================================================================
// Name        : Heap_sort.cpp
// Author      : Bhavana
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "hsort.h"
//main
int main()
{
	hsort heap;								//object creation of the class
    int c,n;
    cout<<"Enter the size of the array: ";//take user input
	cin>>n;
	int a[n];
    while(true){//menu drive
		cout<<"\n------------------------MENU------------------------";
		cout<<"\n1) Insert element\n2) Build Heap\n3) Sorting using heap sort\n4) Exit"<<endl;
		cout<<"------------------------------------------------------\n";
		cin>>c;
		if(c==4){
			break;
		}
		switch(c){
		case 1:
			cout<<"Enter "<<n<<" elements of the array"<<endl;//input
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			break;
		case 2:
			heap.buildHS(a,n);//build the heap
			break;
		case 3:
			heap.heapSort(a,n);
			cout<<"Sorted array is: "<<endl;//sorting of elements
			heap.display(a,n);
			break;
		case 4:cout<<"Program finished!";//finished
		break;
		default:
			cout<<"Enter a valid index!"<<endl;
			break;
		}

    }
}
//Program finished!
