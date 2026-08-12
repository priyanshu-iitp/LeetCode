class Solution {
public:
    // int solve(vector<int>&nums,int i,int prev,vector<vector<int>>&dp)
    // {
    //     if(i>=nums.size())return 0;
    //     if(dp[i][prev+1]!=-1)return dp[i][prev+1];

    //     //not take
    //     int nottake=0+solve(nums,i+1,prev,dp);
    //     //take
    //     int take=0;
    //     if(prev==-1 || nums[i]>nums[prev]) 
    //     take=1+solve(nums,i+1,i,dp);

    //     return dp[i][prev+1]=max(take,nottake);
    // }
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>next(n+1,0);
        vector<int>temp(n+1,0);

        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                int nottake=0+next[prev+1];
                //take
                int take=0;
                if(prev==-1 || nums[i]>nums[prev]) 
                take=1+next[i+1];

                temp[prev+1]=max(take,nottake);
            }
            next=temp;
        }
        return next[-1+1];
        
    }
};