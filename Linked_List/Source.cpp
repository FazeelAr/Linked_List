#include "SLList.h"
#include<forward_list>
//int main()
//{
//	forward_list<int> list;
//	list.push_front(1);
//	for (int i = 0; i < 10; i++)
//	{
//		list.insert_after(list.end(), i + 1);
//	}
//	while (!list.empty())
//	{
//		cout << list.front() << ' ';
//		list.pop_front();
//	}
//}
int main()
{
	SLList<int> list{};
	//list.addToHead(5);
	for (int i = 0; i < 5; i++)
	{
		list.addToHead(i + 5);
	}
	try
	{
		//list.printList();
		SLList<int> list2 = list;
		cout << "\nAfter copy constructor\n";
		//cout << '\n' << list2.removeNode(11) << '\n';
		cout << "After removal\n";
		list.printList();
		list2.addToTail(3);
		list2.addToTail(5);
		list2.addToTail(4);
		list2.printList();
		list.doUnion(list2).printList();
	}
	catch (const char* str)
	{
		cout << str;
	}
	
}