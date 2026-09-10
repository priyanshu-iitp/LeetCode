/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void sub(TreeNode*root,int&sum,int&n)
    {
        if(root==NULL)
        return ;
        
        //nlr
        sum+=root->val;
        n=n+1;
        sub(root->left,sum,n);
        sub(root->right,sum,n);
    }

    int averageOfSubtree(TreeNode* root) {
        
        if(root==NULL)
        return 0;

        int sum=0;
        int n=0;
        sub(root,sum,n);
        if(sum/n==root->val)
        { 
            return 1+averageOfSubtree(root->left)+averageOfSubtree(root->right);
        }
        else 
        {
            return 0+averageOfSubtree(root->left)+averageOfSubtree(root->right);
        }
    }
};