#ifndef DSAHelper_H
#define DSAHelper_H
#include "Node.h"
using namespace std;

class DSAHelper
{
public:
	// ARRAYS
	void IReverseArray(int arr[], int length)
	{
		cout << "Reversing array.." << endl;
		int s = 0, e = length - 1;

		while (s <= e)
		{
			swap(arr[s], arr[e]);
			s++;
			e--;
		}
	}
	
	void IPrintArray(int arr[], int length)
	{
		cout << "IPrinting Array: ";
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void IPrintArrayReverse(int arr[], int length)
	{
		cout << "IPrinting Array Reverse: ";
		for (int i = length-1; i >=0; i--)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}


	int ISumArray(int arr[], int length)
	{
		int answer = 0;

		for (int i = 0; i < length; i++)
		{
			answer += arr[i];
		}

		return answer;
	}
	pair<int, int> GetMinMaxIndex(int arr[], int length)
	{
		int small = 0, large = 0;
		for (int i = 0; i < length; i++)
		{
			if (arr[i]< arr[small])
			{
				small = i;
			}
			else if (arr[i] > arr[large])
			{
				large=i;
			}
		}
		return make_pair(small, large);
		
	}
	bool IIsSorted(int arr[], int length)
	{
		if (length == 1) return true;

		for (int i = 1; i < length; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				return false;
			}
		}
		return true;
	}

