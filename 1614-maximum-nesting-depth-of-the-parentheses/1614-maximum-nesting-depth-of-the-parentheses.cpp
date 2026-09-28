class Solution {
public:
    int maxDepth(string s) {

        int ans=0;
        int r=0;
        for(auto it:s)
        {
            if(it=='(')
            {
                r++;
                ans=max(ans,r);
            }
            else if(it==')')
            {   
               r--;
            }
        }

        return ans;
        
    }
};