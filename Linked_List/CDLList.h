#ifndef CDLLIST_H
#define CDLLIST_H
#include<iostream>
using namespace std;
template<typename T>
struct CDNode
{
	T data;
	CDNode<T>* next;
	CDNode<T>* prev;
	CDNode(T dt, CDNode<T>* nt = nullptr, CDNode<T>* pr = nullptr)
	{
		data = dt;
		next = nt;
		prev = pr;
	}
};
template<typename T>
class CDLList
{
	CDNode<T>* curr;
public:
	CDLList()
	{
		curr = nullptr;
	}
	~CDLList()
	{
		if (isEmpty())
		{
			return;
		}
		CDNode<T>* temp = curr;
		do
		{
			CDNode<T>* del = curr;
			curr = curr->next;
			delete del;
		} while (curr != temp);
		curr = nullptr;
	}
	bool isEmpty()
	{
		return curr == nullptr ? true : false;
	}
	void addToTail(T dt)
	{
		if (isEmpty())
		{
			curr = new CDNode<T>{ dt };
			curr->next = curr->prev = curr;
		}
		else
		{
			curr->prev = new CDNode<T>{ dt,curr,curr->prev };
			curr->prev->prev->next = curr->prev;
		}
	}
	void addToHead(T dt)
	{
		if (isEmpty())
		{
			curr = new CDNode<T>{ dt };
			curr->next = curr->prev = curr;
		}
		else
		{
			curr = new CDNode<T>{ dt,curr,curr->prev };
			curr->next->prev = curr;
			curr->prev->next = curr;
		}
	}
	void print()
	{
		if (isEmpty())
		{
			return;
		}
		else
		{
			cout << '\n';
			CDNode<T> *iter = curr;
			do
			{
				cout << iter->data << ' ';
				iter = iter->next;
			} 
			while (iter != curr);
		}
	}
};
#endif // !CDLLIST_H
