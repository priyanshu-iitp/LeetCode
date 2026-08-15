class Solution {
public:
    // int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp)
    // {
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int mini=1e8;
    //     for(int k=i;k<=j;k++)
    //     {
    //         int cost=nums[j+1]-nums[i-1]+solve(nums,i,k-1,dp)+solve(nums,k+1,j,dp);
    //         mini=min(mini,cost);
    //     }
    //     return dp[i][j]=mini;
    // }
    int minCost(int size, vector<int>& cuts) {

        //we insert 0 at first at cuts and n at last of cuts to know the length of stick;
        int n=cuts.size();
        vector<int>nums(n+2,0);

        for(int i=0;i<n;i++)
        nums[i+1]=cuts[i];

        nums[n+1]=size;

        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {

                 if(i>j)continue;

                int mini=1e8;
                for(int k=i;k<=j;k++)
                {
                    int cost=nums[j+1]-nums[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][n];

        
        
    }
};