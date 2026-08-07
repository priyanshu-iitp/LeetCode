class Solution {
public:
    int change(int k, vector<int>& nums) {

        int n=nums.size();
        vector<vector<long long >>dp(n,vector<long long >(k+1,0));

        for(int i=0;i<=k;i++)
        {
            if(i%nums[0]==0) dp[0][i]=1;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                int notpick=dp[i-1][j];
                int pick=0;
                if(j>=nums[i])
                pick=dp[i][j-nums[i]];

                dp[i][j]=(1ll*pick+notpick);
            }
        }
        return dp[n-1][k];
        
    }
};