	void ISelectionSort(int arr[], int length)
	{
		for (int i = 0; i <= length - 2; i++)
		{
			int smallest = i;
			for (int j = i + 1; j <= length - 1; j++)
			{
				if (arr[j] < arr[smallest])
				{
					smallest = j;
				}
			}
			swap(arr[i], arr[smallest]);
		}
	}
	void IBubbleSort(int arr[], int length)
	{
		for (int count = 1; count <= length - 1; count++)
		{
			int flag = 0;
			for (int j = 0; j <= length - 2; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					swap(arr[j], arr[j + 1]);
					flag = 1; 
				}
			}
			if (flag == 0)
			{	// already sorted, break;
				break;
			}
		}
	}
	
	int ILinearSearch(int arr[], int length, int target)
	{
		for (int i = 0; i < length - 1; i++)
		{
			if (arr[i] == target)
			{
				return i;
			}
		}
		return -1;
	}

	int IBinarySearch(int arr[], int length, int target)
	{
		int s = 0, e = length - 1;

		while (s <= e)
		{
			int mid = (s + e) / 2;
			if (arr[mid] == target)
			{
				return mid;
			}
			else if (target < arr[mid])
			{
				e = mid - 1;
			}
			else if (arr[mid] < target)
			{
				s = mid + 1;
			}
		}
		return -1;
	}

	// CHAR ARRAYS
	void IPrintArray(char arr[])
	{
		cout << "Iterative Print Array(char): ";
		for (int i = 0; arr[i] != '\0'; i++)
		{
			cout << arr[i]<<" ";
		}
		cout << endl;
	}
	void IReverseArray(char arr[])
	{
		int s = 0, e = IGetLength(arr) - 1;

		while (s <= e)
		{
			swap(arr[s], arr[e]);
			s++;
			e--;
		}
	}
	int IGetLength(char input[])
	{
		int count = 0;
		for (int i = 0; input[i] != '\0'; i++)
		{
			count++;
		}
		return count;
	}
	
	// VECTORS
	void IPrintVector(vector<int>& v)
	{
		cout << "Iterative Print Vector: ";
		int length = v.size();
		
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	
	}

	// RECURSION

	bool RIsSorted(int arr[], int length)
	{
		if (length == 0 || length == 1)
		{
			return true;
		}

		if (arr[0] > arr[1])
		{
			return false;
		}

		return RIsSorted(arr + 1, length - 1);
	}
	int RSumArray(int arr[], int length)
	{
		if (length == 0) return 0;

		return arr[0] + RSumArray(arr + 1, length - 1);
	}

	int RGetFirstIndex(int arr[], int length, int target, int i)
	{
		if (i ==length) return -1;
		if (arr[i] == target)
		{
			return i;
		}
		return RGetFirstIndex(arr, length, target, i + 1);
	}

	int RGetLastIndex(int arr[], int length, int target, int i)
	{
		if (i == -1)
		{
			return -3;
		}
		if (arr[i] == target)
		{
			return i;
		}
		return RGetLastIndex(arr, length, target, i - 1);
	}

	void RPrintPositions(int arr[], int length, int target, int i)
	{
		if (i == length) return;
		if (arr[i] == target)
		{
			cout << i << " ";
		}
		RPrintPositions(arr, length, target, i + 1);
	}

	int RCountOccurance(int arr[], int length, int target, int i)
	{
		if (i == length)
			return 0;

			if (arr[i] == target)
			{
				return 1 + RCountOccurance(arr, length, target, i + 1);
			}
			else
			{
				return RCountOccurance(arr, length, target, i + 1);
			}
	}

	void RSaveAllPositions(int arr[], int length, int target, int i, vector<int>& ans)
	{
		if (i == length) { return; }

		if (arr[i] == target)
		{
			ans.push_back(i);
		}
		RSaveAllPositions(arr, length, target, i + 1, ans);
	}

	bool RCheckPalindrome(int arr[], int s, int e)
	{
		if (s > e) return true;

		if (arr[s] == arr[e])
		{
			return RCheckPalindrome(arr, s + 1, e - 1);
		}
		else
		{
			return false;
		}
	}

	void RPrintArrayHead(int arr[], int length, int i)
	{
		if (i > length - 1)
		{
			return;
		}
		cout << arr[i] << " ";
		RPrintArrayHead(arr, length, i + 1);
	}

	void RPrintArrayTail(int arr[], int length, int i)
	{

		if (i > length - 1)
		{
			
			return;
		}
		RPrintArrayTail(arr, length, i + 1);
		cout << arr[i] << " ";
	}

	void RPrintVector(vector<int> v,int length, int i)
	{
		if (i < length)
		{
			cout << v[i] << " ";
			RPrintVector(v, length, i + 1);
		}
	}

	int RGetLength(char input[])
	{
		if (input[0] == '\0')
		{
			return 0;
		}
		return 1 + RGetLength(input+1);
	}

	void RReplaceCharacter(char input[], char replaceTarget, char replaceWith)
	{
		if (input[0] == '\0') return ;

		if (input[0] == replaceTarget)
		{
			input[0] = replaceWith;
		}
		return RReplaceCharacter(input + 1, replaceTarget, replaceWith);
	}

	void RRemoveCharacter(char input[], char removeTarget)
	{
		if (input[0] == '\0')
		{
			return;
		}

		if (input[0] != removeTarget)
		{
			RRemoveCharacter(input + 1, removeTarget);
		}
		else
		{
			for (int i = 0; input[i] != '\0'; i++)
			{
				input[i] = input[i + 1];
			}
			RRemoveCharacter(input, removeTarget);
		}
	}

	void RRemoveConsecutiveDuplicates(char input[])
	{
		if (input[0] == '\0')
		{
			return;
		}

		if (input[0] != input[1])
		{
			RRemoveConsecutiveDuplicates(input + 1);
		}
		else
		{
			for (int i = 0; input[i] != '\0'; i++)
			{
				input[i] = input[i + 1];
			}
			RRemoveConsecutiveDuplicates(input);
		}
	}

	void RPrintSubsequence(string input, string output)
	{
		if (input.length() == 0)
		{
			cout << output << endl;
			return ;
		}
		RPrintSubsequence(input.substr(1), output + input[0]);
		RPrintSubsequence(input.substr(1), output);
	}

	void RStoreSubsequence(string input, string output, vector<string>& v)
	{
		if(input.length() == 0)
		{
			v.push_back(output);
			return;
		}

		RStoreSubsequence(input.substr(1), output + input[0],v);
		RStoreSubsequence(input.substr(1), output,v);
	}
	
	void RPrintPermutations(string str, int i = 0)
	{
		if (str[i] == '\0')
		{
			cout << str << endl;
		}
		for (int j = i; str[j] != '\0'; j++)
		{
			swap(str[i], str[j]);
			RPrintPermutations(str, i + 1);
			swap(str[i], str[j]);
		}
	}

	int CountStaircaseSteps(int n)
	{
		if (n == 0 || n == 1)
		{
			return 1;
		}

		if (n < 0)
		{
			return 0;
		}

		return CountStaircaseSteps(n - 1) + CountStaircaseSteps(n - 2) + CountStaircaseSteps(n - 3);
	}
	// Merge Sort & QuickSort

	void MergeArray(int* arr, int s, int e)
	{
		int mid = (s + e) / 2;

		int i = s;
		int j = mid + 1;
		int k = s;

		int tmp[1000];

		while (i <= mid && j <= e)
		{
			if (arr[i] < arr[j])
			{
				tmp[k++] = arr[i++];
			}
			else
			{
				tmp[k++] = arr[j++];
			}
		}

		while (i <= mid)
		{
			tmp[k++] = arr[i++];
		}
		while (j <= e)
		{
			tmp[k++] = arr[j++];
		}

		for (int i = s; i <= e; i++)
		{
			arr[i] = tmp[i];
		}
	}
	void MergeSort(int arr[], int s, int e)
	{
		if (s >= e)
		{
			return;
		}

		int mid = (s + e) / 2;
		MergeSort(arr, s, mid);
		MergeSort(arr, mid + 1, e);

		MergeArray(arr, s, e);
	}

	// LinkedList
	void IPrintLinkedList(Node *head)
	{
		while (head != NULL)
		{
			cout << head->data << " -> ";
			head = head->next;
		}
		cout << "NULL" << endl;
	}
	int IGetLength(Node *head)
	{
		int count = 0;
		while (head) 
		{
			count++;
			head = head->next;
		}
		return count;
	}

	void IPrintLinkedListAtIndex(Node* head, int index)
	{
		if (index < 0) { 
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
			cout << head->data << endl;
		}
		else
		{
			cout << "-1" << endl;
		}
	}
	Node* IInsertLinkedListAtIndex(Node* head, int index, int value)
	{
		if (index < 0) { return head; }
		if (index == 0)
		{
			Node* n = new Node(value);
			n->next = head;
			head = n;
			return head;
		}
		Node* copy = head;
		int count = 1;
		while (count <= index-1 && head != NULL)
		{
			head = head->next;
			count++;
		}
		if (head)
		{
			Node* n = new Node(value);
			Node* tmp = head->next;
			head->next = n;
			n->next = tmp;
			return copy;

		}
		return copy;
	}

	Node* IDeleteLinkedListAtIndex(Node* head, int index)
	{
		if (index < 0) { return head; }

		if (index == 0 && head)
		{
			Node* new_head = head->next;
			head->next = NULL;
			delete head;
			return new_head;
		}

		Node* curr = head;
		int count = 1;
		while (count <= index - 1 && curr != NULL)
		{
			curr = curr->next;
			count++;
		}
		if (curr && curr->next)
		{
			Node* tmp = curr->next;
			curr->next = curr->next->next;
			tmp->next = NULL;
			delete tmp;
			return head;
		}
		return head;
	}
	int RGetLength(Node* head)
	{
		if (head == NULL) { return 0; }
		return 1 + RGetLength(head->next);
	}

	bool ISearchLinkedList(Node* head, int data)
	{
		Node* curr = head;
		while (curr != NULL)
		{
			if (curr->data == data)
			{
				return true;
			}
			curr = curr->next;
		}
		return false;
	}
	bool RSearchLinkedList(Node* head, int data)
	{
		if (head == NULL) return false;
		if (head->data == data) return true;
		return RSearchLinkedList(head->next, data);
	}

	Node* IGetMiddleNode(Node *head)
	{
		Node* slow = head;
		Node* fast = head->next;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast != NULL)
		{
			return slow->next;
		}
		return slow;
	}
	Node* IReverseLinkedList(Node*head)
	{
		Node* current = head;
		Node* prev = NULL, * next = NULL;

		while (current != NULL)
		{
			// store next
			next = current->next;
			
			// reverse current->next
			current->next = prev;

			// move pointer one position head
			prev = current;
			current = next;
		}
		head = prev;
		return head;
	}
	Node* RReverseLinkedList(Node* head)
	{
		if (head == NULL || head->next == NULL)
		{
			return head;
		}

		Node* rest = RReverseLinkedList(head->next);
		head->next->next = head;

		head->next = NULL;

		return rest;
	}
	Node* IRemoveLinkedListNodeAtIndex(Node* head, int k)
	{
		Node* one = head;
		Node* two = head;

		while (k--) { /// k times
			two = two->next;
		}
		if (two == NULL) {   /// length of ll = k  => delete head node
			return one->next;
		}
		while (two->next != NULL) {
			one = one->next;
			two = two->next;
		}

		/// delete kth node from end
		one->next = one->next->next;      /// memory leak

		return head;
	}

	Node* IMergeLinkedList(Node* l1, Node* l2)
	{
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		Node* finalHead = NULL;

		if (l1->data < l2->data)
		{
			finalHead = l1;
			l1 = l1->next;
		}
		else
		{
			finalHead = l2;
			l2 = l2->next;
		}

		Node* p = finalHead;

		while (l1 && l2)
		{
			if (l1->data < l2->data)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}

		if (l1)
		{
			p->next = l1;
		}
		else
		{
			p->next = l2;
		}
		return finalHead;
	}
	
	Node* RMergeLinkedList(Node* a, Node* b)
	{
		if (a == NULL) return b;
		if (b == NULL) return a;

		Node* newHead = NULL;
		if (a->data < b->data)
		{
			newHead = a;
			newHead->next = RMergeLinkedList(a->next, b);
		}
		else
		{
			newHead = b;
			newHead->next = RMergeLinkedList(a, b->next);
		}
		return newHead;
	}



};

#endif