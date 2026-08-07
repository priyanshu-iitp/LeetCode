class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {

        int n=t1.size();
        int m=t2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=m;i++)dp[0][i]=0;
        for(int i=0;i<=n;i++)dp[i][0]=0;    
        
        for(int i1=1;i1<=n;i1++)
        {
            for(int i2=1;i2<=m;i2++)
            {
                //match
                if(t1[i1-1]==t2[i2-1]) dp[i1][i2]=1+dp[i1-1][i2-1];
                //not match
                else dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
        return dp[n][m];
        
    }
};