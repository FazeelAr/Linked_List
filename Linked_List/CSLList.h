#ifndef CSLList_H
#define CSLList_H
#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node(T dt, Node<T>* nt = nullptr)
	{
		data = dt;
		next = nt;
	}
};
template<typename T>
class CSLList
{
	Node<T>* tail;
public:
	CSLList() :tail{ nullptr }
	{}
	bool isEmpty()
	{
		return tail == nullptr ? true : false;
	}
	void addToTail(T e)
	{
		if (isEmpty())
		{
			tail = new Node<T>{ e };
			tail->next = tail;
		}
		else
		{
			tail = new Node<T>{ e,tail->next };
			tail = tail->next;
		}
	}
	void addToHead(T e)
	{
		if (isEmpty())
		{
			tail = new Node<T>{ e };
			tail->next = tail;
		}
		else
		{
			tail->next = new Node<T>{ e ,tail->next };
		}
	}
};
#endif // !CSLList_H
