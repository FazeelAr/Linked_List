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
		for (int i = 0; i < 5;i++)
		{
			cout<<list.deleteAtTail()<<'\n';
		}
	}
	catch (const char* str)
	{
		cout << str;
	}
	
}