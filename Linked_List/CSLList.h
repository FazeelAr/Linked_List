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
			tail = new ListNode<T>{ e };
			tail->next = tail;
		}
		else
		{
			tail->next = new ListNode<T>{ e,tail->next };
			tail = tail->next;
		}
	}
	void addToHead(T e)
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
	T deleteFromTail()
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
	T deleteFromHead()
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
	bool deleteNode(T e)
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
		ListNode<T>* iter = tail->next->next, *prev = tail;
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
	T deleteNthNode(int n)
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
	void print()
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
		}
		while (iter != tail->next);
	}
	~CSLList()
	{
		if (!tail)
		{
			return;
		}
		ListNode<T>* iter = tail->next, *temp;
		while (iter != tail)
		{
			temp = iter;
			iter = iter->next;
			delete temp;
		}
		delete tail;
		tail = nullptr;
	}
};
#endif // !CSLList_H
