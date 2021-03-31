//============================================================================
// Name        : HeapSort.cpp
// Author      : Vedant
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================




#include <iostream>
using namespace std;
#include "hsort.h"

int main() {

	hsort object;
	int size;
	int choice;
	bool flag = true;
	while(flag == true){
		cout<<"\n1. Insert\n2. Display\n3. Max Heap\n4. Min Heap\n5. Exit"<<endl;
		cin>>choice;
		switch(choice){
		case 1:
		{
			size = object.input();
			break;
		}
		case 2:
		{
			object.display();
			break;
		}
		case 3:
		{
			object.heapSort(size);
			break;
		}
		case 4:{
			object.heapSortMin(size);
			break;
		}
		case 5:
		{
			flag = false;
			break;
		}
	}
	}
	return 0;
}


/*
1. Insert
2. Display
3. Max Heap
4. Min Heap
5. Exit
1

 Enter size of Array 5

Enter the elements of the array :
15
20
10
5
25

1. Insert
2. Display
3. Max Heap
4. Min Heap
5. Exit
2
15 20 10 5 25
1. Insert
2. Display
3. Max Heap
4. Min Heap
5. Exit
3


		---BUILD HEAP---

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	right	Comparisons	Array
-------------------------------------------------------------------------------
1	3	4		1	15 25 10 5 20

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	right	Comparisons	Array
-------------------------------------------------------------------------------
4	9	10		0	15 25 10 5 20
No change

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	right	Comparisons	Array
-------------------------------------------------------------------------------
0	1	2		1	25 15 10 5 20

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	right	Comparisons	Array
-------------------------------------------------------------------------------
1	3	4		1	25 20 10 5 15

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	right	Comparisons	Array
-------------------------------------------------------------------------------
4	9	10		0	25 20 10 5 15
No change

		---DELETE HEAP---

---Array Swap---15 20 10 5 25

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	right	Comparisons	Array
-------------------------------------------------------------------------------
0	1	2		1	20 15 10 5 25

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	right	Comparisons	Array
-------------------------------------------------------------------------------
1	3	4		0	20 15 10 5 25
No change

---Array Swap---5 15 10 20 25

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	right	Comparisons	Array
-------------------------------------------------------------------------------
0	1	2		1	15 5 10 20 25

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	right	Comparisons	Array
-------------------------------------------------------------------------------
1	3	4		0	15 5 10 20 25
No change

---Array Swap---10 5 15 20 25

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	right	Comparisons	Array
-------------------------------------------------------------------------------
0	1	2		0	10 5 15 20 25
No change

---Array Swap---5 10 15 20 25

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	right	Comparisons	Array
-------------------------------------------------------------------------------
0	1	2		0	5 10 15 20 25
No change

SORTED HEAP : 5 10 15 20 25
1. Insert
2. Display
3. Max Heap
4. Min Heap
5. Exit
4


		---BUILD HEAP---

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	Right	Comparisons	Array
-------------------------------------------------------------------------------
1	3	4		0	5 10 15 20 25
No change

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	Right	Comparisons	Array
-------------------------------------------------------------------------------
0	1	2		0	5 10 15 20 25
No change

		---DELETE HEAP---

---Array Swap---25 10 15 20 5

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	Right	Comparisons	Array
-------------------------------------------------------------------------------
0	1	2		1	10 25 15 20 5

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	Right	Comparisons	Array
-------------------------------------------------------------------------------
1	3	4		1	10 20 15 25 5

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	Right	Comparisons	Array
-------------------------------------------------------------------------------
3	7	8		0	10 20 15 25 5
No change

---Array Swap---25 20 15 10 5

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	Right	Comparisons	Array
-------------------------------------------------------------------------------
0	1	2		2	15 20 25 10 5

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	Right	Comparisons	Array
-------------------------------------------------------------------------------
2	5	6		0	15 20 25 10 5
No change

---Array Swap---25 20 15 10 5

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	Right	Comparisons	Array
-------------------------------------------------------------------------------
0	1	2		1	20 25 15 10 5

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	Right	Comparisons	Array
-------------------------------------------------------------------------------
1	3	4		0	20 25 15 10 5
No change

---Array Swap---25 20 15 10 5

*** Passwise Output ***
-------------------------------------------------------------------------------
Largest	Left	Right	Comparisons	Array
-------------------------------------------------------------------------------
0	1	2		0	25 20 15 10 5
No change

SORTED HEAP : 25 20 15 10 5
1. Insert
2. Display
3. Max Heap
4. Min Heap
5. Exit
5

*/