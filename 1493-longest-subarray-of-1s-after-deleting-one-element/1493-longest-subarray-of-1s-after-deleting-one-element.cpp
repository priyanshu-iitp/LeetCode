class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n=nums.size();
        int zero=0;
        int ones=0;
        for(auto it:nums)
        {
            if(it==0) zero++;
            else ones++;
        }

        if(zero==n) return 0;
        else if(ones==n) return n-1;

        int l=-1,r=0;
        int ans=0,cnt=0;
        while(r<n)
        {
           if(nums[r]==0) 
           {
                ans=max(ans,cnt);
                cnt=r-l-1;
                l=r;
           }
           else cnt++;

            
            r++;
        }
        return max(ans,cnt);
        
    }
};