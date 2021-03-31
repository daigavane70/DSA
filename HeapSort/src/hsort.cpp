#include "hsort.h"
#include<iostream>
using namespace std;

hsort::hsort() {
	// TODO Auto-generated constructor stub
	size = 0;
}

hsort::~hsort() {
	// TODO Auto-generated destructor stub
}

int hsort::input(){
	do{
		cout<<"\n Enter size of Array ";
		cin>>size;
		if(size > 0){
			break;
		}else{
			cout<<"\n Wrong size, Enter again! ";
		}
	}while(1);

	cout<<"\nEnter the elements of the array : "<<endl;
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	return size;
}

void hsort::display(){
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
}

void hsort::max_heapify(int arr[], int n, int i){
	int largest = i;	//Initialize largest as root
	int l = 2*i+1;
	int r = 2*i+2;
	int comp = 0;	//variable for storing comparisions

	cout<<"\n\n*** Passwise Output ***";
	cout << "\n-------------------------------------------------------------------------------";
	cout << "\nLargest	Left	right	Comparisons	Array";
	cout << "\n-------------------------------------------------------------------------------\n";
	cout << largest <<"\t" << l << "\t" << r << "\t\t";
	// If left child is larger than root
	if(l < n and arr[l] > arr[largest]){
		largest = l;
		comp++;
	}
	// If right child is larger than largest
	if(r < n and arr[r] > arr[largest]){
		largest = r;
		comp++;
	}
	cout<<comp<<"\t";

	//If largest is not root
	if(largest!= i){
		int temp;
		temp = arr[i] ;
		arr[i] = arr[largest] ;
		arr[largest] = temp ;
		display();
		max_heapify(arr, n, largest);
	}else{
		display();
		cout<<"\nNo change ";
	}
}

void hsort::heapSort(int n){
	//build heap
	cout<<"\n\n\t\t---BUILD HEAP---";
	for(int i= (n/2)-1; i>=0;i--){
		max_heapify(arr, n, i);
	}

	//deleting
	cout << "\n\n\t\t---DELETE HEAP---";
	for(int i= n-1; i>0; i--){
		//move current root to end
		int temp;
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		cout <<"\n\n---Array Swap---";
		display();
		//calling max heapify on reduced heap
		max_heapify(arr, i, 0);
	}

	cout<<"\n\nSORTED HEAP : ";
	display();
}

void hsort::min_heapify(int arr[], int n, int i){
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int comp = 0;
	cout << "\n\n*** Passwise Output ***";
	cout << "\n-------------------------------------------------------------------------------";
	cout << "\nLargest	Left	Right	Comparisons	Array";
	cout << "\n-------------------------------------------------------------------------------\n";
	cout << smallest <<"\t" << left << "\t" << right << "\t\t";
	// If left child is larger than root
	if (left < n && arr[left] < arr[smallest]){
		smallest = left;
		comp++;
	}
	// If right child is larger than largest so far
	if (right < n && arr[right] < arr[smallest]){
		smallest = right;
		comp++;
	}
	cout<< comp<<"\t";
	//if smallest is not root
	if(smallest !=i){
		int temp;
		temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;

		display();
		min_heapify(arr, n, smallest);
	}
	else{
		display();
		cout<<"\nNo change ";
	}
}

void hsort::heapSortMin(int n){
	//build heap
	int temp;
	cout <<"\n\n\t\t---BUILD HEAP---";
	for(int i = (n/2)-1; i>=0; i--){
		min_heapify(arr, n, i);
	}
	//deleting
	cout<<"\n\n\t\t---DELETE HEAP---";
	for(int i=n-1;i>0;i--){
		//move current to root
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		cout <<"\n\n---Array Swap---";
		display();
		min_heapify(arr, i, 0);
	}
	cout<<"\n\nSORTED HEAP : ";
	display();

}
