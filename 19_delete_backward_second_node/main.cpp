#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *beforeTarget = NULL;
    ListNode *target = NULL;
    ListNode *ptrNode = head;
    int count = 0;
    while (ptrNode != NULL)
    {
        if (target == NULL)
        {
            if (n - 1 == count)
            {
                target = head;
            }
        }
        else
        {
            beforeTarget = target;
            target = target->next;
        }
        ptrNode = ptrNode->next;
        count++;
    }

    if (target == NULL)
    {
        return head;
    }
    else
    {
        if (beforeTarget == NULL)
        {
            return target->next;
        }
        else
        {
            beforeTarget->next = target->next;
            target->next = NULL;
            return head;
        }
    }
}

int main()
{
    int k[] = {1, 2, 3, 4, 5};
    int kLen = 5;
    ListNode *head = new ListNode(k[0]);
    ListNode *pNode = head;
    for (int i = 1; i < kLen; i++)
    {
        pNode->next = new ListNode(k[i]);
        pNode = pNode->next;
    }

    ListNode *result = removeNthFromEnd(head, 5);
    pNode = result;
    while (pNode != NULL)
    {
        cout << pNode->val << ", ";
        pNode = pNode->next;
    }
    return 0;
}