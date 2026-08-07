class Solution {
public:
    int solve (vector<int>&nums,int i,int k,vector<vector<int>>&dp)
    {   
        if(i==0)
        {
            if(k%nums[0]==0) return 1;
            else return 0;
        }

        if(dp[i][k]!=-1)return dp[i][k];

        int notpick=solve(nums,i-1,k,dp);
        int pick=0;
        if(k>=nums[i])
        pick=solve(nums,i,k-nums[i],dp);

        return dp[i][k]=pick+notpick;

    }
    int change(int amount, vector<int>& nums) {

        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(nums,n-1,amount,dp);
        
    }
};