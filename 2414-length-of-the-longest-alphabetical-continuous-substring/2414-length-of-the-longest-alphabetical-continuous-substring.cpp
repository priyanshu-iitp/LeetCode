class Solution {
public:
    int longestContinuousSubstring(string s) {

        int n=s.size();
        int ans=1;

        int l=0,r=1;
        char c=s[l];

        while(r<n)
        {
            if(s[r]==c+1)
            {
                c=s[r];
            }
            else
            {
                l=r;
                c=s[l];
            }

            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
        
    }
};