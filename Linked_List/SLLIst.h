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
	SLList(const SLList<T>& ref): SLList()
	{
		if (!ref.head || !ref.tail)
		{
			return;
		}
		Node<T>* iter = ref.head;
		while (iter)
		{
			if (tail != nullptr)
			{
				tail->next = new Node<T>(iter->data);
				tail = tail->next;
			}
			else
			{
				tail = head = new Node<T>(iter->data);
			}
			iter = iter->next;
		}
	}
	~SLList()
	{
		while (head)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
		head = tail = nullptr;
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
	Node<T>* searchNode(T element)
	{
		Node<T>* iter = head;
		while (iter && iter->data != element)
		{
			iter = iter->next;
		}
		return (iter == nullptr) ? nullptr : iter;
	}
	void printList()
	{
		cout << '\n';
		Node<T>* iter = head;
		while (iter)
		{
			cout << iter->data << ' ';
			iter = iter->next;
		}
	}
	T removeNode(T e)
	{
		Node<T>* iter = head, *prev = head;
		while (iter && iter->data != e)
		{
			prev = iter;
			iter = iter->next;
		}
		if (iter)
		{
			T elem = iter->data;
			prev->next = iter->next;
			delete iter;
			return elem;
		}
		throw "\nElement not found";
	}
	SLList<T> doUnion(SLList<T>& list)
	{
		SLList<T> unionList{ *this };
		for (Node<T>* iter = list.getHead(); iter; iter = iter->next)
		{
			if (unionList.searchNode(iter->data) == nullptr)
			{
				unionList.addToTail(iter->data);
			}
		}
		return unionList;
	}
	void deleteAlterNodes()
	{
		for (Node<T>* iter = head; iter; iter = iter->next)
		{

		}
	}
};
#endif // !LINKED_LIST_H ;
