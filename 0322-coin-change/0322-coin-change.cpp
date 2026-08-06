class Solution {
public:
    int solve(vector<int>&nums,int i,int k,vector<vector<int>>&dp)
    {
        if(i==0)
        {
            if(k%nums[i]==0)
            return k/nums[i];
            else return INT_MAX;
        }
        if(dp[i][k]!=-1)return dp[i][k];

       int notpick=solve(nums,i-1,k,dp);
       int pick=INT_MAX;
       if(k>=nums[i]) 
       {
            int x=solve(nums,i,k-nums[i],dp);
            if(x!=INT_MAX)
            pick=1+x;
       }

       return dp[i][k]=min(pick,notpick);
    }
    int coinChange(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,1e8));

        for(int i=0;i<=k;i++)
        {
            if(i%nums[0]==0)
            dp[0][i]=i/nums[0];
        }


        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                int notpick=dp[i-1][j];
                int pick=1e8;
                if(j>=nums[i]) 
                {
                        int x=dp[i][j-nums[i]];
                        pick=1+x;
                }

                dp[i][j]=min(pick,notpick);
            }
        }

        return dp[n-1][k]==1e8?-1:dp[n-1][k];






       
        
    }
};