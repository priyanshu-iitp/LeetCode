class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum=0;
        for(auto it:nums)
        sum+=it;

        if(sum%2==1) return false;
        
        int n=nums.size();
        int k=sum/2;

        vector<vector<bool>>dp(n,vector<bool>(k+1,0));

        for(int i=0;i<n;i++)
        dp[i][0]=true;

        if(k>=nums[0])
        dp[0][nums[0]]=true;


        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                //not pick
                bool notpick=dp[i-1][j];

                //pick
                bool pick=false;
                if(j>=nums[i])
                pick=dp[i-1][j-nums[i]];

                dp[i][j]=pick||notpick;
            }
        }
        return dp[n-1][k];
        
    }
};