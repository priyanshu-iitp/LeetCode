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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int>ans(2,-1);
        ans[0]=INT_MAX;
        vector<int>idx;

        ListNode*temp=head->next;
        ListNode*prev=head;
        int i=2;

        while(temp->next)
        {
            if(temp->val>prev->val && temp->val>temp->next->val) idx.push_back(i);
            if(temp->val<prev->val && temp->val<temp->next->val) idx.push_back(i);

            prev=temp;
            temp=temp->next;
            i++;
        }

        int n=idx.size();
        if(n>=2)
        {
            for(int i=1;i<n;i++)
            {
                ans[0]=min(ans[0],idx[i]-idx[i-1]);
            }
            ans[1]=idx[n-1]-idx[0];

            return ans;
        }

        return {-1,-1};



        
    }
};