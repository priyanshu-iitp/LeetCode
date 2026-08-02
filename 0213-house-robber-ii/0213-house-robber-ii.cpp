class Solution {
public:
    int solve(vector<int>&nums,int i,bool flag,vector<int>&dp)
    {
        if(flag)
        {
            if(i==1) return nums[1];
            if(i<1) return 0;
        }
        else
        {
            if(i==0) return nums[0];
            if(i<0) return 0;
        }

        if(dp[i]!=-1)return dp[i];

        //pick
        int x=solve(nums,i-2,flag,dp)+nums[i];
        //notpick
        int y=solve(nums,i-1,flag,dp)+0;

        return dp[i]=max(x,y);

    }
    int rob(vector<int>& nums) {

        int n=nums.size();
        if(n==1)return nums[0];
       
        bool flag=true;
        vector<int>dp(n,-1);
        int ans1=solve(nums,n-1,flag,dp);

        flag=false;
        vector<int>dp2(n,-1);
        int ans2=solve(nums,n-2,flag,dp2);

        return max(ans1,ans2);


        
    }
};