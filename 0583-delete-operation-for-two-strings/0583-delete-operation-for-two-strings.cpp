class Solution {
public:
    int solve(string&s1,string&s2,int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i-1]==s2[j-1]) return dp[i][j]=1+solve(s1,s2,i-1,j-1,dp);
        return dp[i][j]= max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));
    }
    int minDistance(string s1, string s2) {

        
        int n=s1.size();
        int m=s2.size();
        //core concept :-(  n+m - 2*(logest common subsequenc) )

        //memoazation
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int lcs=solve(s1,s2,n,m,dp);

        return n+m-2*lcs;
    }
};