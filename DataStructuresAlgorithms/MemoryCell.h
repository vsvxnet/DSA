#pragma once
#ifndef MemoryCell_H
#define MemoryCell_H
#include <iostream>
using namespace std;
template<class T>
class MemoryCell
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
};


#endif