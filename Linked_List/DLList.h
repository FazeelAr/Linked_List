#ifndef DLLIST_H
#define DLLIST_H
#include<iostream>
#include<vector>
using namespace std;
template<typename T>
struct DNode
{
	T data;
	DNode<T>* next;
	DNode<T>* prev;
	DNode(T d, DNode<T>* n = nullptr, DNode<T>* p = nullptr)
	{
		data = d;
		next = n;
		prev = p;
	}
};
template<typename T>
class DLList
{
	DNode<T>* head;
	DNode<T>* tail;
public:
	DLList();
	DLList(const DLList<T>& ref);
	~DLList();
	bool isEmpty()const;
	void addToHead(T e);
	void addToTail(T e);
	T deleteFromTail();
	T deleteFromHead();
	void display()const;
	bool deleteNode(T e);
	bool deleteNthNode(int n);
};
template<typename T>
DLList<T>::DLList() :head{ nullptr }, tail{ nullptr } 
{}
template<typename T>
bool DLList<T>::isEmpty()const
{
	return (head == nullptr && tail == nullptr) ? true : false;
}
template<typename T>
DLList<T>::DLList(const DLList<T>& ref)
{
	if (ref.isEmpty())
	{
		return;
	}
	DNode<T>* iter = ref.head;
	while (iter)
	{
		addToTail(iter->data);
		iter = iter->next;
	}
}
template<typename T>
void DLList<T>::addToHead(T e)
{
	if (head == nullptr)
	{
		head = tail = new DNode<T>(e);
	}
	else
	{
		head = new DNode<T>{ e,head };
		head->next->prev = head;
	}
}
template<typename T>
void DLList<T>::addToTail(T e)
{
	if (tail == nullptr)
	{
		head = tail = new DNode<T>(e);
	}
	else
	{
		tail = new DNode<T>{ e,nullptr,tail };
		tail->prev->next = tail;
	}
}
template<typename T>
T DLList<T>::deleteFromTail()
{
	if (isEmpty())
	{
		throw "\nList is empty";
	}
	T e = tail->data;
	if (head == tail)
	{
		delete tail;
		tail = head = nullptr;
		return e;
	}
	tail = tail->prev;
	delete tail->next;
	tail->next = nullptr;
}
template<typename T>
T DLList<T>::deleteFromHead()
{
	if (isEmpty())
	{
		throw "\nList is empty";
	}
	T e = head->data;
	if (head == tail)
	{
		delete head;
		tail = head = nullptr;
		return e;
	}
	head = head->next;
	delete head->prev;
	head->prev = nullptr;
}
template<typename T>
void DLList<T>::display()const
{
	if (isEmpty())
	{
		return;
	}
	DNode<T>* iter = head;
	cout << '\n';
	while (iter)
	{
		cout << iter->data << ' ';
		iter = iter->next;
	}
	cout << '\n';
}
template<typename T>
bool DLList<T>::deleteNode(T e)
{
	if (head == nullptr)
	{
		return false;
	}
	if (head->data == e)
	{
		deleteFromHead();
		return true;
	}
	DNode<T>* iter = head;
	while (iter && iter->data != e)
	{
		iter = iter->next;
	}
	if (iter)
	{
		if (iter == tail)
		{
			deleteFromTail();
			return true;
		}
		iter->prev->next = iter->next;
		iter->next->prev = iter->prev;
		return true;
	}
	return false;
}
template<typename T>
bool DLList<T>::deleteNthNode(int n)
{
	if (n <= 0)
		return false;
	if (n == 1)
	{
		deleteFromHead();
		return true;
	}
	int i = 1;
	DNode<T>* iter = head->next;
	while (iter && i != n)
	{
		iter = iter->next;
		i++;
	}
	if (iter)
	{
		if (iter == tail)
		{
			deleteFromTail();
			return true;
		}
		iter->prev->next = iter->next;
		iter->next->prev = iter->prev;
		return true;
	}
	return false;
}
template<typename T>
DLList<T>::~DLList()
{
	if (isEmpty())
	{
		return;
	}
	DNode<T>* iter = head;
	while (iter->next)
	{
		DNode<T>* temp = iter;
		iter = iter->next;
		delete temp;
	}
	head = tail = nullptr;
}
#endif // !DLLIST_H
