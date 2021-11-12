#pragma once
#include <iostream>
#include "DSAInterview.h"
#include "DSAHelper.h"
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	DSAHelper mHelper;

	// ARRAYS
	int arr1[7] = { 1,2,3,4,4,4,5 };
	int length = (sizeof(arr1) / sizeof(arr1[0]));

	mHelper.IPrintArray(arr1, length);
	cout << "ISumArray: " << mHelper.ISumArray(arr1, length) << endl;
	pair<int, int> pair_minmax = mHelper.GetMinMaxIndex(arr1, length);

	cout << "Smallest Element Index: " << pair_minmax.first << " Value=" << arr1[pair_minmax.first] << endl;
	cout << "Largest Element Index: " << pair_minmax.second << " Value=" << arr1[pair_minmax.second] << endl;

	mHelper.IPrintArrayReverse(arr1, length);

	mHelper.IReverseArray(arr1, length);
	mHelper.IPrintArray(arr1, length);

	if (!mHelper.IIsSorted(arr1, length))
	{
		cout << "Array is not sorted.. (selection-sort in process)" << endl;
		mHelper.ISelectionSort(arr1, length);
		mHelper.IPrintArray(arr1, length);
	}
	
	mHelper.IReverseArray(arr1, length);
	if (!mHelper.IIsSorted(arr1, length))
	{
		cout << "Array is not sorted.. (bubble-sort in process)" << endl;
		mHelper.IBubbleSort(arr1, length);
		mHelper.IPrintArray(arr1, length);
	}

	int target1 = 4;
	int targetindex = mHelper.ILinearSearch(arr1, length, target1);
	cout << "Linear searching for value ( " << target1 << " ) exists at index " << targetindex << endl;

	targetindex = mHelper.IBinarySearch(arr1, length, target1);
	cout << "Binary searching for value ( " << target1 << " ) exists at index " << targetindex << endl;


	cout << endl;
	cout << endl;
	// CHAR ARRAY
	char arr2[10] = "MyCha";
	mHelper.IPrintArray(arr2);
	cout << "Length of string: " << mHelper.IGetLength(arr2) << endl;

	mHelper.IReverseArray(arr2);
	mHelper.IPrintArray(arr2);

	// VECTORS
	vector<int> v1(10,-2);
	vector<int> v2(100);

	mHelper.IPrintVector(v1);

	// RECURION
	if (!mHelper.RIsSorted(arr1, length))
	{
		cout << "Array is not sorted.. (recursive)" << endl;
	}
	else
	{
		cout << "Array is sorted.. (recursive)" << endl;

	}

	mHelper.RPrintArrayHead(arr1, length,0);
	cout << endl; 
	mHelper.RPrintArrayTail(arr1, length, 0);
	cout << endl;
	int value_bucket = mHelper.RSumArray(arr1, length);
	cout << "Recursive sum: " << value_bucket << endl;
	value_bucket = mHelper.RGetFirstIndex(arr1, length, 4, 0);
	cout << "First index: " << value_bucket<<endl;
	value_bucket = mHelper.RGetLastIndex(arr1, length, 4, 0);
	cout << "Last index: " << value_bucket<<endl;
	cout << "Counting occurance of 4: " << mHelper.RCountOccurance(arr1, length, target1, 0);

	vector<int> positions1;
	mHelper.RSaveAllPositions(arr1, length, target1, 0, positions1);
	cout << endl;
	mHelper.RPrintVector(positions1, positions1.size(), 0);
	cout << endl;
	
	cout << "IsPalindrome? " << mHelper.RCheckPalindrome(arr1, 0, length-1) << endl;

	int arr3[6] = { 1,2,3,3,2,1 };
	int length3 = (sizeof(arr3) / sizeof(arr3[0]));
	cout << "IsPalindrome? " << mHelper.RCheckPalindrome(arr3, 0, length3-1) << endl;

	cout << "Attempting character replace: ";
	char arr4[] = "TThhis iis somme strring";
	mHelper.RReplaceCharacter(arr4, 't', 'x');
	cout << arr4 << endl;

	cout << "Attempting character remove: ";
	mHelper.RRemoveCharacter(arr4, 's');
	cout << arr4 << endl;

	cout << "Attempting remove consecutive duplicates: ";
	mHelper.RRemoveConsecutiveDuplicates(arr4);
	cout << arr4 << endl;

	string str2 = "abcd";
	cout << "Printing all subsequence of string: " << endl;
	mHelper.RPrintSubsequence(str2,"");

	vector<string> vec1;
	
	mHelper.RStoreSubsequence(str2, "", vec1);
	cout << "There are " << vec1.size() << " subsequences" << endl;
	for (int i = 0; i < vec1.size(); i++)
	{
		cout << vec1[i] << " ";
	}
	cout << endl;

	cout << "Printing all permutations of " << str2 << endl;
	mHelper.RPrintPermutations(str2);

	cout << endl;
	cout << endl;


	// LinkedList
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

	mHelper.IPrintLinkedList(head);
	cout << "LinkedList length = " << mHelper.IGetLength(head) << endl;
	
	cout << "Printing LL at index 3 = ";
	mHelper.IPrintLinkedListAtIndex(head, 3);

	cout << "Inserting at index 3 ";
	mHelper.IInsertLinkedListAtIndex(head, 3, 6);
	mHelper.IInsertLinkedListAtIndex(head, 3, 7);
	mHelper.IInsertLinkedListAtIndex(head, 3, 8);
	cout << endl;
	mHelper.IPrintLinkedList(head);
	cout << "Deleting at index 3 " << endl;

	mHelper.IDeleteLinkedListAtIndex(head, 3);
	mHelper.IPrintLinkedList(head);
	cout << endl;
	cout << "LinkedList length (recursive) = " << mHelper.RGetLength(head) << endl;
	cout << "Reversing linkedlist " << endl;
	mHelper.IPrintLinkedList(head);
	head = mHelper.IReverseLinkedList(head);
	mHelper.IPrintLinkedList(head);

	head = mHelper.IRemoveLinkedListNodeAtIndex(head, 3);
	mHelper.IPrintLinkedList(head);

	




	return 0;
}