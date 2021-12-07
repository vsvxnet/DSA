#ifndef DSAHelper_H
#define DSAHelper_H
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

template <typename T> class BTNode
{
public:
	T data;
	BTNode* left;
	BTNode* right;
	BTNode(T data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~BTNode()
	{
		delete left;
		delete right;
	}

};

template <typename T> class TreeNode
{
public:
	T data;
	vector<TreeNode<T>*> children;
	TreeNode(T data) {
		this->data = data;
	}
};

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
class DSAHelper
{
public:
	void PrintArray(vector<int> nums)
	{
		cout << "Printing Array: ";

		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << " ";
		}
		cout << endl;
	}
	void PrintArrayReverse(vector<int> nums)
	{
		cout << "Printing Array Reverse: ";

		for (int i = nums.size() - 1; i >= 0; i--)
		{
			cout << nums[i] << " ";
		}

		cout << endl;
	
	}
	int SumArray(vector<int> nums)
	{
		int sum = 0; 

		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
		}

		return sum;
	}
	bool IsArraySorted(vector<int> nums)
	{
		if (nums.size() == 0 || nums.size() == 1)
		{
			return true;
		}

		for (int i = 0; i < nums.size()-1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				return false;
			}
		}
		return true;
	}
	
	int GetLargestValueIndex(vector<int> nums)
	{
		if (nums.size() == 0)
			return -1;
		if (nums.size() == 1)
		{
			return 0;
		}

		int idx = 0, max = nums[idx];

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > max)
			{
				max = nums[i];
				idx = i;
			}
			
		}
		
		return idx;
	}

	int GetSmallestValueIndex(vector<int> nums)
	{
		if (nums.size() == 0)
		{
			return -1;
		}
		if (nums.size() == 1)
		{
			return 1;
		}

		int idx = 0, min = nums[idx];
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < min)
			{
				min = nums[i];
				idx = i;
			}
		}

		return idx;
	}

	void ReverseArray(vector<int>& nums)
	{
		if (nums.size() == 0)
		{
			return;
		}
		int start = 0;
		int end = nums.size() - 1;

		while (start <= end)
		{
			swap(nums[start], nums[end]);
			start++;
			end--;
		}
	}

	int GetLength(char input[])
	{
		int count = 0;
		for (int i = 0; input[i] != '\0'; i++)
		{
			count++;
		}
		return count;
	}

	void ReverseArray(char input[])
	{
		int start = 0;
		int end = GetLength(input) - 1;
		while (start <= end)
		{
			swap(input[start++], input[end--]);
		}
	}

	int LinearSearch(vector<int> nums, int target)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == target)
			{
				return i;
			}
		}
		return -1;
	}

	int BinarySearch(vector<int> nums, int target)
	{
		bool issorted = IsArraySorted(nums);
		if (!issorted )
		{
			cout << "Array is not sorted." << endl;
			return -1;
		}
	
		int start = 0;
		int end = nums.size() - 1;

		while (start <= end)
		{
			int mid = start + (end - start) / 2;

			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] > target)
			{
				end = mid - 1;
			}
			else if (nums[mid] > target)
			{
				start = mid + 1;
			}
		}
		return -1;
	}

	int RFactorial(int n) 
	{
		if (n == 0)
		{
			return 1;
		}

		int small_ans = RFactorial(n - 1);

		int ans = n * small_ans;
		return ans;
	}

	int RFibonacci(int n)
	{
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return 1;
		}

		int small_ans = RFibonacci(n - 1);
		int small_ans2 = RFibonacci(n - 2);

		return small_ans + small_ans2;
	}

	int RPower(int x, int n)
	{
		if (n == 0)
		{
			return 1;
		}

		int small_ans = RPower(x, n - 1);

		return x * small_ans;
	}

	void RPrintTail(int n) {

		if (n == 0) return;
		RPrintTail(n - 1);
		cout << n << endl;
		return;
	}

	void RPrintHead(int n)
	{
		if (n == 0) return;
		cout << n << endl;
		RPrintHead(n - 1);
		return;
	}

	int RCountDigits(int n)
	{
		if (n == 0)
		{
			return 0;
		}

		int small_ans = RCountDigits(n / 10);

		return small_ans + 1;
	}

	int RSumDigits(int n)
	{
		if (n == 0)
			return 0;

		int small_ans = RSumDigits(n / 10);

		int last_digit = n % 10;
		return small_ans + last_digit;
	}

	int RMultiply(int m, int n)
	{
		if (n == 0) return 0;

		int small_ans = RMultiply(m, n - 1);

		return small_ans + m;
	}

	int RCountZeros(int n)
	{
		if (n == 0)
		{
			return 0;
		}

		int small_ans = RCountZeros(n / 10);
		int last_digit = n % 10;

		if (last_digit == 0)
		{
			return 1 + small_ans;
		}
		else
		{
			return small_ans;
		}
	}
	
	double RGeometricSum(int K)
	{
		if (K == 0) return 1;

		double small_ans = RGeometricSum(K - 1);

		return small_ans + 1.0 / RPower(2, K);
	}

	// Recursion-Medium
	bool RCheckSorted(vector<int> nums)
	{
		if (nums.size() == 0 || nums.size() == 1)
		{	
			return true;
		}
		if (nums[0] > nums[1])
		{
			return false;
		}
		vector<int> n(nums.begin() + 1, nums.end());
		return RCheckSorted(n);
	}
	bool RCheckSorted(int nums[], int length)
	{
		if (length == 0 || length == 1)
			return true;

		if (nums[0] > nums[1])
		{
			return false;
		}

		return RCheckSorted(nums + 1, length - 1);
	}

	int RSumArray(vector<int> nums)
	{
		if (nums.size() == 0) { return 0; }
		vector<int> nv(nums.begin() + 1, nums.end());
		return nums[0] + RSumArray(nv);
	}

	int RSumArray(int nums[], int length)
	{
		if (length == 0) { return 0; }

		return nums[0] + RSumArray(nums + 1, length - 1);
	}

	int RFirstIndex(int nums[], int length, int target, int idx)
	{
		if (idx == length)
		{
			return -1;
		}
		if (nums[idx] == target)
		{
			return idx;
		}

		return RFirstIndex(nums, length, target, idx + 1);
	}

	void RPrintAllPositions(int nums[], int length, int target, int idx)
	{
		if (idx == length)
		{
			return;
		}

		if (nums[idx] == target)
		{
			cout << idx << " ";
		}

		RPrintAllPositions(nums, length, target, idx + 1);
	}

	void RCountOccurance(int nums[], int length, int target, int idx, int& ans)
	{
		if (idx == length)
		{
			return;
		}

		if (nums[idx] == target)
		{
			ans++;
		}
		RCountOccurance(nums, length, target, idx + 1, ans);
	}
	
	void RSaveAllPositions(int nums[], int length, int target, int idx, vector<int>& ans)
	{
		if (idx == length)
		{
			return;
		}

		if (nums[idx] == target)
		{
			ans.push_back(idx);
		}
		RSaveAllPositions(nums, length, target, idx + 1, ans);
	}

	bool RCheckPalindrome(int nums[], int start, int end)
	{
		if (start > end)
		{
			return true;
		}

		if (nums[start] == nums[end])
		{
			return RCheckPalindrome(nums, start++, end--);
		}
		else
		{
			return false;
		}
	}

	//Recursion Advanced
	void RPrint(char input[])
	{
		if (input[0] == '\0')
		{
			return;
		}
		cout << input[0];
		RPrint(input + 1);
	}
	void RPrintReverse(char input[])
	{
		if (input[0] = '\0')
		{
			return;
		}
		RPrintReverse(input + 1);
		cout << input[0];
	}
	
	int RLength(char input[])
	{
		if (input[0] == '\0')
		{
			return 0;
		}

		return 1 + RLength(input + 1);
	}

	void RCharacterReplace(char input[], char target, char replace)
	{
		if (input[0] == '\0')
		{
			return;
		}
		if (input[0] == target)
		{
			input[0] = replace;
		}
		RCharacterReplace(input + 1, target, replace);
	}

	void RCharacterRemove(char input[], char target)
	{
		if (input[0] == '\0')
		{
			return;
		}

		if (input[0] != target)
		{
			RCharacterRemove(input + 1, target);
		}
		else
		{
			for (int i = 0; input[i] != '\0'; i++)
			{
				input[i] = input[i + 1];
			}
			RCharacterRemove(input, target);
		}	

	
	}

	void RConsecutiveDuplicateRemove(char input[])
	{
		if (input[0] == '\0')
		{
			return;
		}

		if (input[0] != input[1])
		{
			RConsecutiveDuplicateRemove(input + 1);
		}
		else
		{
			for (int i = 0; input[i] != '\0'; i++)
			{
				input[i] = input[i + 1];
			}
			RConsecutiveDuplicateRemove(input);
			
		}
	}

	void RPrintSubsequence(string input, string output)
	{
		if (input.length() == 0)
		{
			cout << output << endl;
			return;
		}

		RPrintSubsequence(input.substr(1), output + input[0]);
		RPrintSubsequence(input.substr(1), output);
	
	}

	void RStoreSubsequence(string input, string output, vector<string>& ans)
	{
		if (input.length() == 0)
		{
			ans.push_back(output);
			return;
		}

		RStoreSubsequence(input.substr(1), output + input[0], ans);
		RStoreSubsequence(input.substr(1), output, ans);
		
	}

	int RConvertStringToInteger(char str[], int n)
	{
		if (n == 0)
		{
			return 0;
		}

		int small_ans = RConvertStringToInteger(str, n - 1);
		int last_digit = str[n - 1] - '0';
		int ans = small_ans * 10 + last_digit;
		return ans;
	}

	void RPrintPermutations(char input[], int i = 0)
	{
		if (input[i] == '\0')
		{
			cout << input << endl;
			return;
		}

		for (int j = i; input[j] != '\0'; j++)
		{
			swap(input[i], input[j]);
			RPrintPermutations(input, i + 1);
			swap(input[i], input[j]);
		}
	}

	int RCountStairs(int n)
	{
		if (n == 0 || n == 1)
		{
			return 1;

		}
		if (n < 0)
		{
			return 0;
		}

		return RCountStairs(n - 1) + RCountStairs(n - 2) + RCountStairs(n - 3);
	}

	// Merge / Quick Sort


	void MergeArrays(int x[], int y[], int nums[], int start, int end)
	{
		int mid = (start + end) / 2;
		int i = start;
		int j = mid + 1;
		int k = start;

		while (i <= mid && j <= end)
		{
			if (x[i] < y[j])
			{
				nums[k++] = x[i++];
			}
			else
			{
				nums[k++] = y[j++];
			}
		}
		
		while (i <= mid)
		{
			nums[k++] = x[i++];
		}

		while (j <= end)
		{
			nums[k++] = y[j++];

		}
	
	}
	void MergeSort(int nums[], int start, int end)
	{
		if (start >= end)
			return;

		int mid = (start + end) / 2;
		int x[100], y[100];
		for (int i = start; i <= mid; i++)
		{
			x[i] = nums[i];
		}
		for (int i = mid + 1; i <= end; i++)
		{
			y[i] = nums[i];
		}

		MergeSort(x, start, mid);
		MergeSort(y, mid + 1, end);
		MergeArrays(x, y, nums, start, end);
	}

	int Partition(int nums[], int start, int end)
	{
		int i = start;
		int pivot = nums[end];
		for (int j = start; j <= end - 1; j++)
		{
			if (nums[j] < pivot)
			{
				swap(nums[i], nums[j]);
				i++;
			}
		}
		swap(nums[i], nums[end]);
		return i;
;	}

	void QuickSort(int nums[], int start, int end) 
	{
		if (start >= end)
		{
			return;
		}

		int p = Partition(nums, start, end);
		QuickSort(nums, start, p - 1);
		QuickSort(nums, p + 1, end);
	}

	// Linked-List

	void PrintLinkedList(Node*& head)
	{
		while (head != NULL)
		{
			cout << head->data << " -> ";
			head = head->next;
		}
		cout << "NULL" << endl;
	}
	int GetLength(Node* head)
	{
		int count = 0;
		while (head)
		{
			count++;
			head = head->next;
		}
		return count;
	}

	void PrintNodeValue(Node* head, int index)
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
			cout << head->data << endl;
		}
		else
		{
			cout << "-1" << endl;
		}
	}
	
	Node* InsertNode(Node* head, int index, int value)
	{
		if (index < 0)
		{
			return head;
		}

		if (index == 0)
		{
			Node* n = new Node(value);
			n->next = head;
			head = n;
			return head;
		}

		Node* headCopy = head;
		int count = 1;
		while (count <= index - 1 && head != NULL)
		{
			head = head->next;
			count++;
		}
		if (head)
		{
			Node* n = new Node(value);
			Node* t = head->next;
			head->next = n;
			n->next = t;

			return headCopy;
		
		}
		return headCopy;
	}

	Node* DeleteNode(Node* head, int index)
	{
		if (index < 0)
		{
			return head;
		}

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
			Node* t = current->next;
			current->next = current->next->next;
			t->next = NULL;
			delete t;
			return head;
		}
		return head;
	}

	
	bool FindElement(Node* head, int data)
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

	bool RFindElement(Node* head, int data)
	{
		if (head == NULL)return false;
		if (head->data == data) return true;
		return RFindElement(head->next, data);
	}

	Node* GetMiddleNode(Node* head)
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

	Node* ReverseNodes(Node* head)
	{
		Node* curr = head;
		Node* prev = NULL;

		while (curr != NULL)
		{
			Node* n = curr->next;
			curr->next = prev;
			prev = curr;
			curr = n;
		}
		return prev;
	}

	Node* RemoveNode(Node* head, int K)
	{
		Node* one = head;
		Node* two = head;

		while (K--)
		{
			two = two->next;
		}

		if (two == NULL)
		{
			return one->next;
		}

		while (two->next != NULL)
		{
			one = one->next;
			two - two->next;
		}

		one->next = one->next->next;
		
		return head;
	}
	
	Node* MergeNodes(Node* head1, Node* head2)
	{
		if (head1 == NULL)return head2;
		if (head2 == NULL)return head1;

		Node* finalHead = NULL;

		if (head1->data < head2->data)
		{
			finalHead = head1;
			head1 = head1->next;
		}
		else
		{
			finalHead = head2;
			head2 = head2->next;
		}
		Node* p = finalHead;

		while (head1 && head2)
		{
			if (head1->data < head2->data)
			{
				p->next = head1;
				head1 = head1->next;
			}
			else
			{
				p->next = head2;
				head2 = head2->next;
			
			}
			p = p->next;
		}
		if (head1)
		{
			p->next = head1;
		}
		else
		{
			p->next = head2;
		}
		return finalHead;
	}

	Node* RMergeNodes(Node* a, Node* b)
	{
		if (a == NULL)return b;
		if (b == NULL)return a;

		Node* newHead = NULL;
		if (a->data < b->data)
		{
			newHead = a;
			newHead->next = RMergeNodes(a->next, b);
		}
		else
		{
			newHead = b;
			newHead->next = RMergeNodes(a, b->next);
		}
		
		return newHead;
	}

	Node* SortList(Node* head)
	{
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		Node* slow = head;
		Node* fast = head->next;

		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		Node* n = slow->next;
		slow->next = NULL;

		Node* a = SortList(head);
		Node* b = SortList(n);

		head = RMergeNodes(a, b);
		return head;
	}

	// stacks
	bool ValidParentheses(string A)
	{
		stack<char> stk;

		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] == '(' || A[i] == '[' || A[i] == '{' || A[i] == '<')
			{
				stk.push(A[i]);
			}
			else
			{
				if (stk.empty())return false;
				else if (A[i] == ')')
				{
					if (stk.top() == '(')
					{
						stk.pop();
					}
					else { return false; }
				}
				else if (A[i] == ']')
				{
					if (stk.top() == '[')
					{
						stk.pop();
					}
					else { return false; }
				}
				else if (A[i] == '}')
				{
					if (stk.top() == '{')
					{
						stk.pop();
					}
					else { return false; }
				}
				else if (A[i] == '>')
				{
					if (stk.top() == '<')
					{
						stk.pop();
					}
					else { return false; }
				}
			
			}
		}

		if (stk.empty())return true;
		return false;
	}

	int EvaluateReversePolishNotation(vector<string>& tokens)
	{
		stack<int> st;

		for (int i = 0; i < tokens.size(); i++)
		{
			if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
			{
				int v1 = st.top();
				st.pop();
				int v2 = st.top();
				st.pop();

				if (tokens[i] == "+")
				{
					st.push(v2 + v1);
				}
				else if (tokens[i] == "-")
				{
					st.push(v2 - v1);
				}
				else if (tokens[i] == "*")
				{
					st.push(v2 * v1);
				}
				else if(tokens[i] == "/")
				{
					st.push(v2 / v1);
				}
			}
			else
			{
				st.push(atoi(tokens[i].c_str()));
			}
		}
		return st.top();

	}

	string RemoveDuplicates(string s)
	{
		int stptr = -1;
		for (int i = 0; i < s.size(); i++)
		{
			if (stptr == -1 || s[i] != s[stptr])
			{
				stptr++;
				s[stptr] = s[i];
			}
			else
			{
				stptr--;
			}
		}
		string ans = "";
		for (int i = 0; i <= stptr; i++)
		{
			ans.push_back(s[i]);
		}
		return ans;
	}


	// queues

	void ReverseQueue(queue<int>& q)
	{
		stack<int> s;
		while (!q.empty())
		{
			s.push(q.front());
			q.pop();
		}

		while (!s.empty())
		{
			q.push(s.top());
			s.pop();
		}
	}

	// Generic Trees
	
	void PrintTree(TreeNode<int>* root)
	{
		if (root == NULL)
		{
			return;

		}

		cout << root->data << ": ";
		for (int i = 0; i < root->children.size(); i++)
		{
			cout << root->children[i]->data << ", ";
		}
		cout << endl;

		for (int i = 0; i < root->children.size(); i++)
		{
			PrintTree(root->children[i]);
		}
	}

	TreeNode<int>* RecursiveInput()
	{
		int rootData;
		cout << "Enter data" << endl;
		cin >> rootData;

		TreeNode<int>* root = new TreeNode<int>(rootData);

		int n;
		cout << " Enter number of children of " << rootData << endl;
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			TreeNode<int>* child = RecursiveInput();
			root->children.push_back(child);
		}
		return root;
	}

	TreeNode<int>* LevelWiseInput()
	{
		int rootData;
		cout << "Enter root data " << endl;
		cin >> rootData;

		TreeNode<int>* root = new TreeNode<int>(rootData);

		queue<TreeNode<int>*> q;
		q.push(root);

		while (!q.empty())
		{
			TreeNode<int>* f = q.front();
			q.pop();

			cout << "Enter num of childnre of " << f->data << endl;

			int n;
			cin >> n;

			for (int i = 1; i <= n; i++)
			{
				int childData;
				cout << "Enter " << i << "th child of " << f->data << endl;
				cin >> childData;
				
				TreeNode<int>* child = new TreeNode<int>(childData);

				q.push(child);
				f->children.push_back(child);
			}
		}
	}

	void PrintLevelOrder(TreeNode<int>* root)
	{
		queue<TreeNode<int>*> q;
		q.push(root);
		
		while (!q.empty())
		{
			TreeNode<int>* f = q.front();
			q.pop();

			cout << f->data << ": ";
			for (int i = 0; i < f->children.size(); i++)
			{
				cout << f->children[i]->data << ", ";
			}
			cout << endl;

			for (int i = 0; i < f->children.size(); i++)
			{
				q.push(f->children[i]);
			}
		}
	}
	
	int CountNodes(TreeNode<int>* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int ans = 1;
		for (int i = 0; i < root->children.size(); i++)
		{
			ans += CountNodes(root->children[i]);
		}
		return ans;
	}

	int GetHeight(TreeNode<int>* root)
	{
		if (root == NULL)
		{
			return 0;
		}

		int mx = 0;

		for (int i = 0; i < root->children.size(); i++)
		{
		
			mx = max(mx, GetHeight(root->children[i]));
		}
		return mx + 1;
	}

	void PrintTreeAtLevel(TreeNode<int>* root, int K)
	{
		if (root == NULL)
		{
			return;
		}

		if (K == 0)
		{
			cout << root->data << endl;
			return;
		}

		for (int i = 0; i < root->children.size(); i++)
		{
			PrintTreeAtLevel(root->children[i], K - 1);
		}
	}

	int CountLeafNodes(TreeNode<int>* root)
	{
		if (root == NULL)
		{
			return 0;
		}

		if (root->children.size() == 0)
		{
			return 1;
		}

		int ans = 0;
		for (int i = 0; i < root->children.size(); i++)
		{
			ans += CountLeafNodes(root->children[i]);
		}
		return ans;
	}

	void PreOrder(TreeNode<int>* root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->data << " ";

		for (int i = 0; i < root->children.size(); i++)
		{
			PreOrder(root->children[i]);
		}
	}

	void PostOrder(TreeNode<int>* root)
	{
		if (root == NULL)
		{
			return;
		}
		for (int i = 0; i < root->children.size(); i++)
		{
			PostOrder(root->children[i]);
		}
		cout << root->data << " ";
	}

	void DeleteTree(TreeNode<int>* root)
	{
		if (root == NULL)
		{
			return;
		}

		for (int i = 0; i < root->children.size(); i++)
		{
		
			DeleteTree(root->children[i]);
		}
		delete root;
	}

	// Binary Tree
	void RPrintTree(BTNode<int>* root)
	{
		if (root == NULL)
		{
			return;
		}

		cout << root->data << ": ";
		if (root->left != NULL)
		{
			cout << "L " << root->left->data;
		}
		if (root->right != NULL)
		{
			cout << "R " << root->right->data;
		}
		cout << endl;

		RPrintTree(root->left);
		RPrintTree(root->right);
	}

	BTNode<int>* BTTakeInput()
	{
		int rootData;
		cout << "Enter data " << endl;
		cin >> rootData;

		if (rootData == -1)
		{
			return NULL;
		}

		BTNode<int>* root = new BTNode<int>(rootData);
		BTNode<int>* leftChild = BTTakeInput();
		BTNode<int>* rightChild = BTTakeInput();

		root->left = leftChild;
		root->right = rightChild;
		return root;
	}
	BTNode<int>* BTTakeInputLevelWise()
	{
		int rootData;
		cout << "Enter root data " << endl;
		cin >> rootData;

		BTNode<int>* root = new BTNode<int>(rootData);
		queue<BTNode<int>*> q;
		q.push(root);

		while (!q.empty())
		{
			BTNode<int>* f = q.front();
			q.pop();

			cout << "Enter left child of " << f->data << endl;
			int leftChildData;
			cin >> leftChildData;

			if (leftChildData != -1)
			{
				BTNode<int>* child = new BTNode<int>(leftChildData);
				q.push(child);
				f->left = child;
			}

			cout << "Enter right child of " << f->data << endl;
			int rightChildData;
			cin >> rightChildData;

			if (rightChildData != -1)
			{
				BTNode<int>* child = new BTNode<int>(rightChildData);
				q.push(child);
				f->right = child;
			}
			
		}
		return root;
	}

	vector<vector<int>> LevelOrder(BTNode<int>* root)
	{
		vector<vector<int>> v;

		if (root == NULL)
		{
			return v;
		}

		vector<int> tmp;

		queue<BTNode<int>*>q;
		q.push(root);
		q.push(NULL);

		while (!q.empty())
		{
			BTNode<int>* f = q.front();
			q.pop();
			if (f == NULL)
			{
				v.push_back(tmp);
				tmp.clear();
				if (!q.empty())
				{
					q.push(NULL);
				}
			}
			else
			{
				tmp.push_back(f->data);
				if (f->left)
				{
					q.push(f->left);
				}
				if (f->right)
				{
					q.push(f->right);
				}
			}
		}
		return v;
	}

	int CountNodes(BTNode<int>* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		return CountNodes(root->left) + CountNodes(root->right) + 1;
	}

	void InOrder(BTNode<int>* root, vector<int>& ans)
	{
		if (root == NULL)
		{
			return;
		}

		InOrder(root->left, ans);
		ans.push_back(root->data);
		InOrder(root->right, ans);
	
	}
	vector<int> TraverseInOrder(BTNode<int>* root)
	{
		vector<int> ans;
		InOrder(root, ans);
		return ans;
	}

	void PreOrder(BTNode<int>* root, vector<int>& ans)
	{
		if (root == NULL)
		{
			return;
		}
		ans.push_back(root->data);
		PreOrder(root->left, ans);
		PreOrder(root->right, ans);
	}

	vector<int> TraversePreOrder(BTNode<int>* root)
	{
		vector<int> ans;
		PreOrder(root, ans);
		return ans;
	}

	void PostOrder(BTNode<int>* root, vector<int>& ans)
	{
		if (root == NULL)
		{
			return;
		}
		PostOrder(root->left, ans);
		PostOrder(root->right, ans);
		ans.push_back(root->data);
	}

	vector<int> TraversePostOrder(BTNode<int>* root)
	{
		vector<int> ans;

		PostOrder(root, ans);
		
		return ans;
	}

	int MaxDepth(BTNode<int>* root)
	{
		if (root == NULL)
		{
			return 0;
		}

		int left = MaxDepth(root->left);
		int right = MaxDepth(root->right);

		return max(left, right) + 1;
	}

	bool BTreeHelper(BTNode<int>* left, BTNode<int>* right)
	{
		if (left == NULL && right != NULL) return false;
		if (left != NULL && right == NULL) return false;
		if (left == NULL && right == NULL) return true;

		if (left->data != right->data) return false;
	
		return BTreeHelper(left->left, right->right) && BTreeHelper(left->right, right->left);
	}

	bool IsSymmetricTree(BTNode<int>* root)
	{
		if (root == NULL)
		{
			return true;
		}
		return BTreeHelper(root->left, root->right);
	}

	bool FindNode(BTNode<int>* root, int key)
	{
		if (root == NULL)
		{
			return false;
		}	
		if (root->data == key)
		{
			return true;
		}
		return (FindNode(root->left, key) || FindNode(root->right, key));
	}


	int MinimumValue(BTNode<int>* root)
	{
		if (root == NULL)
		{
			return INT_MAX;
		}

		int left_min = MinimumValue(root->left);
		int right_min = MinimumValue(root->right);

		return min(root->data, min(left_min, right_min));
	}

	int MaximumValue(BTNode<int>* root)
	{
		if (root == NULL)
		{
			return INT_MIN;
		}

		int left_max = MaximumValue(root->left);
		int right_max = MaximumValue(root->right);

		return max(root->data, max(left_max, right_max));
	}

	int CountLeafNodes(BTNode<int>* root)
	{
		if (root == NULL)
		{
			return 0;
		}

		if (root->left == NULL && root->right == NULL)
		{
			return 1;
		}

		return CountLeafNodes(root->left) + CountLeafNodes(root->right);
	
	}

};




#endif