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
        list.deleteNthNode(2);
        list.deleteNode(5);
        list.print();
    }
    catch (const char* s)
    {
        cout << s;
    }
}