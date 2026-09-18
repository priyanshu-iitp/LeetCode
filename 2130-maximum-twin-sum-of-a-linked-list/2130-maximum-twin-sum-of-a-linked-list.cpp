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
    int pairSum(ListNode* head) {

        int ans=INT_MIN;
        vector<int>nums;
        ListNode*temp=head;
        while(temp)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }

        int n=nums.size();
        for(int i=0;i<n/2;i++)
        {
            int sum=nums[i]+nums[n-1-i];
            ans=max(ans,sum);
        }

        return ans;

        
    }
};