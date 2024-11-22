#ifndef SL_LIST_H
#define SL_LIST_H
#include<iostream>
#include<vector>
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
	Node<T>* head;
	Node<T>* tail;
public:
	SLList();
	SLList(const SLList<T>& ref);
	~SLList();
	bool isEmpty();
	void addToHead(T e);
	void addToTail(Node<T>* p);
	void addToTail(T e);
	Node<T>* getTail();
	Node<T>* getHead();
	T deleteAtHead();
	T deleteAtTail();
	Node<T>* searchNode(T element);
	void display();
	bool removeNode(T e);
	SLList<T> doUnion(SLList<T>& list);
	void deleteAlterNodes();
	void removeDuplicates();
	void reverseList();
	bool isJoining(SLList<T>& list);
};

template<typename T>
SLList<T>::SLList()
{
	head = nullptr;
	tail = nullptr;
}

template<typename T>
SLList<T>::SLList(const SLList<T>& ref) : SLList()
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

template<typename T>
SLList<T>::~SLList()
{
	while (head)
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	head = tail = nullptr;
}

template<typename T>
bool SLList<T>::isEmpty()
{
	return (head == nullptr && tail == nullptr) ? true : false;
}

template<typename T>
void SLList<T>::addToHead(T e)
{
	head = new Node<T>(e, head);
	if (tail == nullptr)
	{
		tail = head;
	}
}

template<typename T>
void SLList<T>::addToTail(T e)
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

template<typename T>
void SLList<T>::addToTail(Node<T>* p)
{
	if (isEmpty())
	{
		tail = head = p;
		return;
	}
	//cout << p->data << '\n';
	tail->next = p;
	/*Node<T>* iter = p;
	while (iter)
	{
		iter = iter->next;
	}
	tail = iter;*/
}
template<typename T>
Node<T>* SLList<T>::getTail()
{
	return tail;
}

template<typename T>
Node<T>* SLList<T>::getHead()
{
	return head;
}

template<typename T>
T SLList<T>::deleteAtHead()
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

template<typename T>
T SLList<T>::deleteAtTail()
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
		{
		}
		delete tail;
		tail = temp;
		tail->next = nullptr;
		return element;
	}
	throw "\nList is Empty";
}

template<typename T>
Node<T>* SLList<T>::searchNode(T element)
{
	Node<T>* iter = head;
	while (iter && iter->data != element)
	{
		iter = iter->next;
	}
	return (iter == nullptr) ? nullptr : iter;
}

template<typename T>
void SLList<T>::display()
{
	cout << '\n';
	Node<T>* iter = head;
	while (iter)
	{
		cout << iter->data << ' ';
		iter = iter->next;
	}
}

template<typename T>
bool SLList<T>::removeNode(T e)
{
	if (isEmpty())
	{
		return false;
	}
	if (head->data == e)
	{
		deleteAtHead();
		return true;
	}
	Node<T>* iter = head->next, * prev = head;
	while (iter && iter->data != e)
	{
		prev = prev->next;
		iter = iter->next;
	}
	if (iter)
	{
		prev->next = iter->next;
		delete iter;
		return true;
	}
	return false;
}

template<typename T>
SLList<T> SLList<T>::doUnion(SLList<T>& list)
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

template<typename T>
void SLList<T>::deleteAlterNodes()
{
	Node<T>* iter = head;
	while (iter && iter->next)
	{
		Node<T>* prev = iter->next;
		iter->next = iter->next->next;
		delete prev;
		iter = iter->next;
	}
}

template<typename T>
void SLList<T>::removeDuplicates()
{
	Node<T>* curr = head;
	while (curr)
	{
		Node<T>* next = curr;
		while (next->next)
		{
			if (curr->data == next->next->data)
			{
				Node<T>* duplicate = next->next;
				next->next = next->next->next;
				delete duplicate;
			}
			else
			{
				next = next->next;
			}
		}
		curr = curr->next;
	}
}

template<typename T>
void SLList<T>::reverseList()
{
	if (!head)
	{
		return;
	}
	Node<T>* iter = head;
	vector<Node<T>*> add;
	while (iter != tail)
	{
		add.push_back(iter);
		iter = iter->next;
	}
	iter = tail;
	Node<T>* temp = head;
	int i = add.size() - 1;
	for (int i = add.size() - 1; i >= 0; i--)
	{
		iter->next = add[i];
		iter = iter->next;
	}
	head = tail;
	tail = iter;
	tail->next = nullptr;
}

template<typename T>
bool SLList<T>::isJoining(SLList<T>& list)
{
	if (list.isEmpty()||!head)
	{
		return false;
	}
	Node<T>* iter1 = head, *iter2 = list.head;
	while (iter2!=iter1)
	{
		iter1 = iter1->next;
		iter2 = iter2->next;
		if (!iter1 && !iter2)
		{
			return false;
		}
		if (iter1 == nullptr)
		{
			iter1 = list.head;
		}
		if (iter2 == nullptr)
		{
			iter2 = head;
		}
	}
	return true;
}
#endif // !LINKED_LIST_H ;
