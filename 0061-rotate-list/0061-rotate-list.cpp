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

        int len=0;
        ListNode*temp=head;
        while(temp)
        {
            temp=temp->next;
            len++;
        }
        k=k%len;
        if(k==0) return head;

        temp=head;
        ListNode*rhead=reverse(temp);
        


        temp=rhead;
        ListNode*kthnode=findnode(temp,k);

        head=kthnode;
        temp=kthnode->next;
        kthnode->next=NULL;
        reverse(rhead);

        rhead->next=reverse(temp);

        return head;
        
    }
};