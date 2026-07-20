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

    ListNode* reverse(ListNode*temp)
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

    ListNode* findnode(ListNode*temp,int k)
    {
        k-=1;
        while(k && temp)
        {
            temp=temp->next;
            k--;
        }

        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp)
        {
            ListNode*kthnode=findnode(temp,k);
            if(kthnode==NULL)
            {
                if(prev) prev->next=temp;
                break;
            }
            ListNode*nextnode=kthnode->next;
            kthnode->next=NULL;
            reverse(temp);
            
            if(head==temp)head=kthnode;
            else prev->next=kthnode;

            prev=temp;
            temp=nextnode;
        }

        return head;
        
    }
};