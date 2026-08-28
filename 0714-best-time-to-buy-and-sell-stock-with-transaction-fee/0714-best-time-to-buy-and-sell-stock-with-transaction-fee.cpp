class Solution {
public:
    // int solve(vector<int>&nums,int i,int buy,int fee,vector<vector<int>>&dp)
    // {
    //     if(i==nums.size()) return 0;
    //     if(dp[i][buy]!=-1) return dp[i][buy];

    //     int profit=INT_MIN;
    //     if(buy)
    //     {
    //         int pur=-nums[i]+solve(nums,i+1,0,fee,dp);
    //         int notpur=solve(nums,i+1,1,fee,dp);

    //         profit=max(pur,notpur);
    //     }
    //     else
    //     {
    //         int sold=nums[i]-fee+solve(nums,i+1,1,fee,dp);
    //         int notsold=solve(nums,i+1,0,fee,dp);

    //         profit=max(sold,notsold);
    //     }

    //     return dp[i][buy]=profit;
    // }
    int maxProfit(vector<int>& nums, int fee) {

        int n=nums.size();
        vector<int>prev(2,0);
        vector<int>temp(2,0);

        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                int profit=INT_MIN;
                if(buy)
                {
                    int pur=-nums[i]+prev[0];
                    int notpur=prev[1];

                    profit=max(pur,notpur);
                }
                else
                {
                    int sold=nums[i]-fee+prev[1];
                    int notsold=prev[0];

                    profit=max(sold,notsold);
                }

                temp[buy]=profit;
            }
            prev=temp;
        }
        return prev[1];
        
    }
};