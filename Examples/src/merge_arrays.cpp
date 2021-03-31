void selection(int n)
{
	cout<<"\nPass\tCurrent\tSwaps\tComparisons\tList";

	int pass=0;
	int comparisons=0;
	int totalComparisons=0;
	int swap=0,totalSwaps=0;

	for(int i=0;i<n-1;i++)
	{
		pass+=1;

		int pos=i;
		for(int j=i+1;j<n;j++)
		{
			if(Student::s[pos].roll>Student::s[j].roll)
			{
				pos=j;
			}
			comparisons+=1;
		}

		if(pos!=i)
		{
			Student::s[i].roll = Student::s[i].roll + Student::s[pos].roll;
			Student::s[pos].roll = Student::s[i].roll - Student::s[pos].roll;
			Student::s[i].roll= Student::s[i].roll - Student::s[pos].roll;
			swap+=1;
		}
		comparisons+=1;

		totalComparisons+=comparisons;
		totalSwaps+=swap;

		cout<<"\n"<<pass<<'\t'<<Student::s[i].roll<<'\t'<<swap<<'\t'<<comparisons<<'\t';

		for(int i=0;i<n;i++){
			cout<<'|'<<Student::s[i].roll;
		}
	}

	cout<<"\n---------------------------------------";
	cout<<"Total Swaps: "<<totalSwaps<<"| Total Comparisons: "<<totalComparisons;
	cout<<"\n---------------------------------------";
}
