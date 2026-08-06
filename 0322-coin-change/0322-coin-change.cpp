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
    int coinChange(vector<int>& nums, int amount) {
        
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int x=solve(nums,n-1,amount,dp);

        return x==INT_MAX?-1:x;
        
    }
};