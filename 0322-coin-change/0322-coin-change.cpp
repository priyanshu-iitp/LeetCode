class Solution {
public:

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