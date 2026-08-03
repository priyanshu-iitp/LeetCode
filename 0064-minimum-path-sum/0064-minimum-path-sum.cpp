class Solution {
public:
    int solve(vector<vector<int>>&nums,int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 && j==0)return nums[0][0];
        if(i<0 || j<0) return 1e9;

        if(dp[i][j]!=-1)return dp[i][j];

        int up=nums[i][j]+solve(nums,i-1,j,dp);
        int left=nums[i][j]+solve(nums,i,j-1,dp);

        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& nums) {

        int m=nums.size();
        int n=nums[0].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(nums,m-1,n-1,dp);
        
    }
};