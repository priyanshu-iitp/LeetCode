class Solution {
public:
    int solve(vector<int>&nums,int i,int buy,vector<vector<int>>&dp)
    {
        if(i==nums.size()) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit=INT_MIN;
        if(buy)
        {
            int purchage=-nums[i]+solve(nums,i+1,0,dp);
            int notpurchage=0+solve(nums,i+1,1,dp);

            profit=max(purchage,notpurchage);
        }
        else
        {
            int sold=nums[i]+solve(nums,i+1,1,dp);
            int notsold=solve(nums,i+1,0,dp);

            profit=max(sold,notsold);
        }

        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {

        int buy=1;
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return solve(prices,0,buy,dp);
        
    }
};