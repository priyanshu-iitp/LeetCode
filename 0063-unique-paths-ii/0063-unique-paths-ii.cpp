class Solution {
public:

    int solve(vector<vector<int>>&nums,int i,int j,vector<vector<int>>&dp)
    {
        //base case;
        if(i>=0 && j>=0 && nums[i][j]==1)return 0;
        if(i==0 && j==0)return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        int up=solve(nums,i-1,j,dp);
        int left=solve(nums,i,j-1,dp);

        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>&nums) {

        int m=nums.size();
        int n=nums[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(nums,m-1,n-1,dp);
        
    }
};