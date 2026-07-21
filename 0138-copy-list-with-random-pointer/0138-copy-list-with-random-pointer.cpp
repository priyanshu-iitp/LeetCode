/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node*temp=head;

        //step 1:-insert copy node between original node
        while(temp)
        {
            Node*copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;

            temp=temp->next->next;
        }

        // step 2:-connect random pointer to copy node
        temp=head;
        while(temp)
        {
            Node*copy=temp->next;
            if(temp->random) copy->random=temp->random->next;
            else copy->random=NULL;

            temp=temp->next->next;
        }

        //step 3:detach inserted copy list from original
        temp=head;
        Node*dummy=new Node(1e9);
        Node*res=dummy;
        while(temp)
        {
            res->next=temp->next;
            res=res->next; 


            temp->next=res->next;
            temp=temp->next;
        }

        temp=dummy->next;
        delete dummy;
        return temp;


        
    }
};