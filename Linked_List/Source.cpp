#include "SLList.h"
#include<forward_list>
int main()
{
	SLList<int> list{};
	for (int i = 0; i < 5; i++)
	{
		for(int j = 0; j<2;j++)
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
		//list2.printList();
		cout << list.removeNode(9);
		list.removeNode(9);
		list.removeNode(9);
		list.removeNode(9);
		//list = list.doUnion(list2);
		//list.printList();
		//list2.removeDuplicates();
		cout << "\nAfter deleteing alternate nodes";
		list.printList();
	}
	catch (const char* str)
	{
		cout << str;
	}
	
}