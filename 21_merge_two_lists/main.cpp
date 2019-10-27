#include <iostream>
#include <stdlib.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *head = NULL;
    ListNode **pr = &head, *p1 = l1, *p2 = l2;
    if(l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    while(p1 != NULL && p2 != NULL)
    {
        *pr = new ListNode(0);
        if(p1->val <= p2->val)
        {
            (*pr)->val = p1->val;
            p1 = p1->next;
            
        }else{

            (*pr)->val = p2->val;
            p2 = p2->next;
        }
        pr = &((*pr)->next);
        
    }
    
    if(p2 != NULL)
    {
        *pr = p2;
    }else if(p1 != NULL){
        *pr = p1;
    }
    return head;
}

int main()
{

    // ListNode *aNode = NULL;
    // ListNode **bNode = &aNode;
    // *bNode = new ListNode(2);
    // if(aNode == NULL)
    // {
    //     cout << "aNode is NULL" << endl;
    // }else{
    //     cout << "aNode val = " << aNode->val << endl;
    // }
    // return 0;

    ListNode *inHead1 = new ListNode(0), *inHead2 = new ListNode(0);
    int k1[] = {1, 2, 4}, k2[] = {1, 3, 4};
    int k1Len = 3, k2Len = 3;
    ListNode* p = inHead1;
    for(int i = 0; i < k1Len; i++)
    {
        p->val = k1[i];
        if(i < k1Len - 1)
        {
            p->next = new ListNode(0);
            p = p->next;
        }
    }

    p = inHead2;
    for(int i = 0; i < k2Len; i++)
    {
        p->val = k2[i];
        if(i < k2Len - 1)
        {
            p->next = new ListNode(0);
            p = p->next;
        }
    }

    ListNode* result = mergeTwoLists(inHead1, inHead2);
    p = result;
    while(p != NULL)
    {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

}