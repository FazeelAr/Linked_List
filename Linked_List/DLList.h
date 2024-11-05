#ifndef DLLIST_H
#define DLLIST_H
template<typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node(T d, Node<T>* n = nullptr, Node<T>* p = nullptr)
	{
		data = d;
		next = n;
		prev = p;
	}
};
template<typename T>
class DLList
{
	Node<T>* head;
	Node<T>* tail;
public:
	DLList() :head{ nullptr }, tail{ nullptr }{}
	void addToHead(T e)
	{
		if (head == nullptr)
		{
			head = tail = new Node<T>(e);
		}
		else
		{
			head = new Node<T>{ e,head };
			head->next->prev = head;
		}
	}
	void addToTail(T e)
	{
		if (tail == nullptr)
		{
			head = tail = new Node<T>(e);
		}
		else
		{
			tail = new Node<T>{ e,nullptr,tail };
			tail->prev->next = tail;
		}
	}
	T deleteFromTail()
	{
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
};
#endif // !DLLIST_H
