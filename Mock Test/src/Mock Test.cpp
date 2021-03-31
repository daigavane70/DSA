//============================================================================
// Name        : Mock.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

struct account{
	int accNo;					//store the account number
	string name;				//name of account holder
	string acountType;			//Savings or Current
	double Balance;				//amount of Money
};

class Bank{
	int accounts;				//number of clients
	account* customer;			//customer arrays

public:
	Bank(int);					//to intialize the array of account holder
	void getDetails();
	void display();
	void nameValidation(account);
	void selSort();				//based on account number
	void insSort();				//based on the name
	void binSearch(string);			//name based search
};

Bank::Bank(int size){
	accounts=size;
	customer=new account[size];
}

void Bank::nameValidation(account temp){
	unsigned int index;
	while(true)
	{
		for(index=0;index<temp.name.length();index++)
		{
			if(!isalpha(temp.name[index]))					//checking if the character in alphabet
			{
				break;
			}
		}

		if(index==temp.name.length())	return;				//all are alphabet

		else{												//some of them are not alphabet
			cout<<"Invalid Name, Enter again: ";
			cin>>temp.name;
		}
	}
}

void Bank::getDetails(){

	cout<<"\n------Enter Details of Customers------"<<endl;
	for(int i=0;i<accounts;i++){
		cout<<"Customer: "<<i+1<<endl;

		cout<<"Name: ";
		getline(cin,customer[i].name);
		getline(cin,customer[i].name);
		nameValidation(customer[i]);								//name validation

		cout<<"Account Number: ";
		cin>>customer[i].accNo;
		while(customer[i].accNo>accounts and customer[i].accNo<0){	//account Number Validation
			cout<<"Invalid Account Number,Enter Again ";
			cin>>customer[i].accNo;
		}
		bool flag=true;
		while(flag)
		{
			for(int j=0;j<i;j++){
				if(customer[i].accNo==customer[j].accNo){
					cout<<"Account Number Already Exist,Enter Again ";
					cin>>customer[i].accNo;
				}
				if(j==i){
					flag=false;
					break;
				}
			}
		}

		cout<<"Savings/Current: ";
		getline(cin,customer[i].acountType);
		getline(cin,customer[i].acountType);

		cout<<"Balance: ";
		cin>>customer[i].Balance;
	}
}

void Bank::display(){
	cout<<"\n-------------------------------------";
	cout<<"\n"<<setw(20)<<"Name"<<setw(20)<<"Account Number"<<setw(8)<<"Type"<<setw(8)<<"Balance";
	for(int i=0;i<accounts;i++){
		cout<<endl<<setw(20)<<customer[i].name<<setw(20)<<customer[i].accNo<<setw(8)<<customer[i].acountType<<setw(8)<<customer[i].Balance;
	}
	cout<<"\n-------------------------------------";
}

void Bank::selSort(){
	int pass=0;
	int comparisons;
	int totalComparisons=0;
	int swap;
	int totalSwaps=0;

	cout<<endl<<"Pass\tCurrent\tComparisons\tSwaps\tList";

	for(int i=0;i<accounts-1;i++) {			//loop for each pass
		pass+=1;
		comparisons=0;
		swap=0;
		for(int j=i+1;j<accounts;j++) {		//loop for comparison

			if(customer[i].accNo>customer[j].accNo){
				account temp;				//swapping
				temp=customer[i];
				customer[i]=customer[j];
				customer[j]=temp;
				swap+=1;
			}
			comparisons+=1;
		}

		totalComparisons+=comparisons;
		totalSwaps+=swap;

		cout<<endl<<pass<<'\t'<<customer[i].accNo<<'\t'<<comparisons<<'\t'<<swap<<'\t';
		for(int i=0;i<accounts;i++){
			cout<<"|"<<customer[i].accNo;
		}
	}

	cout<<"\n-------------------------------------"<<endl;
	cout<<"|total Comparisons: "<<totalComparisons<<"|Total Swaps: "<<totalSwaps<<endl;
}

