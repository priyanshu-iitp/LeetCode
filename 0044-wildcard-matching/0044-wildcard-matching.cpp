class Solution {
public:
    // bool solve(string&p, string&s,int i,int j,vector<vector<int>>&dp)
    // {   

    //     if(i==0 && j==0) return true;
    //     if(i==0 && j>=1) return false;
    //     if(j==0 && i>=1)
    //     {
    //         for(int k=0;k<i;k++)
    //         if(p[k]!='*') return false;

    //         return true;
    //     }


    //     if(dp[i][j]!=-1) return dp[i][j];


    //     if(p[i-1]==s[j-1] || p[i-1]=='?') return dp[i][j]=solve(p,s,i-1,j-1,dp);
    //     if(p[i-1]=='*') return dp[i][j]=solve(p,s,i-1,j,dp) || solve(p,s,i,j-1,dp);

    //     return dp[i][j]=false;
    // }
    bool isMatch(string s, string p) {

        int m=s.size();
        int n=p.size();
        vector<bool>prev(m+1,true);
        vector<bool>temp(m+1,true);

        prev[0]=true;
        for(int j=1;j<=m;j++) prev[j]=false;

       

        for(int i=1;i<=n;i++)
        {
            for(int k=1;k<=i;k++)
            {
                if(p[k-1]!='*') temp[0]=false;
            }

            for(int j=1;j<=m;j++)
            {
                if(p[i-1]==s[j-1] || p[i-1]=='?') temp[j]=prev[j-1];
                else if(p[i-1]=='*') temp[j]=prev[j] || temp[j-1];
                else temp[j]=false;
            }
            prev=temp;
        }
        return prev[m];
        
    }
};