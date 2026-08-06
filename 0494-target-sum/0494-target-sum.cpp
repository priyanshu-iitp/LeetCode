class Solution {
public:
    int solve(vector<int>&nums,int i,int k,vector<vector<int>>&dp)
    {
        if(i==0) 
        {
            if(k==0 && nums[0] == 0) return 2;
            if (k==0 || nums[0] == k) return 1;
            return 0;
        }

        if(dp[i][k]!=-1)return dp[i][k];

        //notpick
        int notpick=solve(nums,i-1,k,dp);
        int pick=0;
        if(k>=nums[i])pick=solve(nums,i-1,k-nums[i],dp);

        return dp[i][k]=pick+notpick;

    }
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum=0;
        for(auto it:nums) sum+=it;

        int k=(sum-target)/2;
        if((sum-target)%2==1 || sum-target<0)return 0;

        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(nums,n-1,k,dp);

        
    }
};