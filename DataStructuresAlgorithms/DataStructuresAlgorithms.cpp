// DataStructuresAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include "MemoryCell.h"
using namespace std;
int main()
{
	MemoryCell<int> int_cells(10), int_cells3(5);

	MemoryCell<int> int_cells1(int_cells);

	MemoryCell<int> int_cells2 = std::move(int_cells);

	int_cells1 = int_cells3;

	int_cells = std::move(int_cells1);

	return 0;
}