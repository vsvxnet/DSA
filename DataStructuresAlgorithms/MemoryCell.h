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

	void Display()
	{
		cout << "Display() MemoryCell: ";
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

	int LinearSearch(T target_value)
	{
		int i;
		for (int i = 0; i < length; i++)
		{
			if (target_value == A[i])
			{
				return i;
			}
		}
		return -1;
	}
	
	bool IsSorted()
	{
		if (length == 0 || length == 1)
		{
			return true;
		}

		if (A[0] > A[1])
		{
			return false;
		}
		return IsSorted(A + 1, length - 1);
	}
	
	bool IsSorted(T a[], int length)
	{

		if (length == 0 || length == 1)
		{
			return true;
		}

		if (a[0] > a[1])
		{
			return false;
		}

		return IsSorted(a + 1, length - 1);
	}
	
	void BubbleSort(MemoryCell *m)
	{
		for (int cnt = 1; cnt <= m->length - 1; cnt++)
		{
			int flag = 0;
			for (int j = 0; j <= m->length - 2; j++)
			{
				if (m->A[j] > m->A[j + 1])
				{
					swap(m->A[j], m->A[j + 1]);
					flag = 1;
				}
			}

			if (flag == 0)
			{
				break;
			}
		}
	}
	
	void SelectionSort(MemoryCell* m)
	{
		for (int i = 0; i <= m->length - 2; i++)
		{
			int smallest = i;
			for (int j = i + 1; j <= m->length - 1; j++)
			{
				if (this->A[j] < this->A[smallest])
				{
					smallest = j;
				}
			}
			swap(this->A[i], this->A[smallest]);
		}
	}

	void SortSTL(MemoryCell* m)
	{
		sort(m->A, m->A + m->length);
	}

	int BinarySearch(T search_value)
	{
		int low, mid, high;
		low = 0;
		high = GetLength() - 1;

		while (low <= high)
		{
			mid = (low + high) / 2;
			if (search_value == A[mid])
			{
				return mid;
			}
			else if (search_value < A[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		return -1;
	}

	int Factorial(int n)
	{
		// base case, 0! = 1
		if (n == 0)
		{
			return 1;
		}

		int subsetAnswer = ComputeFactorial(n - 1);
		int ans = n * subsetAnswer;
		return ans;
	}

	int Fibonacci(int n)
	{
		if (n == 0)
		{
			return 0;
		}

		if (n == 1)
		{
			return 1;
		}

		int smallAns1 = fib(n - 1);
		int smallAns2 = fib(n - 2);

		return smallAns1 + smallAns2;
	}

	int Power(int base, int exponent)
	{
		if (exponent == 0)
		{
			return 1;
		}
		int smallAns = Power(base, exponent - 1);
		return base * smallAns;
	}

	void RecursivePrintFromHead(int num)
	{

		if (num == 0)
		{
			return;
		}

		cout << num << endl;
		RecursivePrintFromHead(num - 1);
	}

	void RecursivePrintFromTail(int num)
	{
		if (num == 0)
		{
			return;
		}
		RecursivePrintFromTail(num - 1);
		cout << num << endl;
	}

	int DigitCount(int n)
	{
		if (n == 0)
		{
			return 0;
		}

		int smallAns = DigitCount(n / 10);

		return smallAns + 1;
	}

	int DigitSum(int n) 
	{
		if (n == 0)
		{
			return 0;
		}
		int smallAns = DigitSum(n / 10);
		int last_digit = n % 10;
		return smallAns + last_digit;

	}

	int DigitMultiply(int m, int n)
	{
		if (n == 0)
		{
			return 0;
		}

		int smallAns = DigitMultiply(m, n - 1);
		return smallAns + m;
	}

	int CountZeros(int n)
	{
		if (n == 0) { return 0; }
		int smallAns = CountZeros(n / 10);
		int last_digit = n % 10;
		if (last_digit == 0)
		{
			return 1 + smallAns;
		}
		else
		{
			return smallAns;
		}
	}	

	double GeometricSum(int k)
	{
		if (k == 0)
		{
			return 1;
		}

		double smallAns = GeometricSum(k - 1);

		return smallAns + 1.0 / Power(2, k);
	}
	
};


#endif