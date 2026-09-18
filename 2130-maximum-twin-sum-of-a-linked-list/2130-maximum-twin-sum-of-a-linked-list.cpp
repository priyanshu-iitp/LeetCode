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
    ListNode* reverse(ListNode* head)
    {
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(curr)
        {
            ListNode*temp=curr;
            curr=curr->next;
            temp->next=prev;
            prev=temp;
        }

        return prev;
    }
    int pairSum(ListNode* head) {

        ListNode*prev=NULL;
        ListNode*slow=head;
        ListNode*fast=head;

        while(fast)
        {
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }

        prev->next=reverse(slow);

        prev=prev->next;
        int ans=INT_MIN;
        ListNode*temp=head;
        while(prev)
        {
            int sum=temp->val+prev->val;
            ans=max(ans,sum);
            temp=temp->next;
            prev=prev->next;
        }

        return ans;

        
    }
};