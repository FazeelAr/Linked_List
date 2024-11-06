#include "SLList.h"
#include"DLList.h"
int main()
{
	DLList<int> list{};
	for (int i = 0; i < 5; i++)
	{
		list.addToHead(i + 5);
		list.addToTail(i + 5);
	}
	try
	{
		list.display();
		list.deleteFromHead();
		list.deleteFromTail();
		list.display();
	}
	catch (const char* str)
	{
		cout << str;
	}
}