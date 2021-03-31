//============================================================================
// Name        : Student Data
// Author      : Vedant Daigavane
// Roll No.    : 23116
// Subject	   : DSA
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

struct student		//defining a struct 'student' to store data
{
	string name;	//name
	int roll_no;	//roll no
	int marks[5];	//int array to store data of 5 marks
	float total;	//total marks
	float SGPA;
};

class stud_class								//declaring a class data to store students info and data and methods to work with it
{
	int size;			//number of students
	student *list;	//array to store the list of students
public:

	stud_class();		//constructor

	stud_class(int p)		//constructor taking no. of students as parameter
	{
		size=p;							//Initializing the Number of Students
		list=new student[size];			//creating  a student array of size n
	}
	void input();						//method to take input of the student detail
	void display();						//method to display the list of students
	void bubble();						//bubble sort
	void linear_search();				//method to search any particular roll_no in list
	void validName(student);				//function to do Name validation
	void Roll_valid(student[],int,int);	//roll Number Validation
	void binary_search(string);			//binary search by name
	void ins_sort();					//insertion sort
	int part(int,int,int*,int*);					//quick sort partitioning
	void qsort(int,int);				//quick sort
	void display_top_5();				//display top 5 Students high SGPA
};

//Input From File

void stud_class::input()				//input using File
{
	ifstream reader("file.txt");				//initializing the input source as file.txt

	for(int i=0;i<size;i++)						//loop to take the input of all the students
	{
		if(i>0)									//skipping the '\n'
			getline(reader,list[i].name);

		getline(reader,list[i].name);			//reading name

		reader>>list[i].roll_no;				//reading roll_no

		list[i].total=0;						//setting total marks to zero

		for(int j=0;j<5;j++)					//reading 5 inputs
		{
			reader>>list[i].marks[j];			//reading marks
			list[i].total+=list[i].marks[j];	//adding to total marks
		}

		list[i].SGPA=list[i].total/250;			//calculating SGPA
	}
}


//manual Input
void stud_class::input()
{
	for(int i=0;i<size;i++)
	{
		cout<<"\nStudent "<<i+1<<endl;					//display Student Number
		int s=0;										//sum of marks
		cout<<"Name: ";
		while((getchar())!='\n');
		getline(cin,list[i].name);						//reading name
		validName(list[i]);								//name validation

		while(list[i].name.size()>20 or list[i].name.size()<6)
		{
			cout<<"Invalid Name, Enter Again: ";
			getline(cin,list[i].name);					//reading name
		}

		cout<<"RollNo: ";
		cin>>list[i].roll_no;							//reading Roll Number
		Roll_valid(list,i,size);								//validation of roll Number
		cout<<"Marks of 5 Subjects(Between 0-50)\n";
		for(int j=0;j<5;j++)							//reading roll numbers and getting marks
		{
			cout<<"Subject "<<j+1<<":";
			cin>>list[i].marks[j];						//reading marks

			while(list[i].marks[j]<0 or list[i].marks[j]>50)
			{
				cout<<"Invalid Marks(0-50), Enter Again: ";
				cin>>list[i].marks[j];					//reading marks
			}

			s+=list[i].marks[j];						//calculating total marks
		}
		list[i].total=(float)s;							//assigning the value of total
		list[i].SGPA=((float)s)/250.0;					//calculating SGPA
	}
}

void stud_class::validName(student stud)					//name validations
{
	unsigned int index;
	while(true)
	{
		for(index=0;index<stud.name.length();index++)
		{
			if(!isalpha(stud.name[index]) and stud.name[index]!=' ')					//checking if the character in alphabet
			{
				break;
			}
		}

		if(index==stud.name.length())	return;				//all are alphabet

		else{												//some of them are not alphabet
			cout<<"Invalid Name, Enter again: ";
			cin>>stud.name;
		}
	}
}

void stud_class::Roll_valid(student a[],int i,int n)
{
	//check Roll_No==Int and Roll_No>0
	while(a[i].roll_no!=int(a[i].roll_no) or a[i].roll_no<=0 or a[i].roll_no>n)
	{
		cout<<"Invalid Roll Number, Enter Again ("<<1<<"-"<<n<<"): ";
		cin>>a[i].roll_no;														//reading roll_no again
	}

	//checking Duplicate
	for(int j=0;j<i;j++)														//loop to traverse through the list
	{
		if(a[j].roll_no==a[i].roll_no)											//comparing
		{
			cout<<a[i].roll_no<<" Already Exists, Enter Again: ";
			cin>>a[i].roll_no;													//reading new roll Number
		}
	}
}

