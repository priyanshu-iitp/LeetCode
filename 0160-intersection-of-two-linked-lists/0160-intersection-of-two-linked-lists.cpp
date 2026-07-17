/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int cnt1=0;
        ListNode*tempA=headA;
        while(tempA)
        {
            cnt1++;
            tempA=tempA->next;
        }

        int cnt2=0;
        ListNode*tempB=headB;
        while(tempB)
        {
            cnt2++;
            tempB=tempB->next;
        }

        ListNode*first=headA;
        ListNode*sec=headB;
        if(cnt1>cnt2)
        {
            int x=cnt1-cnt2;
            while(x)
            {
                first=first->next;
                x--;
            }
        }
        else
        {
            int x=cnt2-cnt1;
            while(x)
            {
                sec=sec->next;
                x--;
            } 
        }

        while(first)
        {
            if(first==sec)
            return first;

            first=first->next;
            sec=sec->next;
        }

        return NULL;


        
    }
};