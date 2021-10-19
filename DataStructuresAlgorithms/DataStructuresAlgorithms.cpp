// DataStructuresAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <string>
#include <algorithm>
#include "MemoryCell.h"
using namespace std;

int main()
{	
	MemoryCell<int> int_cells(10), int_cells3(5);

	MemoryCell<int> int_cells1(int_cells);

	MemoryCell<int> int_cells2 = std::move(int_cells);

	int_cells1 = int_cells3;

	int_cells = std::move(int_cells1);

	MemoryCell<int> myList(10);

		myList.Display("Before creating memorycell");
		myList.Append(&myList, 1);
		myList.Append(&myList, 2);
		myList.Append(&myList, 3);
		myList.Append(&myList, 4);
		myList.Append(&myList, 5);
		//myList.Create();
		myList.Display("After creating memorycell");
		
		



	return 0;
}