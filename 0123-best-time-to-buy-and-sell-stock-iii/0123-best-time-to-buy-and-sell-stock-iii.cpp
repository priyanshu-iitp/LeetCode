class Solution {
public:
    // int solve(vector<int>&nums,int i,int buy,int atmost,vector<vector<vector<int>>>&dp)
    // {
    //     if(atmost==0) return 0;
    //     if(i==nums.size()) return 0;

    //     if(dp[i][buy][atmost]!=-1) return dp[i][buy][atmost];

    //     int profit=INT_MIN;
    //     //buy
    //     if(buy)
    //     {
    //         int purchase=-nums[i]+solve(nums,i+1,0,atmost,dp);
    //         int notpurchase=0+solve(nums,i+1,1,atmost,dp);

    //         profit=max(purchase,notpurchase);
    //     }
    //     //not buy;
    //     else
    //     {
    //         int sold=nums[i]+solve(nums,i+1,1,atmost-1,dp);
    //         int notsold=solve(nums,i+1,0,atmost,dp);

    //         profit=max(sold,notsold);
    //     }

    //     return dp[i][buy][atmost]=profit;
    // }
    int maxProfit(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>prev(2,vector<int>(3,0));
        vector<vector<int>>temp(2,vector<int>(3,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                for(int atmost=1;atmost<3;atmost++)
                {
                    int profit=INT_MIN;
                    //buy
                    if(buy)
                    {
                        int purchase=-nums[i]+prev[0][atmost];
                        int notpurchase=0+prev[1][atmost];

                        profit=max(purchase,notpurchase);
                    }
                    //not buy;
                    else
                    {
                        int sold=nums[i]+prev[1][atmost-1];
                        int notsold=prev[0][atmost];

                        profit=max(sold,notsold);
                    }

                    temp[buy][atmost]=profit;
                }
            }

            prev=temp;
        }


        return prev[1][2];
        
    }
};