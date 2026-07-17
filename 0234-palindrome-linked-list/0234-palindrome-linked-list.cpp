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
    bool isPalindrome(ListNode* head) {

        if(head==NULL || head->next==NULL) 
        return true;

        ListNode*slow=head;
        ListNode*fast=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;

        }

        //for odd length
        if(fast) slow=slow->next;

        ListNode*temp=NULL;
        while(slow)
        {
            ListNode*front=slow->next;
            slow->next=temp;
            temp=slow;
            slow=front;
        }
       
        
        ListNode*p1=temp;
        ListNode*p2=head;
        while(p1)
        {
            if(p1->val!=p2->val)return false;
            else
            {
                p1=p1->next;
                p2=p2->next;
            }
        }
        return true;


        
    }
};