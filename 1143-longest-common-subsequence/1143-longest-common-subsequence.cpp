class Solution {
public:
    int solve(string&t1, string&t2,int i1,int i2,vector<vector<int>>&dp)
    {
        if(i1<0 || i2<0)return 0;

        if(dp[i1][i2]!=-1) return dp[i1][i2];

        //match
        if(t1[i1]==t2[i2]) return dp[i1][i2]=1+solve(t1,t2,i1-1,i2-1,dp);
        //not match
        return dp[i1][i2]=max(solve(t1,t2,i1-1,i2,dp),solve(t1,t2,i1,i2-1,dp));
    }
    int longestCommonSubsequence(string t1, string t2) {

        int n=t1.size();
        int m=t2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(t1,t2,n-1,m-1,dp);
        
    }
};