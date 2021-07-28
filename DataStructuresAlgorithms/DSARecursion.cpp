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
	printf("%d ", SumRecursion(x));
}
