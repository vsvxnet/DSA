#ifndef Node_H
#define Node_H
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

#endif;
