#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if(k <= 1 || head == nullptr)
        return head;
    ListNode * pPreTail = nullptr;
    ListNode * pNextHead = head;
    while(true)
    {
        ListNode * pf = pNextHead, *pl = pNextHead;
        if(pf == nullptr)
            return head;
        int n = k-1;
        while(k >= 0)
        {
            if(pl->next == nullptr)
                return head;
            else
            {
                n--;
                pl = pl->next;
            }
        }
        pNextHead = pl->next;

        ListNode * p1 = pf, *p2 = pf->next, * p3 = nullptr;
        pf->next = pNextHead;
        while(p2 != pNextHead)
        {
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        if(pf == head)
        {
            head = pl;
            pPreTail = pf;
        }
        else
        {
            pPreTail ->next = pl;
            pPreTail = pf;
            pf = pNextHead;
        } 
    }
}

int main()
{
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode * pCur = head->next;
    pCur->next = new ListNode(3);
    pCur = pCur->next;
    pCur->next = new ListNode(4);
    pCur = pCur->next;
    pCur->next = new ListNode(5);
    head = reverseKGroup(head, 2);
    while(head != nullptr)
    {
        cout << head->val << " ";
        head = head -> next;
    }

    return 0;
}