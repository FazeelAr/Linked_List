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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    unsigned long long int num1 = 0, num2 = 0;
    ListNode* iter = l1, * iter2 = l2;
    while (iter || iter2)
    {
        if (iter)
        {
            num1 = (num1 * 10) + iter->val;
            iter = iter->next;
        }
        if (iter2)
        {
            num2 = (num2 * 10) + iter2->val;
            iter2 = iter2->next;
        }
    }
    cout << "nums  " << num1 << "  " << num2 << "\n";

    unsigned long long int tempNum1 = 0, tempNum2 = 0;
    while (num1)
    {
        tempNum1 = (tempNum1 * 10) + (num1 % 10);
        num1 = num1 / 10;
    }
    while (num2)
    {
        tempNum2 = (tempNum2 * 10) + (num2 % 10);
        num2 = num2 / 10;
    }
    unsigned long long int result = tempNum1 + tempNum2;
    cout << "result  "<<result<<"\n";
    if (result == 0)
    {
        ListNode* list = new ListNode{ 0 };
        return list;
    }
    ListNode* list = nullptr;
    int i = 0;
    ListNode* temp = list;
    //ListNode*& iter1 = list;
    while (result)
    {
        if (i == 0)
        {
            int number = result % 10;
            list = new ListNode{ number };
            i++;
            result = result / 10;
            temp = list;
        }
        else
        {
            int number = result % 10;
            list->next = new ListNode{ number };
            list = list->next;
            result = result / 10;

        }
    }
    list = temp;
    return list;
}
int main()
{
    SLList<int> list1{}, list2;
    list1.addToTail(1);
    list1.addToTail(2);
    list1.addToTail(3);
    list1.addToTail(4);
    list1.addToTail(5);
    list1.addToTail(6);
    list2.addToTail(1);
    list2.addToTail(2);
    cout << list1.getHead()->next->next->next;
    list2.addToTail(list1.getHead()->next->next);
    list1.display();
}