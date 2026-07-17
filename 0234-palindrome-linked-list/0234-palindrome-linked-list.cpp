/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* revers(ListNode*temp)
    {
        ListNode*prev=NULL;
        while(temp)
        {
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {

        if(head==NULL || head->next==NULL) 
        return true;

        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next && fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;

        }


        ListNode*newhead=revers(slow->next);
        slow->next = newhead;
       
        
        ListNode*first=head;
        ListNode*second=newhead;
        while(second)
        {
            if(first->val!=second->val)
            {
                slow->next=revers(slow->next);
                return false;
            }
            else
            {
                first=first->next;
                second=second->next;
            }
        }
        slow->next=revers(slow->next);
        return true;


        
    }
};