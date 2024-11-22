#include "SLList.h"
#include"DLList.h"
#include"CSLList.h"
int main()
{
    try
    {
        /*SLList<int> list1{}, list2;
        list1.addToTail(1);
        list1.addToTail(2);
        list1.addToTail(3);
        list1.addToTail(4);
        list1.addToTail(5);
        list1.addToTail(6);
        list2.addToTail(1);
        list2.addToTail(2);*/
        //cout << list1.getHead()->next->next->next;
        //list2.addToTail(list1.getHead()->next->next);
        //list1.display();
        CSLList<int> list{};
        list.addToHead(1);
        list.addToHead(2);
        list.addToHead(3);
        list.addToHead(4);
        list.addToHead(5);
        list.addToHead(6);
        list.addToHead(7);
        list.addToTail(8);
        list.addToTail(9);
        list.addToTail(10);
        list.print();
        /*list.deleteFromTail();
        list.deleteFromTail();
        list.deleteFromTail();
        list.deleteFromTail();
        list.deleteFromHead();
        list.deleteFromHead();
        list.deleteFromHead();*/
        cout << '\n' << list.deleteNthNode(10);
        list.print();
    }
    catch (const char* s)
    {
        cout << s;
    }
}