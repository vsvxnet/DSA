#pragma once
#ifndef MemoryCell_H
#define MemoryCell_H
#include <iostream>
#include <algorithm>
using namespace std;

template <class T> class MemoryCell
{
private:
	T* A;
	int size;
	int length;
public:
	explicit MemoryCell(int initial_size) :size{ initial_size }
	{
		cout << "Constructor: MemoryCell of size " << this->size << endl;
		A = new T[this->size];
	}

	~MemoryCell()
	{
		cout << "Destructor: MemoryCell of size " << this->size << endl;
		delete[] A;
	}

	MemoryCell(const MemoryCell& rhs)
	{
		A = new T{ *rhs.A };
		size = rhs.size;
		length = rhs.length;
		cout << "CopyConstructor: MemoryCell of size " << this->size << endl;
	}

	MemoryCell(MemoryCell&& rhs) : A{ rhs.A }, size{ rhs.size }, length{ rhs.length }
	{
		rhs.A = nullptr;
		cout << "MoveConstructor: MemoryCell of size " << this->size << endl;
	}

	MemoryCell& operator=(const MemoryCell& rhs)
	{
		cout << "CopyAssignment: " << endl;
		if (this != &rhs)
		{
			*A = *rhs.A;
			size = rhs.size;
			length = rhs.length;
		}
		return *this;
	}

	MemoryCell& operator=(MemoryCell&& rhs)
	{
		cout << "MoveAssignment: " << endl;
		std::swap(A, rhs.A);
		std::swap(size, rhs.size);
		std::swap(length, rhs.length);
		return *this;
	}

	void Display(string displayMsg)
	{
		cout << "Display(" << displayMsg << ") MemoryCell: ";
		for (int i = 0; i < length; i++)
		{
			cout << A[i] << " ";
		}
		cout << endl;
	}

	void Append(MemoryCell* m, int x)
	{
		if (m->length < m->size)
		{
			m->A[m->length++] = x;
		}
	}
	int gcd(int a, int b)
	{
		if (b == 0)
		{
			return a;
		}
		else
		{
			return gcd(b, a % b);
		}
	}

	void ReverseArray(int start, int end)
	{
		while (start < end)
		{
			int tmp = A[start];
			A[start] = A[end];
			A[end] = tmp;
			start++;
			end--;
		}
	}


	void LeftRotateByOne()
	{
		int tmp = A[0], i;
		for (i = 0; i < length - 1; i++)
		{
			A[i] = A[i + 1];
		}
		A[length - 1] = tmp;
	}
	void LeftRotateBy(int rotations)
	{
		for (int i = 0; i < rotations; i++)
		{
			LeftRotateByOne();
		}
	}
	void JuggleRotate(int rotations)
	{
		rotations = rotations % length;
		int g_c_d = gcd(rotations, length);
		cout << "Juggle GCD: " << g_c_d << endl;

		for (int i = 0; i < g_c_d; i++)
		{
			int temp = A[i];
			int j = i;

			while (1)
			{
				int k = j + rotations;
				if (k >= length)
				{
					k = k - length;
				}
				if (k == i)
				{
					break;
				}
				A[j] = A[k];
				j = k;
			}
			A[j] = temp;
		}
	}

	void ReversalRotate(int rotations)
	{
		if (rotations == 0)
			return;
		rotations = rotations % length;

		ReverseArray(0, rotations - 1);
		ReverseArray(rotations, length - 1);
		ReverseArray(0, length - 1);
	}

	void Rotate(int rotations)
	{
		int i = 0, j = length - 1;
		while (i != j)
		{
			swap(A[i], A[j]);
			i++;
		}
	}
	int findPivot(int low, int high)
	{
		if (high < low)
		{
			return -1;
		}
		if (high == low)
		{
			return low;
		}

		int mid = (low + high) / 2;
		if (mid < high && A[mid] > A[mid + 1])
		{
			return mid;
		}

		if (mid > low && A[mid] < A[mid - 1])
		{
			return(mid - 1);
		}

		if (A[low] >= A[mid])
		{
			return findPivot(low, mid - 1);
		}
		return findPivot(mid + 1, high);
	}

	int BinarySearch(int low, int high, int key)
	{
		if (high < low)
		{
			return -1;
		}

		int mid =(low + high) / 2;
		if (key == A[mid])
		{
			return mid;
		}

		if (key > A[mid])
		{
			return BinarySearch(mid + 1, high, key);
		}

		return BinarySearch(low, mid - 1, key);
	}
	int PivotedBinarySearch(int length, int key)
	{
		int pivot = findPivot(0, length - 1);
		if (pivot == -1)
		{
			return BinarySearch(0, length - 1, key);
		}

		if (A[pivot] == key)
		{
			return pivot;
		}

		if (A[0] <= key)
		{
			return BinarySearch(0, pivot - 1,key);
		}
		return BinarySearch(pivot + 1, length - 1, key);
	}

	bool PrintPairsInSortedRotated(int x)
	{
		int i;
		for (i = 0; i < length - 1; i++)
		{
			if (A[i] > A[i + 1])
			{
				break;
			}
		}
		int l = (i + 1) % length;
		int r = i;

		while (l != r)
		{
			if (A[l] + A[r] == x)
			{
				cout << "Found pair: " << A[l] << ", " << A[r] << endl;
				return true;
			}
			if (A[l] + A[r] < x)
			{
				l = (l + 1) % length;
			}
			else
			{
				r = (length + r - 1) % length;
			}
		}
		return false;
	}
	
	int MaxSum()
	{
		int aSum = 0;
		int cVal = 0;

		for (int i = 0; i < length; i++)
		{
			aSum = aSum += A[i];
			cVal = cVal + (i * A[i]);
		}

		int maxVal = cVal;

		for (int j = 1; j < length; j++)
		{
			cVal = cVal + aSum - length * A[length - j];
			if (cVal > maxVal)
			{
				maxVal = cVal;
			}
		}

		return maxVal;
	}

	int MaxSumAll()
	{
		int cum_sum = 0;
		for (int i = 0; i < length; i++)
		{
			cum_sum += A[i];
		}

		int curr_val = 0;
		for (int i = 0; i < length; i++)
		{
			curr_val += i * A[i];
		}

		int res = curr_val;

		for (int i = 1; i < length; i++)
		{
			int next_val = curr_val - (cum_sum - A[i - 1]) + A[i - 1] * (length - 1);
			curr_val = next_val;
			res = max(res, next_val);
		}

		return res;
	}
};



#endif