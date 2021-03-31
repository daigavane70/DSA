//============================================================================
// Name        : Runtime_Duplicate.cpp
// Author      : Vedant
// Roll_no     : 23116
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int check(int a[],int b,int c)	//method to check weather the number entered is already in the list
{
	for(int i=0;i<c;i++)	//performing linear search to check the number
	{
		if(a[i]==b) return 1;	//if found return 1
	}
	return 0;	//not found
}

int main() {
	int n;										//number of elements
	cout<<"\nEnter the Number of Students: ";
	cin>>n;										//reading number of elements

	int arr[n];									//array to store the elements
	cout<<"\nStart Entering Roll Numbers"<<endl;
	for(int i=0;i<n;i++)						//loop to get all the n numbers
	{
		cout<<"Student "<<i+1<<" :";
		cin>>arr[i];							//reading the i'th element of list
		if(check(arr,arr[i],i))					//checking if the enetered number is already present in the list
		{
			//found
			cout<<"!!! "<<arr[i]<<" already Exits, Enter again !!!"<<endl;	//asking user to enter the ith number again
			i--;
		}

	}
}

/*
-----OUTPUT-----

Enter the Number of Students: 5

Start Entering Roll Numbers
Student 1 :1
Student 2 :2
Student 3 :1
!!! 1 already Exits, Enter again !!!
Student 3 :3
Student 4 :4
Student 5 :4
!!! 4 already Exits, Enter again !!!
Student 5 :5

 */