void stud_class::linear_search()
{
	int status;										//to store the result of comparison
	float s;										//SGPA to search
	cout<<"\nEnter the SGPA of student to search: ";
	cin>>s;											//SGPA Name

	cout<<setfill('-')<<setw(60);
	cout<<"\n"<<setfill(' ')<<setw(6)<<"Index|"<<setw(5)<<"Key|"<<setw(8)<<"RollNo|"<<setw(20)<<"Name|"<<setw(7)<<"SGPA|"<<setw(8)<<"Status|"<<endl;
	cout<<setfill('-')<<setw(60);

	for(int i=0;i<size;i++)							//loop to compare all the SGPA's with KEY
	{
		status=0;
		if(list[i].SGPA==s)							//comparing
			status=1;								//setting status to 1 if the key is matched

		cout<<"\n"<<setfill(' ')<<setw(5)<<i<<'|';
		cout<<setw(4)<<s<<'|';
		cout<<setw(7)<<list[i].roll_no<<'|';
		cout<<setw(19)<<list[i].name<<'|';
		cout<<setw(6)<<list[i].SGPA<<'|';
		cout<<setw(7)<<status<<'|';
		if(status)	cout<<"Found";
	}

	cout<<"\n"<<setfill('-')<<setw(60);
}

void stud_class::bubble()
{
	int pass=0, swap, comparison=0;
	int tot_swap=0, tot_comparison=0;

	for(int i=0;i<size-1;i++)					// Loop For each pass
	{
		swap=0;								//number of swaps
		comparison=0;

		for(int j=0;j<size-i-1;j++)			// Loop for checking the adjacent roll_numbers
		{
			if(list[j].roll_no>list[j+1].roll_no)	//swapping "In case of descending just replace '>' by '<'"
			{
				student t;
				t=list[j];
				list[j]=list[j+1];
				list[j+1]=t;
				swap++;						//incrementing Swap
			}
			comparison++;
		}

		pass++;								//incrementing pass
											//Pass wise output
		if(pass==1)
		{
		cout<<"\n----------------------------------------------------------------";
		cout<<"\n|Pass\t\t|Comparisons\t|Swaps\t\t|List";
		cout<<"\n----------------------------------------------------------------";
		}

		cout<<"\n|"<<pass<<"\t\t|"<<comparison<<"\t\t|"<<swap<<"\t\t";

		for(int i=0;i<size;i++)				//printing the list of roll Number
		{
			cout<<"|"<<list[i].roll_no;
		}

		tot_swap+=swap;						//adding to total Swaps
		tot_comparison+=comparison;			//adding to total Comparison

		if(swap==0)	break;					//Breaking If no Swaps
		}

	cout<<"\n----------------------------------------------------------------"<<endl;

	cout<<"Data Sorted"<<endl;
	this->display();


											//Analysis Part
	cout<<"\nTOTAL SWAPS: "<<tot_swap<<"\t| TOTAL COMPARISONS: "<<tot_comparison;
											//checking the Complexity
	if(tot_comparison<=size)
		cout<<"\n\t<<<<<<<<BEST CASE>>>>>>>>";
	else if(tot_comparison>size and tot_comparison<(size*size))
		cout<<"\n\t<<<<<<<<AVERAGE CASE>>>>>>>>";
	else
		cout<<"\n\t<<<<<<<<WORST CASE>>>>>>>>";

	cout<<"\n----------------------------------------------------------------"<<endl;
}

void stud_class::display()
{
	cout<<"-----------------------------------------------";
	cout<<setfill(' ')<<"\n"<<setw(8)<<"RollNo|"<<setw(20)<<"Name|"<<setw(8)<<"Total|"<<setw(8)<<"SGPA|"<<endl;
	cout<<"-----------------------------------------------";
	for(int i=0;i<size;i++)							//for traversal through the list
	{
		cout<<"\n"<<setw(7)<<list[i].roll_no<<'|';	//roll no
		cout<<setw(19)<<list[i].name<<'|';			//display name
		cout<<setw(7)<<list[i].total<<'|';			//total marks
		cout<<setw(7)<<list[i].SGPA<<'|';			//percentage
	}
	cout<<' '<<setfill('-')<<setw(77);
	cout<<endl;
}

