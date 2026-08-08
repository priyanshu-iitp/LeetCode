class Solution {
public:
    int solve (string&s,string&s2,int i,int j,vector<vector<int>>&dp)
    {
        if(i==0 || j==0)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        //match
        if(s[i-1]==s2[j-1]) return dp[i][j]=1+solve(s,s2,i-1,j-1,dp);
        //mot matcj
        return dp[i][j]=max(solve(s,s2,i-1,j,dp),solve(s,s2,i,j-1,dp));
    }
    int longestPalindromeSubseq(string s) {

        string s2=s;
        reverse(s2.begin(),s2.end());
        int n=s.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(s,s2,n,n,dp);        
    }
};