#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL)
    {}
};

ListNode* reverseKGroup(ListNode* head, int k)
{
    if(head == NULL || k <= 1)
    {
        return head;
    }
    ListNode **nodePoint = (ListNode**)alloca(k * sizeof(ListNode*));
    ListNode *holdHead = NULL, *holdTail = NULL, *p = head;
    int ptr = 0;
    int listPtr = 0;
    while (p != NULL)
    {
        nodePoint[listPtr++] = p;
        p = p->next;
        if(listPtr == k)
        {
            holdTail = p;
            for(int i = k - 1; i > 0; i--)
            {
                nodePoint[i]->next = nodePoint[i - 1];
            }
            nodePoint[0]->next = p;
            if(holdHead != NULL)
            {
                holdHead->next = nodePoint[k - 1];
            }else{
                head = nodePoint[k - 1];
            }
            
            holdHead = nodePoint[0];
            listPtr = 0;
        }
    }
    return head;
}

int main()
{
    ListNode *root = new ListNode(1);
    ListNode *p = root;
    for(int i = 2; i < 6; i++)
    {
        p->next = new ListNode(i);
        p = p->next;
    }
    ListNode *result = reverseKGroup(root, 3);
    p = result;
    while(p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}