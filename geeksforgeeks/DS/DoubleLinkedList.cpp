#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node *next;
	Node *prev;
};

// add elmement at the head
void push(Node **head, int new_data)
{
	Node *new_node = new Node;

	new_node->data = new_data;

	new_node->next = *head;
	new_node->prev = nullptr;

	if (*head != nullptr)
		(*head)->prev = new_node;

	*head = new_node;
}

// add element after given node
void insertAfter(Node *prev_node, int new_data)
{
	if (prev_node == nullptr)
	{
		cout << "The given previous node cannot be NULL!"
				 << "\n";
		return;
	}

	Node *new_node = new Node;

	new_node->data = new_data;

	new_node->next = prev_node->next;

	prev_node->next = new_node;

	new_node->prev = prev_node;

	if (new_node->next != nullptr)
		new_node->next->prev = new_node;
}

// add element at the tail
void append(Node **head, int new_data)
{
	Node *new_node = new Node;

	Node *last = *head;

	new_node->data = new_data;

	new_node->next = nullptr;

	if (*head == nullptr)
	{
		new_node->prev = nullptr;
		*head = new_node;
		return;
	}

	while (last->next != nullptr)
		last = last->next;

	last->next = new_node;

	new_node->prev = last;

	return;
}

void printList(Node *node)
{
	cout << "Traversal in forward direction"
			 << "\n";

	while (node != nullptr)
	{
		cout << node->data << "\n";
		node = node->next;
	}
}

int main()
{
	Node *head = nullptr;

	push(&head, 55);

	insertAfter(head, 8);

	insertAfter(head->next, 85);

	append(&head, 633);

	printList(head);

	return 0;
}