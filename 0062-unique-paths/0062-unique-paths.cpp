class Solution {
public:
    int solve(int m,int n,vector<vector<int>>&dp,int row,int col)
    {
        if(row==m-1 && col==n-1)
        {
            return 1;
        }
        if(row>=m || col>=n) return 0;

        if(dp[row][col]!=-1)
        return dp[row][col];

        int right=solve(m,n,dp,row,col+1);
        int down=solve(m,n,dp,row+1,col);

        return dp[row][col]=right+down;
            
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m,n,dp,0,0);
        
    }
};