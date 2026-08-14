class Solution {
public:
    // int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp)
    // {
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];

    //     int ans=INT_MIN;
    //     for(int idx=i;idx<=j;idx++)
    //     {
    //         int cost=nums[i-1]*nums[idx]*nums[j+1]+solve(nums,i,idx-1,dp)+solve(nums,idx+1,j,dp);
    //         ans=max(ans,cost);
    //     }
    //     return dp[i][j]=ans;
    // }
    int maxCoins(vector<int>& arr) {

        int n=arr.size();
        vector<int>nums(n+2,1);

        for(int i=0;i<n;i++)
        nums[i+1]=arr[i];
        
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>=1;i--)
        {
            for(int j=i;j<=n;j++)
            {
                if(i>j) continue;
                
                int ans=INT_MIN;
                for(int idx=i;idx<=j;idx++)
                {
                    int cost=nums[i-1]*nums[idx]*nums[j+1]+dp[i][idx-1]+dp[idx+1][j];
                    ans=max(ans,cost);
                }
                dp[i][j]=ans;

            }
        }
        return dp[1][n];
        
    }
};