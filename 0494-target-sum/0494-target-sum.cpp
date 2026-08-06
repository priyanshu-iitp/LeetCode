class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum=0;
        for(auto it:nums) sum+=it;

        int k=(sum-target)/2;
        if((sum-target)%2==1 || sum-target<0)return 0;

        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,0));

        for(int i=0;i<=k;i++)
        {
            if(i==0 && nums[0] == 0) dp[0][i]=2;
            else if (i==0 || nums[0] == i) dp[0][i]=1;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                //notpick
                int notpick=dp[i-1][j];
                int pick=0;
                if(j>=nums[i])pick=dp[i-1][j-nums[i]];

                dp[i][j]=pick+notpick;
            }
        }
        return dp[n-1][k];

        
    }
};