void stud_class::display_top_5()
{
	cout<<"-----------------------------------------------";
		cout<<setfill(' ')<<"\n"<<setw(8)<<"RollNo|"<<setw(20)<<"Name|"<<setw(8)<<"Total|"<<setw(8)<<"SGPA|"<<endl;
		cout<<"-----------------------------------------------";
		for(int i=size-1;i>=size-5;i--)						//for traversal through the 5 students in List
		{
			cout<<"\n"<<setw(7)<<list[i].roll_no<<'|';	//roll no
			cout<<setw(19)<<list[i].name<<'|';			//display name
			cout<<setw(7)<<list[i].total<<'|';			//total marks
			cout<<setw(7)<<list[i].SGPA<<'|';			//percentage
		}
		cout<<' '<<setfill('-')<<setw(77);
		cout<<endl;
}

void stud_class::binary_search(string s)
{
	int start=0;	//starting index
	int end=size-1;	//last index
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
		cout<<"\n|"<<pass<<"\t|"<<comparison<<"\t\t|"<<start<<"\t|"<<end<<"\t|"<<mid<<setw(21)<<s<<'|'<<setw(19)<<list[mid].name<<"|\t";

		for(int i=start;i<=end;i++)		cout<<list[i].name<<"|";	//printing the list of names

		if(list[mid].name==s)
		{
			found=mid;	//checking for mid value
			break;
		}

		else if(list[mid].name>s)	end=mid-1;			//less than mid value

		else if(list[mid].name<s)		start=mid+1;	//greater than mid value
	}

	if(pass)	cout<<"\n--------------------------------------------------------------------------------------------------"<<endl;

														//Printing the Analysis Part
	cout<<"\t PASSES: "<<pass<<" | COMPARISONS: "<<comparison;
	if(comparison==1)
		cout<<"\n\t<<<<<<<<BEST CASE>>>>>>>>>";
	else if(comparison>=log2(size))
		cout<<"\n\t<<<<<<<<WORST CASE>>>>>>>>>";
	else
		cout<<"\n\t<<<<<<<<AVG CASE>>>>>>>>>";
	cout<<"\n--------------------------------------------------------------------------------------------------"<<endl;

	if(found+1)									//Student Found and then we are printing its details
	{
		cout<<"\nFound";
		cout<<"\n---------------------------------------------------------------";
		cout<<"\n\t|RollNo\t\t|Name\t\t|Total\t\t|SGPA"<<endl;
		cout<<"---------------------------------------------------------------";
		cout<<"\n\t|"<<list[found].roll_no;		//roll no
		cout<<"\t\t|"<<list[found].name;		//display name
		cout<<"\t\t|"<<list[found].total;		//total marks
		cout<<"\t\t|"<<list[found].SGPA;		//percentage
		cout<<"\n---------------------------------------------------------------";
		cout<<endl;
	}
	else cout<<"\nNot Found";
}

