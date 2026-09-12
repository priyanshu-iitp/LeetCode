class Solution {
public:
    int minimumRecolors(string nums, int k) {

        int n=nums.size();
        int ans=INT_MAX;

        int l=0,r=0;
        int x=0;
        while(r<n)
        {
            if(nums[r]=='W') x++;

            if(r-l+1>k)
            {
                if(nums[l]=='W')
                x--;
                l++;
            }

            if(r-l+1==k) ans=min(ans,x);

            r++;
        }

        return ans;
        
    }
};