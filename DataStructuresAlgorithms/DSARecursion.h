#pragma once
class DSARecursion
{
private:
	void HeadRecursion(int n);
	void TailRecursion(int n);
	int SumRecursion(int n);
	int SumRecursionStatic(int n);
	void TreeRecursion(int n);
	void IndirectRecursionA(int n);
	void IndirectRecursionB(int n);
	int NestedRecursion(int n);

public:
	void TestHeadRecursion();
	void TestTailRecursion();
	void TestSumRecursion();
	void TestTreeRecursion();
	void TestIndirectRecursion();
	void TestNestedRecursion();
};