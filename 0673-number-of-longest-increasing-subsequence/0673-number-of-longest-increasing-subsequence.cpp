class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);

        int maxlen=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {   
                    //copy
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=1+dp[j];
                        cnt[i]=cnt[j];
                    }
                    // another size lis found
                    else if(dp[j]+1==dp[i])
                    cnt[i]+=cnt[j];
                }
            }

            maxlen=max(maxlen,dp[i]);
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxlen)
            ans+=cnt[i];
        }

        return ans;   
    }
};