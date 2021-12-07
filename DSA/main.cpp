#pragma once
#include <iostream>
#include "DSAHelper.h"
#include <vector>
#include <algorithm>
using namespace std;

int main()
{















	DSAHelper mHelper;

	vector<int> arr1 = { 1,4,3,5,9,7,8,2,6 };
	vector<int> arr2 = { 1,2,3,4,5};
	mHelper.PrintArray(arr1);
	mHelper.PrintArrayReverse(arr1);
	int sum1 = mHelper.SumArray(arr1);
	cout << "Sum of Array:  " << sum1 << endl;

	cout << "Is Sorted? : " << mHelper.IsArraySorted(arr1) << endl;
	cout << "Is Sorted? : " << mHelper.IsArraySorted(arr2) << endl;
	
	int largest_index = mHelper.GetLargestValueIndex(arr1);
	int smallest_index = mHelper.GetSmallestValueIndex(arr1);
	cout << "Largest element index = " << largest_index << " with value = " << arr1[largest_index] << endl;
	cout << "Smallest element index = " << smallest_index << " with value = " << arr1[smallest_index] << endl;


	cout << "Before reverse-> ";
	mHelper.PrintArray(arr1);
	mHelper.ReverseArray(arr1);
	cout << "After reverse-> ";
	mHelper.PrintArray(arr1);

	char carr1[] = "this is a string";
	int count1 = mHelper.GetLength(carr1);
	cout << "Length of string < " << carr1 << " > is: " << count1 << endl;
	mHelper.ReverseArray(carr1);
	cout << carr1 << endl;

	int target1 = 7;
	int pos1 = mHelper.LinearSearch(arr1, target1);
	cout << "(LS) Position of " << target1 << " is :" << pos1 << endl;
	pos1 = mHelper.BinarySearch(arr1, target1);
	cout << "(BS) Position of " << target1 << " is :" << pos1 << endl;
	
	cout << "Sorted? " << mHelper.RCheckSorted(arr1) << endl;
	cout << "RSumArray= " << mHelper.RSumArray(arr1) << endl;
	cout << endl;
	cout << endl;
	cout << "Linked List Section: " << endl;

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

	mHelper.PrintLinkedList(head);
	head = &n1;
	cout << "Length of list is : " << mHelper.GetLength(head) << endl;
	head = &n1;
	int ith = 3;
	cout << "Value at index = " << ith << " is = ";
	mHelper.PrintNodeValue(head, ith);

	head = &n1;

	int insert_value = 33;
	mHelper.InsertNode(head, ith, insert_value);
	
	head = &n1;
	cout << "Value at index = " << ith << " is = ";
	mHelper.PrintNodeValue(head, ith);
	head = &n1;
	mHelper.PrintLinkedList(head);







	return 0;
}