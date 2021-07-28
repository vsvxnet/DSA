#include "DSARecursion.h"
#include <iostream>>
void DSARecursion::HeadRecursion(int n)
{

	//printf("%d ", "Testing.. HeadRecursion");
	if (n > 0)
	{
		HeadRecursion(n-1);
		printf("%d ", n);
	}
}

void DSARecursion::TailRecursion(int n)
{
//	printf("%d ", "Testing.. TailRecursion");
	if (n > 0)
	{
		printf("%d ", n);
		TailRecursion(n - 1);
	}
}

int DSARecursion::SumRecursion(int n)
{
	if (n > 0)
	{
		return SumRecursion(n - 1) + n;
	}
	return 0;
}

int DSARecursion::SumRecursionStatic(int n)
{
	static int x = 0; // variable created at compile-time
	if (n > 0)
	{
		x++;
		return SumRecursionStatic(n - 1) + x;
	}
	return 0;
}

void DSARecursion::TreeRecursion(int n)
{
	if (n > 0)
	{
		printf("%d ", n);
		TreeRecursion(n - 1);
		TreeRecursion(n - 1);
	}
}

void DSARecursion::IndirectRecursionA(int n)
{
	if (n > 0)
	{
		printf("%d ", n);
		IndirectRecursionB(n - 1);
	}
}
void DSARecursion::IndirectRecursionB(int n)
{
	if (n > 1)
	{
		printf("%d ", n);
		IndirectRecursionA(n / 2);
	}
}
void DSARecursion::TestHeadRecursion()
{
	std::cout << "\nTesting HeadRecursion()" << std::endl;
	int x = 5;
	TailRecursion(x);
}

void DSARecursion::TestTailRecursion()
{

	std::cout << "\nTesting TailRecursion()" << std::endl;
	int x = 10;
	HeadRecursion(x);
}

void DSARecursion::TestSumRecursion()
{
	int x = 10;
	std::cout << "\nTesting SumRecursion()" << std::endl;
	printf("%d ", SumRecursion(x));

	std::cout << "\nTesting SumRecursion(static)" << std::endl;
	printf("%d ", SumRecursionStatic(x));

}

void DSARecursion::TestTreeRecursion()
{
	std::cout << "\nTesting TreeRecursion()" << std::endl;

	int x = 5;
	TreeRecursion(x);
}

void DSARecursion::TestIndirectRecursion()
{
	std::cout << "\nTesting IndirectRecursion()" << std::endl;

	IndirectRecursionA(20);
	
}

