#ifndef DLLIST_H
#define DLLIST_H
#include<iostream>
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
	DLList() :head{ nullptr }, tail{ nullptr }{}
	bool isEmpty()
	{
		return (head == nullptr && tail == nullptr) ? true : false;
	}
	void addToHead(T e)
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
	void addToTail(T e)
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
	T deleteFromTail()
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
	T deleteFromHead()
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
	void display()
	{
		DNode<T>* iter = head;
		cout << '\n';
		while (iter)
		{
			cout << iter->data << ' ';
			iter = iter->next;
		}
		cout << '\n';
	}
};
#endif // !DLLIST_H
