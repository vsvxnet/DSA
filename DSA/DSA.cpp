// DSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
//#include "MemoryCell.h"
#include "MyHelper.h"

using namespace std;

int main()
{
	MyHelper helper;
	const int count = 9;
	int arr1[count] = { 5,8,2,6,3,1,7,9,4 };
	int arr2[count] = { 5,8,2,6,3,1,7,9,4 };
	int arr3[count] = { 5,8,2,6,3,1,7,9,4 };
	int arr4[count] = { 5,8,2,6,3,1,7,9,4 };

	helper.PrintArray(arr1, count);

	int sum = helper.SumArray(arr1, count);

	cout << "Sum of array is " << sum << endl;

	int largest1 = helper.GetLargest(arr1, count);
	int smallest1 = helper.GetSmallest(arr1, count);

	cout << "Smallest = " << smallest1 << " Largest = " << largest1 << endl;

	helper.ReversePrintArray(arr1, count);

	cout << "Before Reverse " << endl;
	helper.PrintArray(arr1, count);
	helper.ReverseArray(arr1, count);
	cout << "After Reverse " << endl;
	helper.PrintArray(arr1, count);

	cout << "Before Selection Sort " << endl;
	helper.PrintArray(arr1, count);
	helper.SelectionSort(arr1, count);
	helper.PrintArray(arr1, count);

	cout << "Before Bubble Sort " << endl;
	helper.PrintArray(arr2, count);
	helper.BubbleSort(arr2, count);
	helper.PrintArray(arr2, count);

	cout << "Before STL-Sort " << endl;
	helper.PrintArray(arr3, count);
	sort(arr3, arr3 + count);
	helper.PrintArray(arr3, count);

	cout << "Linear search example..  " << endl;

	int target1 = 5;
	helper.PrintArray(arr4, count);
	int idx1 = helper.LinearSearch(arr4, count, target1);
	cout << "Index of " << target1 << " is " << idx1 << endl;
	
	target1 = 7;
	idx1 = helper.LinearSearch(arr4, count, target1);
	cout << "Index of " << target1 << " is " << idx1 << endl;

	target1 = 3;
	idx1 = helper.LinearSearch(arr4, count, target1);
	cout << "Index of " << target1 << " is " << idx1 << endl;
	cout << endl;
	cout << "Binary search example..  " << endl;

	target1 = 5;
	idx1 = helper.BinarySearch(arr4, count, target1);
	cout << "Index of " << target1 << " is " << idx1 << endl;

	int arr5[7] = { 7,3,10,5,6,2,-5 };
	helper.PrintArray(arr5, 7);
	helper.MergeSort(arr5, 0, 7-1);
	helper.PrintArray(arr5, 7);


	int arr6[7] = {2, 1, 3, 4, 5, 7, -2};
	helper.PrintArray(arr6, 7);
	helper.QuickSort(arr6, 0, 7-1);
	helper.PrintArray(arr6, 7);

	// Linked-List
	cout << endl;
	cout << "Printing linked-list search example..  " << endl;

	Node n1(1); 
	Node* head = &n1;
	Node n2(2);
	Node n3(3);
	Node n4(4);
	Node n5(5);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	helper.PrintLinkedList(head);

	Node* head1 = helper.TakeLinkedListTailInput();
	helper.PrintLinkedList(head1);

	Node* head2 = helper.TakeLinkedListHeadInput();
	helper.PrintLinkedList(head2);

	Node* head3 = helper.TakeLinkedListHeadInput();
	int llength = helper.GetLinkedListLength(head3);
	cout << "Length of linked-list is " << llength << endl;
	
	Node* head4 = helper.TakeLinkedListTailInput();
	int ith;
	cout << "Enter index to print:  " << endl;
	cin >> ith;
	helper.PrintLinkedListAtIndex(head4, ith);
	
	int tdata = 99;
	int tindex = 5;
	head4 = helper.InsertLinkedListAtIndex(head4, tindex, tdata);
	helper.PrintLinkedList(head4);
	tindex = 0;
	head4 = helper.DeleteLinkedListAtIndex(head4, tindex);
	
	int rlength = helper.GetLinkedListLengthRecursive(head4);
	cout << "Recursive Length of linked-list is " << rlength << endl;
	return 0;
};