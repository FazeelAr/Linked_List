#include "SLList.h"
#include"DLList.h"
struct ListNode 
{
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
int main()
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

}