void Bank::insSort()
{
	int pass=0,comparisons=0,swap=0;
	int tot_swaps=0,tot_comparisons=0;

	for(int i=1;i<accounts;i++)								//loop for PASS
	{
		pass++;
		comparisons=0;
		swap=0;
		for(int j=0;j<i;j++)							//loop for Comparison
		{
			if(customer[j].name>customer[i].name)				//Comparing Name
			{
				account l=customer[i];						//storing the initial value

				for(int k=i;k>j;k--)					//loop to shifting the elements
				{
					customer[k]=customer[k-1];
				}

				customer[j]=l;								//setting the value to correct position
				swap++;
			}
			comparisons++;
		}

		//printing passwise output
		if(pass==1)
		{
			cout<<"\n----------------------------------------------------------------";
			cout<<"\n\t|Pass\t\t|Comparisons\t|Swaps\t\t|List";
			cout<<"\n----------------------------------------------------------------";
		}
		//printing values if parameters
		cout<<"\n\t|"<<pass<<"\t\t|"<<comparisons<<"\t\t|"<<swap<<"\t\t";

		for(int j=0;j<=i;j++)
		{
			cout<<customer[j].name<<"|";
		}
		tot_comparisons+=comparisons;
		tot_swaps+=swap;
	}
	cout<<"\n----------------------------------------------------------------"<<endl;

	//Analysis Part
	cout<<"\t|TOTAL SWAPS: "<<tot_swaps<<"\t|TOTAL COMPARISONS: "<<tot_comparisons;
	cout<<"\n----------------------------------------------------------------"<<endl;
}

void Bank::binSearch(string name){
	int start=0;	//starting index
	int end=accounts-1;	//last index
	int mid;		//mid index

	int pass=0,comparison=0;		//total comparison and total pass

	int found=-1;

	while(start<=end)				//continue traversing till the section to be searched has size greater than 1
	{
		pass++;

		comparison++;

		mid=(start+end)/2;								//setting the mid index

		if(pass==1)										//checking for first Pass
		{
			cout<<"\n--------------------------------------------------------------------------------------------------"<<setfill(' ');
			cout<<"\n|Pass\t|Comparisons\t|Start\t|End\t|Mid"<<setw(20)<<"KeyElement|"<<setw(20)<<"MidElement|"<<"\t|List";
			cout<<"\n--------------------------------------------------------------------------------------------------";
		}
																	//printing the values of parameters
		cout<<"\n|"<<pass<<"\t|"<<comparison<<"\t\t|"<<start<<"\t|"<<end<<"\t|"<<mid<<setw(21)<<name<<'|'<<setw(19)<<customer[mid].name<<"|\t";

		for(int i=start;i<=end;i++)		cout<<customer[i].name<<"|";	//printing the list of names

		if(customer[mid].name==name)
		{
			found=mid;	//checking for mid value
			break;
		}

		else if(customer[mid].name>name)	end=mid-1;			//less than mid value

		else if(customer[mid].name<name)		start=mid+1;	//greater than mid value
	}

	if(pass)	cout<<"\n--------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\t PASSES: "<<pass<<" | COMPARISONS: "<<comparison;
	cout<<"\n--------------------------------------------------------------------------------------------------"<<endl;

	if(found+1){
		cout<<"\nName found"<<endl;
		cout<<"----------------------"<<endl;
		cout<<"Name|\tAccount Number|\tType|\tBalance|"<<endl;
		cout<<customer[found].name<<"|  "<<customer[found].accNo<<"|  "<<customer[found].acountType<<"|  "<<customer[found].Balance<<endl;
		cout<<"----------------------"<<endl;
	}
	else
		cout<<"\nNot Found"<<endl;

}

int main() {

	Bank Account(0);										//created object with zero account Holders
	int choice=0;											//to get the users choice
	int size=0;												//to store the number of customers

	while(choice<=5)										//looop for the menu
	{
		cout<<"\n------------------------"<<endl;
		cout<<"1. Enter Details"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Selection Sort(Account Number)"<<endl;
		cout<<"4. Insertion Sort(Name)"<<endl;
		cout<<"5. Binary Search(Name)"<<endl;
		cout<<"Enter Choice: ";
		cin>>choice;										//reading the choice

	switch(choice){											//switch case to perform the particular operation enetered by user
	case 1:{
		cout<<"Enter the Number of Customers: ";
		cin>>size;
		Bank newList(size);
		Account=newList;
		Account.getDetails();
		break;
	}
	case 2:
	{
		if(size!=0){
			Account.display();
		}
		else
			cout<<endl<<"No Data to Display";
		break;
	}
	case 3:{
		if(size!=0){
			Account.selSort();
		}
		else
			cout<<endl<<"No data to work On";
		break;
	}
	case 4:{
		if(size!=0) {
			Account.insSort();
		}
		else
			cout<<"No data to work On";
		break;
	}
	case 5:{
		if(size!=0) {
			string name;
			cout<<"\nEnter the Name you want to search: ";
			getline(cin,name);
			getline(cin,name);
			Account.binSearch(name);
		}
	}
	}
	}

return 0;
}
