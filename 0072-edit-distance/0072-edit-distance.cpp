class Solution {
public:
    int solve(string &s1,string&s2,int i,int j,vector<vector<int>>&dp)
    {
        if(j==0) return i;
        if(i==0) return j;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i-1]==s2[j-1]) return 0+solve(s1,s2,i-1,j-1,dp);

        int del=1+solve(s1,s2,i-1,j,dp);
        int insert=1+solve(s1,s2,i,j-1,dp);
        int rep=1+solve(s1,s2,i-1,j-1,dp);

        return dp[i][j]=min({del,insert,rep});
    }
    int minDistance(string s1, string s2) {

        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,n,m,dp);
        
    }
};