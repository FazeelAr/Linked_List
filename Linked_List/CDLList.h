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
	CDLList();
	~CDLList();
	bool isEmpty();
	void addToTail(T dt);
	void addToHead(T dt);
	T deleteFromHead();
	T deleteFromTail();
	bool deleteNode(T val);
	T deleteNthNode(int n);
	void print();
};
template<typename T>
CDLList<T>::CDLList()
{
	curr = nullptr;
}
template<typename T>
CDLList<T>::~CDLList()
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
template<typename T>
bool CDLList<T>::isEmpty()
{
	return curr == nullptr ? true : false;
}
template<typename T>
void CDLList<T>::addToTail(T dt)
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
template<typename T>
void CDLList<T>::addToHead(T dt)
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
template<typename T>
T CDLList<T>::deleteFromHead()
{
	if (isEmpty())
	{
		throw "\nList is Empty";
	}
	T dt = curr->data;
	if (curr->next == curr)
	{
		delete curr;
		curr = nullptr;
		return dt;
	}
	CDNode<T>* temp = curr->prev;
	curr = curr->next;
	delete curr->prev;
	temp->next = curr;
	curr->prev = temp;
	return dt;
}
template<typename T>
T CDLList<T>::deleteFromTail()
{
	if (isEmpty())
	{
		throw "\nList is Empty";
	}
	T dt = curr->prev->data;
	if (curr->prev == curr)
	{
		delete curr;
		curr = nullptr;
		return dt;
	}
	CDNode<T>* temp = curr->prev;
	curr->prev = temp->prev;
	temp->prev->next = curr;
	delete temp;
	return dt;
}
template<typename T>
bool CDLList<T>::deleteNode(T val)
{
	if (isEmpty())
	{
		return false;
	}
	if (curr->data == val)
	{
		deleteFromHead();
		return true;
	}
	CDNode<T>* iter = curr->next;
	while (iter != curr && iter->data != val)
	{
		iter = iter->next;
	}
	if (iter != curr)
	{
		iter->prev->next = iter->next;
		iter->next->prev = iter->prev;
		delete iter;
		return true;
	}
	return false;
}
template<typename T>
T CDLList<T>::deleteNthNode(int n)
{
	if (isEmpty())
	{
		throw "\nList is empty";
	}
	if (n == 1)
	{
		return deleteFromHead();
	}
	CDNode<T>* iter = curr->next;
	int i = 2;
	while (iter != curr && i != n)
	{
		iter = iter->next;
		i++;
	}
	if (iter != curr)
	{
		iter->next->prev = iter->prev;
		iter->prev->next = iter->next;
		T dt = iter->data;
		delete iter;
		return dt;
	}
	throw "Out of Bound Node";
}
template<typename T>
void CDLList<T>::print()
{
	if (isEmpty())
	{
		return;
	}
	else
	{
		cout << '\n';
		CDNode<T>* iter = curr;
		do
		{
			cout << iter->data << ' ';
			iter = iter->next;
		} while (iter != curr);
	}
}
#endif // !CDLLIST_H ;
