#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL)
    {}
};

ListNode* swapPairs(ListNode* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    ListNode *ll = NULL, *l = head, *r = l->next;
    while(r != NULL && l != NULL)
    {
        l->next = r->next;
        if(ll != NULL)
        {
            ll->next = r;
        }else{
            head = r;
        }
        r->next = l;
        ll = l;
        l = l->next;
        if(l != NULL)
        {
            r = l->next;
        }else{
            break;
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
    ListNode *result = swapPairs(root);
    p = result;
    while(p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}