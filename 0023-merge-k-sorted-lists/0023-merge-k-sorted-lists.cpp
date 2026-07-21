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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int k=lists.size();
        if(k==0) return NULL;

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>> >p;

        for(int i=0;i<k;i++)
        {
            if(lists[i]!=NULL) p.push({lists[i]->val,lists[i]});
        }

        ListNode*dummy=new ListNode(1e9);
        ListNode*temp=dummy;

        while(!p.empty())
        {
            int data=p.top().first;
            ListNode*newnode= p.top().second;
            p.pop();


            if(newnode->next) p.push({newnode->next->val,newnode->next});

            temp->next=newnode;
            temp=newnode;
        }

        temp=dummy->next;
        delete dummy;
        return temp;
        
    }
};