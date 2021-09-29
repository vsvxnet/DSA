// DataStructuresAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <string>
#include <algorithm>
#include "MemoryCell.h"
using namespace std;

int StrLength(char input[])
{
	int cnt = 0;
	for (int i = 0; input[i] != '\0'; i++)
	{
		cnt++;
	}
	return cnt;
}

void StrReverse(char input[])
{
	int s = 0;
	int e = StrLength(input) - 1;

	while (s < e)
	{
		swap(input[s], input[e]);
		s++;
		e--;
	}
}

void PrintAllPrefixes(char str[])
{
	for (int e = 0; str[e] != '\0'; e++)
	{
		for (int s = 0; s <= e; s++)
		{
			cout << str[s];
		}
		cout << endl;
	}
}

void PrintArray(int a[][5], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	
	MemoryCell<int> int_cells(10), int_cells3(5);

	MemoryCell<int> int_cells1(int_cells);

	MemoryCell<int> int_cells2 = std::move(int_cells);

	int_cells1 = int_cells3;

	int_cells = std::move(int_cells1);

	MemoryCell<int> myList(10);

		cout << "Displaying before creating MemoryCell: " << endl;
		myList.Display();

	myList.Create();

		cout << "Displaying after creating MemoryCell: " << endl;
		myList.Display();

		cout << "Linear search \"4\", index =" << myList.LinearSearch(4) << endl;
		if (!myList.IsSorted())
		{
			cout << "List is not sorted for binary search. Sorting.." << endl;
			myList.BubbleSort(&myList);
			myList.Display();
		}
			cout << "Binary search \"4\", index =" << myList.BinarySearch(4) << endl;
			cout << "Recursive binary search \"4\", index =" << myList.RecursiveBinarySearch(0, myList.GetLength(), 4) << endl;

		
		
		
	//myList.Append(&myList, 6);
	//myList.Display();
	//myList.Append(&myList, 7);
	//myList.Display();
	//int deleteResult = myList.Delete(&myList, 7);

//	cout << "Linear search \"4\" , index =" << myList.LinearSearch(4) << endl;
//	cout << "Binary search \"4\" , index =" << myList.BinarySearch(3) << endl;
	
	//cout << "Before selection sort: " << endl;
	//myList.Display();
	//myList.SelectionSort();
	//myList.Display();

	//cout << "Before bubble sort: " << endl;
	//myList.Display();
	//myList.BubbleSort();
	//myList.Display();
	
	//cout << "Before STL sort: " << endl;
	//myList.Display();
	//myList.STLSort();
	//myList.Display();

	//cout <<"Factorial: " << myList.Factorial(5) << endl;
	//cout <<"Fibonacci: " << myList.Fibonacci(10) << endl;
	//cout <<"Power: " << myList.Power(2,6) << endl;

	//myList.RecursivePrint(10);
	//cout << myList.DigitCount(534322121) << endl;
	//cout << myList.IsSortedHelper(&myList) << endl;
	/*
	int a[] = { 5,6,6,8,9,10,11,11 };
	int ans = 0;
	myList.CountOccurance(a, 8, 11, 0, ans);

	cout << "count of 11 is " << ans << endl;
	*/
	return 0;
}