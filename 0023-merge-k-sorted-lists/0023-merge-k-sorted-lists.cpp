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
    ListNode* mergesort(ListNode*left,ListNode*right)
    {
        ListNode* dummy=new ListNode(1e9);
        ListNode*temp=dummy;
        while(left && right)
        {
            if(left->val<right->val)
            {
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else
            {
                temp->next=right;
                temp=right;
                right=right->next;
            }

        }
        if(left) temp->next=left;
        if(right) temp->next=right;

        temp=dummy->next;
        delete dummy;
        return temp;
    }
  
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0) return NULL;
        
        ListNode*head=lists[0];
        for(int i=1;i<lists.size();i++)
        {
            head=mergesort(head,lists[i]);
        }
        return head;


        
    }
};