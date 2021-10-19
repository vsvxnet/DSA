// AlgoExpert.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int target)
{
    if (low > high) return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return binarySearch(arr, mid + 1, high, target);
    }
    else return binarySearch(arr, low, mid - 1, target);
}

int binarySearch(int arr[], int length, int target) 
{
  //  int length = *(&arr + 1) - arr;
    if (arr == nullptr || length == 0)
        return -1;
    return binarySearch(arr, 0, length - 1, target);
}


int main()
{
    
    int a[] = { 1,3,5,7,9 };

    cout << binarySearch(a,5, 9) << endl;
}