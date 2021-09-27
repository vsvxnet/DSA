#pragma once
#ifndef MemoryCell_H
#define MemoryCell_H
#include <iostream>
using namespace std;

template<class T> class MemoryCell
{
private:
	T *A;
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
		A = new T{*rhs.A};
		size = rhs.size;
		length = rhs.length;
		cout << "CopyConstructor(): MemoryCell of size " << this->size << endl;

	}

	MemoryCell(MemoryCell&& rhs) :A{ rhs.A }, size{ rhs.size }, length{rhs.length}
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

	MemoryCell& operator=(MemoryCell && rhs)
	{
		cout << "Move-Assignment(): " << endl;

		std::swap(A, rhs.A);
		std::swap(size, rhs.size);
		std::swap(length, rhs.length);
		return *this;
	}

	int read() const
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

	void Display()
	{
		cout << "Display() MemoryCell: ";
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

	int LinearSearch(T target_value) 
	{
		int i;
		for (int i = 0; i <length; i++)
		{
			if (target_value == A[i])
			{
				return i;
			}
		}
		return -1;
	}

	int BinarySearch(T target_value)
	{
		int low, mid, high;
		low = 0;
		high = length - 1;

		while (low <= high)
		{
			mid = (low + high) / 2;
			if (target_value == A[mid])
			{
				return mid;
			}
			else if (target_value < A[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid1 + 1;
			}
		}
		return -1;
	}

	int RecursiveBinarySearch(int low, int high, T target_value)
	{
		int mid = 0;
		if (low < high)
		{
			mid = (low + high) / 2;
			if (target_value == A[mid])
			{
				return mid;
			}
			else if (target_value < A[mid])
			{
				RecursiveBinarySearch(low, mid-1, target_value);
			}
			else
			{
				RecursiveBinarySearch(mid + 1, high, target_value);
			}
		}
		return -1;
	}

};


#endif