#pragma once
#ifndef MemoryCell_H
#define MemoryCell_H
#include <iostream>
#include <algorithm>
using namespace std;

template<class T> class MemoryCell
{
private:
	T* A;
	int size;
	int length;
public:
	explicit MemoryCell(int initial_size) :size(initial_size)
	{
		cout << "Constructor: MemoryCell of size " << this->size << endl;
		A = new T[this->size];
	}
	~MemoryCell()
	{
		cout << "Destructor(): MemoryCell of size " << this->size << endl;

		delete[] A;
	}

	MemoryCell(const MemoryCell& rhs)
	{
		A = new T{ *rhs.A };
		size = rhs.size;
		length = rhs.length;
		cout << "CopyConstructor(): MemoryCell of size " << this->size << endl;

	}

	MemoryCell(MemoryCell&& rhs) :A{ rhs.A }, size{ rhs.size }, length{ rhs.length }
	{
		rhs.A = nullptr;
		cout << "MoveConstructor(): MemoryCell of size " << this->size << endl;
	}

	MemoryCell& operator=(const MemoryCell& rhs)
	{
		cout << "Copy-Assignment(): " << endl;

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
		cout << "Move-Assignment(): " << endl;

		std::swap(A, rhs.A);
		std::swap(size, rhs.size);
		std::swap(length, rhs.length);
		return *this;
	}

	T read() const
	{
		return *A;
	}
	void write(T x)
	{
		*A = x;
	}

	void Create()
	{
		cout << "Enter number of elements: " << flush;
		cin >> length;
		if (length > size)
		{
			cout << "Length is greater than allocated size." << endl;
		}
		else
		{
			cout << "Enter the array elements: " << endl;
			for (int i = 0; i < length; i++)
			{
				cout << "Array [" << i << "] = " << flush;
				cin >> A[i];
			}
			cout << endl;
		}
	}

	void Display(string displayMsg)
	{
		cout << "Display(" << displayMsg<< ") MemoryCell: ";
		for (int i = 0; i < length; i++)
		{
			cout << A[i] << " ";
		}
		cout << endl;
	}

	int GetLength()
	{
		return length;
	}

	void Append(MemoryCell* m, int x)
	{
		if (m->length < m->size)
		{
			m->A[m->length++] = x;
		}
	}

	void Insert(MemoryCell* m, int index, int x)
	{
		int i;
		if (index >= 0 && index <= m->length)
		{
			for (i = m->length; i > index; i--)
			{
				m->A[i] = m->A[i - 1];
			}
			m->A[index] = x;
			m->length++;
		}
	}

	int Delete(MemoryCell* m, int index)
	{
		int x = 0;
		int i;
		if (index >= 0 && index <= m->length)
		{
			x = m->A[index];
			for (i = index; i < m->length - 1; i++)
			{
				m->A[i] = m->A[i + 1];
			}
			m->length--;
			return x;
		}
	}

	bool IsSortedHelper() 
	{
		return IsSorted(A, GetLength());
	}

	bool IsSorted(int a[], int n)
	{
		if (n == 0 || n == 1)
		{
			return true;
		}
		if (a[0] > a[1])
		{
			return false;
		}

		return IsSorted(a + 1, n - 1);
	}

	int SumHelper()
	{
		return RecursiveSum(A, GetLength());
	}

	int RecursiveSum(int a[], int n)
	{
		if (n == 0)
		{
			return 0;
		}
		return a[0] + RecursiveSum(a + 1, n - 1);
	}

	int FindSmallestValue()
	{
		int result = INT_MAX;
		for (int i = 0; i < length; i++)
		{
			if (A[i] < result)
			{
				result = A[i];
			}
		
		}
		return result;
	}

	int FindLargestValue()
	{
		int result = INT_MIN;
		for (int i = 0; i < length; i++)
		{
			if (A[i] > result)
			{
				result = A[i];
			}
		}
	}


};


#endif