#ifndef SL_LIST_H
#define SL_LIST_H
#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	T data;
	Node* next;
	Node(T d, Node<T> * n = nullptr)
	{
		data = d;
		next = n;
	}
};
template<typename T>
class SLList
{
public:
	Node<T>* head;
	Node<T>* tail;
	SLList()
	{
		head = nullptr;
		tail = nullptr;
	}
	bool isEmpty()
	{
		return (head == nullptr && tail == nullptr) ? true : false;
	}
	void addToHead(T e)
	{
		head = new Node<T>(e, head);
		if (tail == nullptr)
		{
			tail = head;
		}
	}
	void addToTail(T e)
	{
		if (tail != nullptr)
		{
			tail->next = new Node<T>(e);
			tail = tail->next;
		}
		else
		{
			tail = head = new Node<T>(e);
		}
	}
	Node<T>* getTail()
	{
		return tail;
	}
	Node<T>* getHead()
	{
		return head;
	}
	T deleteAtHead()
	{
		if (!isEmpty())
		{
			T element = head->data;
			if (head == tail)
			{
				delete head;
				head = tail = nullptr;
				return element;
			}
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			return element;
		}
		throw "\nList is empty";
	}
	T deleteAtTail()
	{
		if (!isEmpty())
		{
			T element = tail->data;
			if (head == tail)
			{
				delete tail;
				tail = head = nullptr;
				return element;
			}
			Node<T>* temp = head, * iter = head;
			for (; temp->next != tail; temp = temp->next)
			{}
			delete tail;
			tail = temp;
			tail->next = nullptr;
			return element;
		}
		throw "\nList is Empty";
	}
	~SLList()
	{
		while (head)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
		head = nullptr;
	}
};
#endif // !LINKED_LIST_H
