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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        //count lenth of list;

        vector<ListNode*>ans(k,NULL);
        ListNode*temp=head;
        int cnt=0;
        while(temp)
        {
            cnt++;
            temp=temp->next;
        }
    
        
        int extra=cnt%k;
        int nonextra=k-extra;
        int elements=cnt/k;

        temp=head;
        int i=0;
            
        while(extra>0 && temp)
        {
            int n=1;
            ListNode*newhead=temp;
            ListNode*curr=temp;
            while(n!=elements+1)
            {
                curr=curr->next;
                n++;
            }
            temp=curr->next;
            curr->next=NULL;
            ans[i++]=newhead;
            extra--;
        }
            

        while(nonextra>0 && temp)
        {
            int n=1;
            ListNode*newhead=temp;
            ListNode*curr=temp;
            while(n!=elements)
            {
                curr=curr->next;
                n++;
            }
            temp=curr->next;
            curr->next=NULL;
            ans[i++]=newhead;
            nonextra--;
        }
        
        return ans;
    }
};