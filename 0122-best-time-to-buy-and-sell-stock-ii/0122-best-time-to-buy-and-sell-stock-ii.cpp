class Solution {
public:
    int maxProfit(vector<int>& nums) {

        int buy=1;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        dp[n][0]=0;
        dp[n][1]=0;

        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                int profit=INT_MIN;
                if(buy)
                {
                    int purchage=-nums[i]+dp[i+1][0];
                    int notpurchage=0+dp[i+1][1];

                    profit=max(purchage,notpurchage);
                }
                else
                {
                    int sold=nums[i]+dp[i+1][1];
                    int notsold=dp[i+1][0];

                    profit=max(sold,notsold);
                }

                dp[i][buy]=profit;
            }
        }

        return dp[0][buy];
        
    }
};