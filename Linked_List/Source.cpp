#include"CDLList.h"
int main()
{
    try
    {
        CDLList<int> list{};
        list.addToHead(7);
        list.addToHead(6);
        list.addToHead(5);
        list.addToHead(4);
        list.addToHead(3);
        list.addToHead(2);
        list.addToHead(1);
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
        //cout << '\n' << list.deleteNthNode(10);
        //list.print();
    }
    catch (const char* s)
    {
        cout << s;
    }
}