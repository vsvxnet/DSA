#pragma once
#ifndef MyHelper_H
#define MyHelper_H
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}

};
class MyHelper 
{
public:
	MyHelper() {}
	~MyHelper() {}
	void PrintArray(int a[], int count)
	{
		cout << "Printing array: ";
		for (int i = 0; i < count; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}

	int SumArray(int a[], int count)
	{
		int sum = 0;
		for (int i = 0; i < count; i++)
		{
			sum += a[i];
		}
		return sum;
	}

	int GetLargest(int a[], int count)
	{
		int largest = a[0];
		for (int i = 0; i < count; i++)
		{
			if (a[i] > largest)
			{
				largest = a[i];
			}
		}
		return largest;
	}

	int GetSmallest(int a[], int count)
	{
		int smallest = a[0];
		for (int i = 0; i < count; i++)
		{
			if (a[i] < smallest)
			{
				smallest = a[i];
			}
		}
		return smallest;
	}

	void ReversePrintArray(int a[], int count)
	{
		cout << "Reverse Printing array: ";
		for (int i = count-1; i >= 0; i--)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}

	void ReverseArray(int a[], int count)
	{
		int s = 0, e = count - 1;
		while (s <= e)
		{
			swap(a[s], a[e]);
			s++; e--;
		}
	}

	void SelectionSort(int a[], int count)
	{
		for (int i = 0; i <= count - 2; i++)
		{
			int smallest = i;
			for (int j = i + 1; j <= count - 1; j++)
			{
				if (a[j] < a[smallest])
				{
					smallest = j;
				}
			}
			swap(a[i], a[smallest]);
		}
	}

	void BubbleSort(int a[], int count)
	{
		for (int i = 1; i <= count - 1; i++)
		{
			int flag = 0;
			for (int j = 0; j <= count - 2; j++)
			{
				if (a[j] > a[j + 1])
				{
					swap(a[j], a[j + 1]);
					flag = 1;
				}
			}
			if (flag == 0)
			{
				break;
			}
		}
	}

	int LinearSearch(int a[], int count, int target)
	{
		for (int i = 0; i < count; i++)
		{
			if (a[i] == target)
			{
				return i;
			}
		}
		return -1;
	}

	bool IsSorted(int a[], int count)
	{
		for (int i = 0; i < count-2; i++)
		{
			if (a[i] > a[i + 1])
			{
				return false;
			}
		}
		return true;
	}
	int BinarySearch(int a[], int count, int target)
	{
		if (IsSorted(a, count) == false) { 
		
			cout << "Not sorted.. sorting .. " << endl;
			PrintArray(a, count);
			sort(a, a + count);
			PrintArray(a, count);
		}
		int s = 0, e = count - 1;
		while (s <= e)
		{
			int mid = (s + e) / 2;
			if (a[mid] == target)
			{
				return mid;
			}
			else if (target < a[mid])
			{
				e = mid - 1;
			}
			else
			{
				s = mid + 1;
			}
		}
		return -1;
	}

	void MergeSort(int a[], int s, int e)
	{
		if (s >= e)
		{
			return;
		}
		int mid = (s + e) / 2;

		MergeSort(a, s, mid);
		MergeSort(a, mid + 1, e);

		Merge(a, s, e);
	}

	void Merge(int* a, int s, int e)
	{
		int mid = (s + e) / 2;
		int i = s;
		int j = mid + 1;
		int k = s;
		int tmp[100];

		while (i <= mid && j <= e)
		{
			if (a[i] < a[j])
			{
				tmp[k++] = a[i++];
			}
			else
			{
				tmp[k++] = a[j++];
			}
		}

		while (i <= mid)
		{
			tmp[k++] = a[i++];
		}
		while (j <= e)
		{
			tmp[k++] = a[j++];
		}

		for (int i = s; i <= e; i++)
		{
			a[i] = tmp[i];
		}
	}
	int partition(int a[], int s, int e)
	{
		int i = s;
		int pivot = a[e];
		for (int j = s; j <= e - 1; j++)
		{
			if (a[j] < pivot)
			{
				swap(a[i], a[j]);
				i++;
			}
		}
		swap(a[i], a[e]);
		return i;
	}
	void QuickSort(int a[], int s, int e)
	{
		if (s >= e)
		{
			return;
		}
		int p = partition(a, s, e);
		QuickSort(a, s, p - 1);
		QuickSort(a, p + 1, e);
	}

	void PrintLinkedList(Node *&head)
	{
		while (head != NULL)
		{
			cout << head->data << " -> ";
			head = head->next;
		}
		cout << "NULL" << endl;
	}

	Node* TakeLinkedListTailInput()
	{
		int data;
		cout << "Enter number a linked-list element (-1 to end): ";
		cin >> data;

		Node* h = NULL;
		Node* t = NULL;
		while (data != -1)
		{
			Node* node = new Node(data);
			if (h == NULL)
			{
				h = node;
				t = node;
			}
			else
			{
				t->next = node;
				t = node;
			}
			cin >> data;
		}
		return h;
	}

	Node* TakeLinkedListHeadInput()
	{
		int data;
		cout << "Enter number a linked-list element (-1 to end): ";
		cin >> data;
		Node* h = NULL;
		Node* t = NULL;
		while (data != -1)
		{
			Node* node = new Node(data);
			if (h == NULL)
			{
				h = node;
				t = node;
			}
			else
			{
				node->next = h;
				h = node;
			}
			cin >> data;
		}
		return h;
	}

	int GetLinkedListLength(Node* head)
	{
		int count = 0;
		while (head!=NULL)
		{
			count++;
			head = head->next;
		}
		return count;
	}

	void PrintLinkedListAtIndex(Node* head, int index)
	{
		if (index < 0)
		{
			cout << "-1" << endl;
			return;
		}

		int count = 1;
		while (count <= index && head != NULL)
		{
			head = head->next;
			count++;
		}

		if (head)
		{
			cout << "Index =" << index << " Value =" << head->data << endl;
		}
		else
		{
			cout << "-1" << endl;
		}
	}

	Node* InsertLinkedListAtIndex(Node* head, int index, int data)
	{
		if (index < 0)
		{
			return head;
		}

		if (index == 0)
		{
			Node* node = new Node(data);
			node->next = head;
			head = node;
			return head;
		}

		Node* copyHead = head;
		int count = 1;
		while (count <= index - 1 && head != NULL)
		{
			head = head->next;
			count++;
		}

		if (head)
		{
			Node* node = new Node(data);
			Node* tmp = head->next;
			head->next = node;
			node->next = tmp;
			return copyHead;
		}
		return copyHead;
	}

	Node* DeleteLinkedListAtIndex(Node* head, int index)
	{
		if (index < 0) return head;

		if (index == 0 && head)
		{
			Node* newHead = head->next;
			head->next = NULL;
			delete head;
			return newHead;
		}

		Node* current = head;
		int count = 1;
		while (count <= index - 1 && current != NULL) 
		{
			current = current->next;
			count++;
		}

		if (current && current->next)
		{
			Node* tmp = current->next;
			current->next = current->next->next;
			tmp->next = NULL;
			delete tmp;
			return head;
		}
		return head;
	}

	int GetLinkedListLengthRecursive(Node* head)
	{
		if (head != NULL) return 0;
		return 1 + (GetLinkedListLengthRecursive(head->next));
	}

	bool SearchLinkedList(Node* head, int data)
	{
		Node* current = head;
		while (current != NULL)
		{
			if (current->data == data)
			{
				return true;
			}
			current = current->next;
		}
		return false;
	}

	bool SearchLinkedListRecursive(Node* head, int data)
	{
		if (head == NULL) return false;
		if (head->data == data) return true;
		return SearchLinkedListRecursive(head->next, data);
	}
};
#endif