#include "SLList.h"
int main()
{
	SLList<int> list{};
	//list.addToHead(5);
	for (int i = 0; i < 5; i++)
	{
		list.addToHead(i + 5);
		list.addToTail(i + 5);
	}
	try
	{
		list.deleteAtTail();
		for (Node<int>* temp = list.getHead(); temp; temp = temp->next)
		{
			cout << temp->data << ' ';
		}
	}
	catch (const char* str)
	{
		cout << str;
	}
	
}