void stud_class::ins_sort()
{
	int pass=0,comparisons=0,swap=0;
	int tot_swaps=0,tot_comparisons=0;

	for(int i=1;i<size;i++)								//loop for PASS
	{
		pass++;
		comparisons=0;
		swap=0;
		for(int j=0;j<i;j++)							//loop for Comparison
		{
			if(list[j].name>list[i].name)				//Comparing Name
			{
				student l=list[i];						//storing the initial value

				for(int k=i;k>j;k--)					//loop to shifting the elements
				{
					list[k]=list[k-1];
				}

				list[j]=l;								//setting the value to correct position
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
			cout<<list[j].name<<"|";
		}
		tot_comparisons+=comparisons;
		tot_swaps+=swap;
	}
	cout<<"\n----------------------------------------------------------------"<<endl;

	//Analysis Part
	cout<<"\t|TOTAL SWAPS: "<<tot_swaps<<"\t|TOTAL COMPARISONS: "<<tot_comparisons;

	if(tot_comparisons==(size*(size-1))/2 and tot_swaps==0)	cout<<"\n\t<<<<<<<<<BEST CASE>>>>>>>>>";
	else if(tot_comparisons==(size*(size-1))/2)	cout<<"\n\t<<<<<<<<<WORST CASE>>>>>>>>>";
	else cout<<"\n\t<<<<<<<<<AVERAGE CASE>>>>>>>>>";

	cout<<"\n----------------------------------------------------------------"<<endl;
}

int stud_class::part(int pivot,int n,int* tot_comp,int* pass)
{
	int i=pivot+1;			//setting the Starting Index
	int j=n;				//ending Index

	int comp=2;												//comparsions

	do
	{
		while(list[i].SGPA<=list[pivot].SGPA)
		{
			i++;			//looking for greater element than pivot element
			comp++;
		}
		while(list[j].SGPA>list[pivot].SGPA)
		{
			comp++;
			j--;			//looking for smaller element than pivot element
		}

		if(i<j)
		{
			student t;
			t=list[i];										//swapping the smaller element with larger element
			list[i]=list[j];
			list[j]=t;
		}

	}while(i<j);

	*tot_comp+=comp;	//Incrementing Total Comparisons
	*pass+=1;			//incrementing Passes

	cout<<"\n\nPass: "<<*pass<<"| Comparisons: "<<comp;

	student t;
	t=list[pivot];													//putting the pivot element at its correct position
	list[pivot]=list[j];
	list[j]=t;

	return j;														//returning the correct position of pivot element
}

void stud_class::qsort(int start,int end)
{
	static int tot_comp=0;							//total comparisons and passes
	static int pass=0;								//to store the number of passes

	if(start<end)
	{
		int j=part(start,end,&tot_comp,&pass);

		cout<<"\nPartition 1: ";
		for(int i=0;i<j;i++)	cout<<list[i].roll_no<<"|";
		cout<<"\nPartition 2: ";
		for(int i=j;i<size;i++)	cout<<list[i].roll_no<<"|";

		qsort(start,j-1);			//Smaller part
		qsort(j+1,end);			//Greater part
	}

	if(start>=end)
	{
		cout<<"\n|	Total Comparisons: "<<tot_comp;
		if(tot_comp==int(size*log(size)))
		{
			cout<<"|	Best Case";
		}
		else if(tot_comp==size*size)
		{
			cout<<"|	Worst Case";
		}
		else	cout<<"|	average Case";
	}
}

int main()
{
	int n=0;																//number of student

	stud_class obj(0);															//declaring class object and calling constructor to initialize the Student array

	int choice=1,sort=0;													//variable to store the choice of operation

	while(choice<8)
	{
	cout<<"\n------------Menu------------"<<endl;							 //display Menu
	cout<<"1. Input Data"<<endl;
	cout<<"2. Display"<<endl;
	cout<<"3. Bubble Sort(Roll No)"<<endl;
	cout<<"4. Linear Search(SGPA)"<<endl;
	cout<<"5. Insertion Sort(Name)"<<endl;
	cout<<"6. Binary Search(Name)"<<endl;
	cout<<"7. Top 5 Rank Holders (Quick Sort)"<<endl;
	cout<<"8. Exit"<<endl;
	cout<<"------------------------------"<<endl;
	cin>>choice;															//reading the users choice

	switch(choice)
	{
		case 1:
		{
			cout<<"Enter The Number Students (Between 1 to 15): ";
			cin>>n;															//reading total Students
			stud_class new_obj(n);
			obj=new_obj;
			while(n<0 or n>15 or n!=int(n))									//validating the value of n
			{
				cout<<"\nInvalid Input";
				cout<<"\nEnter The Number Students (Between 1 to 10): ";
				cin>>n;														//reading total Students
			}

			stud_class obj1(n);

			obj=obj1;

			obj.input();													//reading data
			break;
		}
		case 2:
		{
			if(n>0)		obj.display();										//display data
			else	cout<<"<--List is Empty-->";
			break;
		}
		case 3:
		{
			sort=1;
			if(n>0)		obj.bubble();										//bubble sort (Roll Number)
			else	cout<<"<--List is Empty-->";
			break;
		}
		case 4:
		{
			if(n>0)		obj.linear_search();								//linear search (SGPA)
			else 	cout<<"<--List is Empty-->";
			break;
		}
		case 5:
		{
			sort=2;		//setting that insertion has been performed
			if(n>0)		obj.ins_sort();										//Insertion Sort (Name)
			else		cout<<"<--List is Empty-->";
			break;
		}
		case 6:
		{
			if(n>0)
			{
			if(sort==2)														//checking if the list is sorted according to the 'Name'
			{
				string s;
				cout<<"Name to Search: ";
				while((getchar())!='\n');
				getline(cin,s);
				obj.binary_search(s);										//Binary Search (Name)
			}
			else	cout<<"List not sorted according to the 'Name'"<<endl;	//list not sorted according to the name
			}

			else	cout<<"<--List is Empty-->";
			break;
		}
		case 7:
		{
			if(n>0)
			{
				obj.qsort(0,n-1);
				cout<<"\n<-----Top 5 Rank Holders----->"<<endl;
				obj.display_top_5();
			}
			else	cout<<"<--List is Empty-->";
			break;
		}
	}
	}
}
