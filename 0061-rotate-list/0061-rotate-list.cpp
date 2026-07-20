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
        while(k)
        {
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL || head->next==NULL || k==0) return head;

        int len=1;
        ListNode*tail=head;
        while(tail->next)
        {
            tail=tail->next;
            len++;
        }
        k=k%len;

        if(k==0) 
        return head;

        tail->next=head;
        ListNode*temp=head;
        int x=len-k-1;
        while(x--)
        {
            temp=temp->next;
        }

        head=temp->next;
        temp->next=NULL;
        return head;
       



       




    
        
    }
};