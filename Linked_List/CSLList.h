#ifndef CSLList_H
#define CSLList_H
#include<iostream>
using namespace std;
template<typename T>
struct ListNode
{
	int val;
	ListNode() : val(0), next(nullptr) {}
	ListNode<T>* next;
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode<T>* next) : val(x), next(next) {}
};
template<typename T>
class CSLList
{
	ListNode<T>* tail;
public:
	CSLList();
	bool isEmpty();
	void addToTail(T e);
	void addToHead(T e);
	T deleteFromTail();
	T deleteFromHead();
	bool deleteNode(T e);
	T deleteNthNode(int n);
	void print();
	~CSLList();
};
template<typename T>
CSLList<T>::CSLList() :tail{ nullptr }
{}
template<typename T>
bool CSLList<T>::isEmpty()
{
	return tail == nullptr ? true : false;
}
template<typename T>
void CSLList<T>::addToTail(T e)
{
	if (isEmpty())
	{
		tail = new ListNode<T>{ e };
		tail->next = tail;
	}
	else
	{
		tail->next = new ListNode<T>{ e,tail->next };
		tail = tail->next;
	}
}
template<typename T>
void CSLList<T>::addToHead(T e)
{
	if (isEmpty())
	{
		tail = new ListNode<T>{ e };
		tail->next = tail;
	}
	else
	{
		tail->next = new ListNode<T>{ e ,tail->next };
	}
}
template<typename T>
T CSLList<T>::deleteFromTail()
{
	if (isEmpty())
	{
		throw "\nlist is empty";
	}
	if (tail->next == tail)
	{
		delete tail;
		tail = nullptr;
	}
	else
	{
		ListNode<T>* iter = tail->next;
		while (iter->next != tail)
		{
			iter = iter->next;
		}
		iter->next = tail->next;
		delete tail;
		tail = iter;
	}
}
template<typename T>
T CSLList<T>::deleteFromHead()
{
	if (isEmpty())
	{
		throw "\nList is empty";
	}
	if (tail == tail->next)
	{
		delete tail;
		tail = nullptr;
	}
	else
	{
		ListNode<T>* temp = tail->next;
		tail->next = tail->next->next;
		delete temp;
	}
}
template<typename T>
bool CSLList<T>::deleteNode(T e)
{
	if (isEmpty())
	{
		return false;
	}
	if (e == tail->val)
	{
		deleteFromTail();
		return true;
	}
	if (e == tail->next->val)
	{
		deleteFromHead();
		return true;
	}
	ListNode<T>* iter = tail->next->next, * prev = tail;
	while (iter->next != tail && iter->val != e)
	{
		prev = iter;
		iter = iter->next;
	}
	if (iter != tail)
	{
		prev->next = iter->next;
		delete iter;
		return true;
	}
	return false;
}
template<typename T>
T CSLList<T>::deleteNthNode(int n)
{
	if (isEmpty())
	{
		throw "\nList is Empty";
	}
	if (n == 1)
	{
		T dt = tail->next->val;
		deleteFromHead();
		return dt;
	}
	int i = 2;
	ListNode<T>* iter = tail->next->next, * prev = tail->next;
	while (iter != tail->next && i < n)
	{
		prev = iter;
		iter = iter->next;
		i++;
	}
	if (iter != tail->next)
	{
		T dt = iter->val;
		if (iter == tail)
		{
			tail = prev;
		}
		prev->next = iter->next;
		delete iter;
		return dt;
	}
	throw "\nOut of bound Node";
}
template<typename T>
void CSLList<T>::print()
{
	if (isEmpty())
	{
		return;
	}
	cout << '\n';
	ListNode<T>* iter = tail->next;
	do
	{
		cout << iter->val << ' ';
		iter = iter->next;
	} while (iter != tail->next);
}
template<typename T>
CSLList<T>::~CSLList()
{
	if (!tail)
	{
		return;
	}
	ListNode<T>* temp;
	while (tail->next != tail)
	{
		temp = tail->next;
		tail->next = temp->next;
		delete temp;
	}
	delete tail;
	tail = nullptr;
}
#endif // !CSLList_H
