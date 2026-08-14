class Solution {
public:
    int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1)return dp[i][j];

        int ans=INT_MIN;
        for(int idx=i;idx<=j;idx++)
        {
            int cost=nums[i-1]*nums[idx]*nums[j+1]+solve(nums,i,idx-1,dp)+solve(nums,idx+1,j,dp);
            ans=max(ans,cost);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& arr) {

        int n=arr.size();
        vector<int>nums(n+2,1);

        for(int i=0;i<n;i++)
        nums[i+1]=arr[i];
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,1,n,dp);
        
    }
};