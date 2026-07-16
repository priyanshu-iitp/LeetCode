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

        int l=0,r=0;
        int ans=0,cnt=0;
        int z=0;
        while(r<n)
        {
           if(nums[r]==0) z++;
           else 
           {    
                cnt++;
                ans=max(ans,cnt);
           }

           while(z>1)
           {
                if(nums[l]==1)cnt--;
                else z--;
                l++;
           }

            
            r++;
        }
        return max(ans,cnt);
        
    }
};